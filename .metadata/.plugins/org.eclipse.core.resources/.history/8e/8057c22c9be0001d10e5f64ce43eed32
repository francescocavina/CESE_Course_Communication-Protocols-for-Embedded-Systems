/*
 * API_debounce.h
 *
 *  Created on: Mar 27, 2023
 *      Author: Francesco Cavina <francescocavina@outlook.com>
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_


/* Includes -----------------------------------------------------------------*/
#include <stdbool.h>
#include "API_delay.h"
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */

/* Public typedefs ----------------------------------------------------------*/
typedef bool bool_t;


/* Public function prototypes -----------------------------------------------*/
bool_t readKey(); 			// This public function returns true when key is pressed
void debounceFSM_init();	// This public function initializes the de-bouncing functionality
void debounceFSM_update(); 	// This public function must be continually called to implement the de-bouncing functionality


#endif /* API_INC_API_DEBOUNCE_H_ */
