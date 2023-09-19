/*
 * Os.c
 *
 *  Created on: 23. 7. 2023
 *      Author: vojte
 */

#include <ButtonHandler.h>
#include <IoHwAb.h>
#include "Os.h"
#include "LedHandler.h"
#include "stm32f030x6.h"
#include "Os_Types.h"
#include "string.h"


#define Time_10MS  10u
#define Time_20MS  20u
#define NO_TIME		0xFFu

#define EVENT_10MS 	 		0x01
#define EVENT_20MS  		0x02
#define EVENT_INIT 			0x04
#define EVENT_RESERVED2 	0x08
#define EVENT_RESERVED3 	0x16

#define NUMBER_OF_TASKS		2u

#define ALL_EVENT_MASK (EVENT_10MS | EVENT_10MS | EVENT_INIT | EVENT_RESERVED2 | EVENT_RESERVED3)

/* need to be consist with OsEventTasks */
static Os_TaskStatus taskStatus[NUMBER_OF_TASKS] = {idle};

static uint32_t evMask = 0;

static uint32_t globalTime = 0;

void Os_Scheduler();

static void Os_InitTask();

static void Os_10msTask();

static void Os_ClearEvent(uint32_t event);

static void Os_CalculateEvent();

static void Os_SetEvent(uint32_t event);

/* need to be consist with taskStatus */
static const Os_EventStruct OsEventTasks[NUMBER_OF_TASKS] =
{
		{ EVENT_10MS, Time_10MS, 10, &taskStatus[0], Os_10msTask },
		{ EVENT_INIT, NO_TIME, 5, &taskStatus[1], Os_InitTask },
};

/* handling sys tick via interupt */
void SysTick_Handler()
{
	globalTime++;
	/* check time events */
	Os_CalculateEvent();
	/* interupt from sis timer every 1 ms, call scheduler */
	Os_Scheduler();
}

/* after task is procced of the current event, clear it */
static void Os_ClearEvent(uint32_t event)
{
	evMask ^= event;
}

/* set event */
static void Os_SetEvent(uint32_t event)
{
	evMask |= event;
}

uint32_t Os_GetGlobalTimeMs()
{
	return globalTime;
}

/* Handling Tasks */
void Os_Scheduler()
{
	/* 10 ms task */
	for (uint8_t index = 0; index < (sizeof(OsEventTasks) / sizeof(Os_EventStruct)); index++)
	{
		/* event present, start the task */
		if ((evMask & OsEventTasks[index].event) != 0)
		{
			/* check task status, if it is already running */
			if(*(OsEventTasks[index].taskStatus) == idle)
			{
				*(OsEventTasks[index].taskStatus) = running;
				OsEventTasks[index].ptrToTask();
				*(OsEventTasks[index].taskStatus) = idle;
				Os_ClearEvent(OsEventTasks[index].event);
			}
		}
	}
}

/* Os init, inicializate NVIC interupt for SysTick */
void Os_Init()
{
	memset(taskStatus, idle, sizeof(taskStatus));
	__NVIC_EnableIRQ(SysTick_IRQn);

	Os_SetEvent(EVENT_INIT);
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
	IoHwAb_Init();
	LedHandler_Init();
}

/* Calculate Timme Event */
static void Os_CalculateEvent()
{
	for (uint8_t index = 0; index < (sizeof(OsEventTasks) / sizeof(Os_EventStruct)); index++)
	{
		/* check if the event is cylic */
		if (OsEventTasks[index].timeMs != NO_TIME)
		{
			if ((globalTime % OsEventTasks[index].timeMs) == 0)
			{
				Os_SetEvent(OsEventTasks[index].event);
			}
		}
	}
}
