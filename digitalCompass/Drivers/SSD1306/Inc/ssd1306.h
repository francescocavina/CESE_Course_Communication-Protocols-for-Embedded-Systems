/**
 * ssd1306.h
 *
 * Created on: Apr 13, 2023
 *      Author: Francesco Cavina <francescocavina@outlook.com>
 *
 * Original author of certain parts:  	Tilen Majerle <tilen@majerle.eu>
 * Modification for STM32f10x: 			Alexander Lutsai <s.lyra@ya.ru>
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
 *       Look for "MODIFIABLE BEGIN #" and "MODIFIABLE END #" labels.
 *
 *
 * The whole driver is composed of the following files:
 *
 *       - ssd1306.c		(DO NOT MODIFY!)
 *       - ssd1306.h		(DO NOT MODIFY!)
 *       - ssd1306_port.c	(modifiable)
 *       - ssd1306_port.h	(modifiable)
 */


#ifndef SSD1306_H
#define SSD1306_H 100


/* Includes ------------------------------------------------------------------*/
#include "ssd1306_port.h"
#include "fonts.h"
#include "stdlib.h"
#include "string.h"


/* Public defines ------------------------------------------------------------*/
/* SSD1306 settings */
/* I2C address */
#define SSD1306_I2C_ADDR         0x78	// 1b01111000 (last bit set to 0 for writing)

/* SSD1306 Display width in pixels */
#define SSD1306_WIDTH            128

/* SSD1306 Display height in pixels */
#define SSD1306_HEIGHT           64


/* Public typedefs -----------------------------------------------------------*/
/**
 * @brief  SSD1306 color enumeration
 */
typedef enum {
	SSD1306_COLOR_BLACK = 0x00,
	SSD1306_COLOR_BLUE = 0x01
} SSD1306_COLOR_t;


/* Public function prototypes ------------------------------------------------*/
/**
 * @brief  Initializes SSD1306 Display
 * @param  None
 * @retval Initialization status:
 *           - 0: Display was not detected
 *           - 1: Display initialized OK and ready to use
 */
uint8_t SSD1306_Init(void);

/**
 * @brief  Updates buffer from internal RAM to display
 * @note   This function must be called each time you do some changes to the display, to update buffer from RAM to display
 * @param  None
 * @retval None
 */
void SSD1306_UpdateScreen(void);

/**
 * @brief  Fills entire display with desired color
 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated display screen
 * @param  Color: Color to be used for screen fill. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
 * @retval None
 */
void SSD1306_Fill(SSD1306_COLOR_t Color);

/**
 * @brief  Draws pixel at desired location
 * @note   @ref SSD1306_UpdateScreen() must called after that in order to see updated display screen
 * @param  x: X location. This parameter can be a value between 0 and SSD1306_WIDTH - 1
 * @param  y: Y location. This parameter can be a value between 0 and SSD1306_HEIGHT - 1
 * @param  color: Color to be used for screen fill. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
 * @retval None
 */
void SSD1306_DrawPixel(uint16_t x, uint16_t y, SSD1306_COLOR_t color);

/**
 * @brief  Sets cursor pointer to desired location
 * @param  x: X location. This parameter can be a value between 0 and SSD1306_WIDTH - 1
 * @param  y: Y location. This parameter can be a value between 0 and SSD1306_HEIGHT - 1
 * @retval None
 */
void SSD1306_GotoXY(uint16_t x, uint16_t y);

/**
 * @brief  Puts character to internal RAM
 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated display screen
 * @param  ch: Character to be written
 * @param  *Font: Pointer to @ref FontDef_t structure with used font
 * @param  color: Color used for drawing. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
 * @retval Character written
 */
uint8_t SSD1306_Putc(uint8_t ch, FontDef_t* Font, SSD1306_COLOR_t color);

/**
 * @brief  Puts string to internal RAM
 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated display screen
 * @param  *str: String to be written
 * @param  *Font: Pointer to @ref FontDef_t structure with used font
 * @param  color: Color used for drawing. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
 * @retval Zero on success or character value when function failed
 */
uint8_t SSD1306_Puts(uint8_t* str, FontDef_t* Font, SSD1306_COLOR_t color);

/**
 * @brief  Draws line on display
 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated display screen
 * @param  x0: Line X start point. Valid input is 0 to SSD1306_WIDTH - 1
 * @param  y0: Line Y start point. Valid input is 0 to SSD1306_HEIGHT - 1
 * @param  x1: Line X end point. Valid input is 0 to SSD1306_WIDTH - 1
 * @param  y1: Line Y end point. Valid input is 0 to SSD1306_HEIGHT - 1
 * @param  c: Color to be used. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
 * @retval None
 */
void SSD1306_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, SSD1306_COLOR_t c);

/**
 * @brief  Draws circle on display
 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated display screen
 * @param  x: X location for center of circle. Valid input is 0 to SSD1306_WIDTH - 1
 * @param  y: Y location for center of circle. Valid input is 0 to SSD1306_HEIGHT - 1
 * @param  r: Circle radius in units of pixels
 * @param  c: Color to be used. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
 * @retval None
 */
void SSD1306_DrawCircle(int16_t x0, int16_t y0, int16_t r, SSD1306_COLOR_t c);

/**
 *  @brief 	Clears the display
 *  @param 	None
 *  @retval None
 */
void SSD1306_Clear (void);


#endif
