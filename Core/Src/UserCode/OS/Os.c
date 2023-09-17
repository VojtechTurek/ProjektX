/*
 * Os.c
 *
 *  Created on: 23. 7. 2023
 *      Author: vojte
 */

#include "Os.h"
#include "LedHandler.h"
#include "IoHwAb_Main.h"
#include "ButtonHandler_Main.h"
#include "stm32f030x6.h"
#include "Os_Types.h"


#define Time_10MS  10u
#define Time_20MS  20u

#define EVENT_10MS 	 		0x01
#define EVENT_20MS  		0x02
#define EVENT_RESERVED1 	0x04
#define EVENT_RESERVED2 	0x08
#define EVENT_RESERVED3 	0x16


#define ALL_EVENT_MASK (EVENT_10MS | EVENT_10MS | EVENT_RESERVED1 | EVENT_RESERVED2 | EVENT_RESERVED3)

/*
static const Os_EventStruct OsEvents[] =
{
		{EVENT_10MS, Time_10MS, 10};
		{EVENT_20MS, Time_20MS, 5};
};
*/

uint32_t evMask = 0;

uint32_t globalTime = 0;

void Os_Scheduler();

static void Os_InitTask();

static void Os_10msTask();

static void Os_ClearEvent(uint32_t mask);

static void Os_CalculateEvent();

static void Os_SetEvent();

/* handling sys tick via interupt */
void SysTick_Handler()
{
	globalTime++;
	/* interupt from sis timer every 1 ms, call scheduler */
	Os_Scheduler();
}

/* after task is procced of the current event, clear it */
static void Os_ClearEvent(uint32_t mask)
{
	evMask ^= mask;
}

uint32_t Os_GetGlobalTimeMs()
{
	return globalTime;
}

/* Handling Tasks */
void Os_Scheduler()
{
	if ((globalTime % Time_10MS) == 0)
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

/* Os init, inicializate NVIC interupt for SysTick */
void Os_Init()
{
	__NVIC_EnableIRQ(SysTick_IRQn);
}

/* 10ms task */
static void Os_10msTask()
{
	IoHwAb_MainFunction();
	ButtonHandler_MainFunction();
	LedHandler_MainFunction();
}

/* Init task */
static void Os_InitTask()
{
	LedHandler_Init();
}

/* Calculate Event */
static void Os_CalculateEvent()
{
	/* check if there is some event occur */
	if (evMask & ALL_EVENT_MASK != 0)
	{
		Os_SetEvent();
	}
}

/* set event */
static void Os_SetEvent()
{
//	for (uint8_t index = 0; index < sizeof(OsEvents / Os_EventStruct); index++)
//	{
//		if (globalTime %)
//	}
}
