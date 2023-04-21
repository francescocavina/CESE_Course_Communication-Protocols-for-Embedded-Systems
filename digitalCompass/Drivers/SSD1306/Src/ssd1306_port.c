/**
 * ssd1306_port.c
 *
 * Created on: Apr 13, 2023
 *      Author: Francesco Cavina <francescocavina@outlook.com>
 *
 *
 * The SSD1306 DISPLAY uses I2C for communication.
 * This driver has different functions for drawing lines, circles and write text.
 * Default pinout depends on platform used.
 *
 * SSD1306   |STM32F429ZI     |DESCRIPTION

 * VCC       |3.3V            |Power supply voltage
 * GND       |GND             |Ground
 * SCL       |PB6 (I2C1_SCL)  |Serial clock line
 * SDA       |PB8 (I2C1_SDA)  |Serial data line
 *
 *
 * Note: In order to use this driver with other platform, only modify the
 *       functions defined on PORT files.
 *       Look for "MODIFY BEGIN #" and "MODIFY END #" labels.
 *
 *
 * The whole driver is composed of the following files:
 *
 *       - ssd1306.c		(DO NOT MODIFY!)
 *       - ssd1306.h		(DO NOT MODIFY!)
 *       - ssd1306_port.c	(modifiable)
 *       - ssd1306_port.h	(modifiable)
 */


/* Includes ------------------------------------------------------------------*/
#include "ssd1306_port.h"


/* Private defines -----------------------------------------------------------*/
#define I2C_ISDEVICEREADY_TIMEOUT	1000
#define I2C_TIMEOUT 				10


/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c_display;


/* Private function prototypes -----------------------------------------------*/
/**
  * @brief  This function is executed in case of error occurrence
  * @param  None
  * @retval None
  */
static void Error_Handler(void);

/**
  * @brief  I2C1 Initialization Function
  * @param  None
  * @retval None
  */
static void MX_I2C1_Init(void);


/* Private function definitions ----------------------------------------------*/
static void MX_I2C1_Init(void) {

	/* Initialize I2C peripheral */
	/* MODIFY BEGIN 1 */
	hi2c_display.Instance = I2C1;
	hi2c_display.Init.ClockSpeed = 400000;
	hi2c_display.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c_display.Init.OwnAddress1 = 0;
	hi2c_display.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c_display.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c_display.Init.OwnAddress2 = 0;
	hi2c_display.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c_display.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	/* MODIFY END 1 */

	/**
	 * To change GPIO for I2C peripheral, go to:
	 *	- File: 	stm32fxxx_hal_msp.c
	 * 	- Function: void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
	 */

	if (
		/* MODIFY BEGIN 2 */
		HAL_I2C_Init(&hi2c_display)
		/* MODIFY END 2 */
		!= HAL_OK) {
		Error_Handler();
	}
}

static void Error_Handler(void) {

  while (1) {}
}


/* Public function definitions -----------------------------------------------*/
uint8_t ssd1306_I2C_Init(uint8_t address) {

	/* Initialize I2C peripheral */
	/* MODIFY BEGIN 3 */
	MX_I2C1_Init();
	/* MODIFY END 3 */

	/* Check if parameter (display address) is not NULL */
	if(address != NULL) {

		/* Check if display is connected to I2C */
		if (
			/* MODIFY BEGIN 4 */
			HAL_I2C_IsDeviceReady(&hi2c_display, address, 1, I2C_ISDEVICEREADY_TIMEOUT)
			/* MODIFY END 4 */
			!= HAL_OK) {
			return 0;	// Display not connected
		} else {
			return 1;	// Display connected
		}
	} else {
		return 0;
	}
}

void ssd1306_I2C_WriteMulti(uint8_t address, uint8_t reg, uint8_t* data, uint16_t count) {

	/* Initialize array to write: 1 byte for register + bytes for data */
	uint8_t dataToSend[256];
	uint8_t i;

	/* Check if first parameter (display address) is not NULL */
	if(address != NULL) {

		dataToSend[0] = reg;

		for(i = 0; i < count; i++) {
			dataToSend[i+1] = data[i];
		}

		/* MODIFY BEGIN 5 */
		HAL_I2C_Master_Transmit(&hi2c_display, address, dataToSend, count+1, I2C_TIMEOUT);
		/* MODIFY END 5 */
	}
}

void ssd1306_I2C_Write(uint8_t address, uint8_t reg, uint8_t data) {

	/* Initialize array to write: 1 byte for register + 1 byte for data */
	uint8_t dataToSend[2];

	/* Check if first parameter (display address) is not NULL */
	if(address != NULL) {

		dataToSend[0] = reg;
		dataToSend[1] = data;

		/* MODIFY BEGIN 6 */
		HAL_I2C_Master_Transmit(&hi2c_display, address, dataToSend, sizeof(dataToSend), I2C_TIMEOUT);
		/* MODIFY END 6 */
	}
}
