/*
 * Os.c
 *
 *  Created on: 23. 7. 2023
 *      Author: vojte
 */
#include "stm32f0xx_hal.h"
#include "Os.h"


void Os_Init()
{

}

uint32_t Os_GetMs()
{
	return HAL_GetTick(); //LL_TIM_GetCounter();
}

