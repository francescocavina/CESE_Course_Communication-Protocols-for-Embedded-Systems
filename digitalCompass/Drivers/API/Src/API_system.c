/*
 * API_system.c
 *
 *  Created on: Apr 17, 2023
 *      Author: Francesco Cavina <francescocavina@outlook.com>
 */


/* Includes ------------------------------------------------------------------*/
#include "API_system.h"


/* Private defines -----------------------------------------------------------*/
#define SYSTEM_TIME	400


/* Private typedef -----------------------------------------------------------*/
typedef enum{
	COMPASS_READING_SENSOR,
	COMPASS_WRITING_DISPLAY,
	RAWDATA_READING_SENSOR,
	RAWDATA_WRITING_DISPLAY
} systemState_t;


/* Private variables ---------------------------------------------------------*/
static delay_t system_delay;
static systemState_t SYSSTATE;
static magnetometer_t sensor;


/* Public functions definitions ----------------------------------------------*/
void systemInit(void) {

	/* Initialize system */
	SYSSTATE = COMPASS_READING_SENSOR;

	/* Initialize BSP PB for ON-BOARD PUSH-BUTTON */
	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);

	/* Initialize magnetometer sensor */
	magnetometerInit();
	sensor.lastValueX = 0;
	sensor.lastValueY = 0;
	sensor.lastValueZ = 0;
	sensor.arrowAngle = 0;
	sensor.UPDATE_FLAG = false;

	/* Initialize OLED display */
	displayInit();

	/* Initialize system delay */
	delayInit(&system_delay, SYSTEM_TIME);

	/* Initialize debounce feature for on-board push-button*/
	debounceFSM_init();
}

void systemUpdate(void) {

	debounceFSM_update();

	switch(SYSSTATE) {

		case COMPASS_READING_SENSOR:
			if(readKey()) {
				/* When push-button pressed, change system state */
				SYSSTATE = RAWDATA_READING_SENSOR;
			} else if(delayRead(&system_delay)) {
				/* When time is up, change system state */
				SYSSTATE = COMPASS_WRITING_DISPLAY;
			}
			readMagnetometer(&sensor);
			break;

		case COMPASS_WRITING_DISPLAY:
			if(readKey()) {
				/* When push-button pressed, change system state */
				SYSSTATE = RAWDATA_READING_SENSOR;
			} else if(delayRead(&system_delay)) {
				/* When time is up, change system state */
				SYSSTATE = COMPASS_READING_SENSOR;
			} else {
				if(sensor.UPDATE_FLAG == true) {
					/* New data available to be shown on the display */
					drawOuterCircle();
					calculateArrowAngle(&sensor);
					drawArrow(sensor.arrowAngle, SSD1306_COLOR_BLUE);
					sensor.UPDATE_FLAG = false;
				}
			}
			break;

		case RAWDATA_READING_SENSOR:
			if(readKey()) {
				/* When push-button pressed, change system state */
				SYSSTATE = COMPASS_READING_SENSOR;
			} else if(delayRead(&system_delay)) {
				/* When time is up, change system state */
				SYSSTATE = RAWDATA_WRITING_DISPLAY;
			}
			readMagnetometer(&sensor);
			break;

		case RAWDATA_WRITING_DISPLAY:
			if(readKey()) {
				/* When push-button pressed, change system state */
				SYSSTATE = COMPASS_READING_SENSOR;
			} else if(delayRead(&system_delay)) {
				/* When time is up, change system state */
				SYSSTATE = RAWDATA_READING_SENSOR;
			} else {
				if(sensor.UPDATE_FLAG == true) {
					/* New data available to be shown on the display */
					writeData(sensor.lastValueX, sensor.lastValueY, sensor.lastValueZ);
					sensor.UPDATE_FLAG = false;
				}
			}
			break;

		default:
			systemInit();
			break;
	}
}
