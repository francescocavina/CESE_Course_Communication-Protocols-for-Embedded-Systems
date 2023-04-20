/*
 * API_system.h
 *
 *  Created on: Apr 17, 2023
 *      Author: Francesco Cavina <francescocavina@outlook.com>
 */

#ifndef API_INC_API_SYSTEM_H_
#define API_INC_API_SYSTEM_H_


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_nucleo_144.h"
#include "API_displayOLED.h"
#include "API_magnetometer.h"
#include "API_delay.h"
#include "API_debounce.h"


/* Public function prototypes ------------------------------------------------*/
/**
 * @brief  Initializes a MEF, display OLED, magnetometer, delay, etc.
 * @brief  The systems is a digital compass
 * @brief  MEF States: 	1)Read Sensor 1;
 * 						2)Write Raw Data from Sensor
 * 						3)Read Sensor 2;
 * 						4)Draw a Compass
 * @param  None
 * @retval None
 */
void systemInit(void);

/**
 * @brief  Updates the state of the MEF and reads on-board push-button.
 * @param  None
 * @retval None
 */
void systemUpdate(void);


#endif /* API_INC_API_SYSTEM_H_ */
