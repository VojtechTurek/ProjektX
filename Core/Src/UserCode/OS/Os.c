/*
 * Os.c
 *
 *  Created on: 23. 7. 2023
 *      Author: vojte
 */

#include "Os.h"
#include "LedHandler.h"
#include "stm32f030x6.h"


#define N10MS  10u
#define N20MS  20u

#define EVENT_10MS  0x01

uint32_t evMask = 0;

uint32_t globalTime = 0;

void Os_scheduler();

static void Os_10msTask();

static void Os_ClearEvent(uint32_t mask);

void Os_Init()
{
	__NVIC_EnableIRQ(SysTick_IRQn);
}

uint32_t Os_GetMs()
{
	return 0;
}

void Os_scheduler()
{
	if ((globalTime % N10MS) == 0)
	{
		evMask |= EVENT_10MS;
	}
	/* 10 ms task */
	if ((evMask & EVENT_10MS) == 1)
	{
		Os_10msTask();

		Os_ClearEvent(EVENT_10MS);
	}
}

static void Os_10msTask()
{
	LedHandler_MainFunction();
}

void SysTick_Handler()
{
	globalTime++;
	/* interupt from sis timer every 1 ms, call scheduler */
	Os_scheduler();
}

static void Os_ClearEvent(uint32_t mask)
{
	evMask ^= mask;
}
