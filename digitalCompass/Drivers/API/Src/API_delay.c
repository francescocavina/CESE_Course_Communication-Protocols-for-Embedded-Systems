/*
 * API_delay.c
 *
 *  Created on: Mar 18, 2023
 *      Author: Francesco Cavina <francescocavina@outlook.com>
 */


#include "API_delay.h"
#include "stm32f4xx_hal.h"  		/* <- HAL include */


/* Implementation of non-blocking delay functions */

void delayInit(delay_t * delay, tick_t duration) {
	// This function configures a non-blocking delay by setting the delay duration
	// and setting the running flag to false.
	if(delay == NULL) 	// Checking the pointer
		return;

	delay->duration = duration;
	delay->running = false;
}

bool_t delayRead(delay_t * delay) {
	// This function starts a previously configured non-blocking delay in case that
	// it was not running. By this condition, the function returns false.
	// If the non-blocking delay was already running, but it didn't reach the configured
	// delay duration, this function returns false. Otherwise, this function returns true.
	if(delay == NULL)	// Checking the pointer
		return false;

	if(delay->running == false){
		delay->startTime = HAL_GetTick();
		delay->running = true;
	} else if(delay->running == true) {
		if(HAL_GetTick() - delay->startTime >= delay->duration) {
			delay->running = false;
			return true;
		}
	}
	return false;
}
void delayWrite(delay_t * delay, tick_t duration) {
	// This function allows to change the delay duration of a previously configured
	// non-blocking delay inside the super-loop.
	if(delay == NULL)	// Checking the pointer
			return;

	delay->duration = duration;
}
