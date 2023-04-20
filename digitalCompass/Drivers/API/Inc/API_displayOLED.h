/*
 * API_displayOLED.h
 *
 * Created on: Apr 14, 2023
 *      Author: Francesco Cavina <francescocavina@outlook.com>
 */

#ifndef API_DISPLAYOLED_INC_API_DISPLAYOLED_H_
#define API_DISPLAYOLED_INC_API_DISPLAYOLED_H_


/* Includes ------------------------------------------------------------------*/
#include "ssd1306.h"
#include "math.h"
#include <stdio.h>


/* Public defines ------------------------------------------------------------*/
#define PI	3.141592654


/* Public function prototypes ------------------------------------------------*/
/**
 * @brief  Initializes OLED Display
 * @param  None
 * @retval None
 */
void displayInit(void);

/**
 *  @brief 	Draws compass outer circle
 *  @param 	None
 *  @retval None
 */
void drawOuterCircle(void);

/**
 * @brief 	Draws an arrow to point the north
 * @param 	Angle in degrees (0° to 360°)
 * @param 	Arrow color	(black or blue)
 * @retval 	None
 */
void drawArrow(double angle, SSD1306_COLOR_t color);

/**
 * @brief  Writes raw data coming from sensor
 * @param  Values of magnetic field in x, y and z axes
 * @retval None
 */
void writeData(int16_t x, int16_t y, int16_t z);


#endif /* API_DISPLAYOLED_INC_API_DISPLAYOLED_H_ */
