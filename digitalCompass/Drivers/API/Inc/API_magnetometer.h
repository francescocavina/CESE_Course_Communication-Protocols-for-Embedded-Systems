/*
 * API_magnetometer.h
 *
 *  Created on: Apr 17, 2023
 *      Author: Francesco Cavina <francescocavina@outlook.com>
 */


#ifndef API_MAGNETOMETER_INC_API_MAGNETOMETER_H_
#define API_MAGNETOMETER_INC_API_MAGNETOMETER_H_


/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "stm32f4xx_nucleo_144.h"


/* Public typedefs -----------------------------------------------------------*/
/**
 * @brief Contains important data from the sensor readings to update the MEF on
 * @brief @ref API_system.c and print the display
 * @field lastValueX:  last value of magnetic field in the X axis
 * @field lastValueY:  last value of magnetic field in the Y axis
 * @field lastValueZ:  last value of magnetic field in the > axis
 * @field arrowAngle:  arrow angle for the compass
 * @field UPDATE_FLAG: true: update display with new values; false: not update display
 */
typedef struct {
	int16_t lastValueX;
	int16_t lastValueY;
	int16_t lastValueZ;
	double arrowAngle;
	bool UPDATE_FLAG;
} magnetometer_t;


/* Public function prototypes ------------------------------------------------*/
/**
 * @brief  Initializes the magnetometer sensor
 * @Note   As there is no sensor connected, this function is empty
 * @param  None
 * @retval None
 */
void magnetometerInit(void);

/**
 * @brief  Generates random values to simulate the reading of the sensor
 * @param  None
 * @retval magnetometer_t structure. Their fields can be seen above
 */
void readMagnetometer(magnetometer_t *sensor);

/**
 * @brief  Calculates the arrow angle for the compass based on the sensor readings
 * @param  None
 * @retval magnetometer_t structure. Their fields can be seen above
 */
void calculateArrowAngle(magnetometer_t *sensor);


#endif /* API_MAGNETOMETER_INC_API_MAGNETOMETER_H_ */
