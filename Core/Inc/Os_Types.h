/*
 * Os_Types.h
 *
 *  Created on: 24. 7. 2023
 *      Author: vojte
 */

#ifndef SRC_USERCODE_OS_OS_TYPES_H_
#define SRC_USERCODE_OS_OS_TYPES_H_

#include "GlobalDefines.h"

typedef enum
{
	idle = 0,
	running,
	suspend,
	terminated,
}Os_TaskStatus;

typedef struct
{
	uint32_t event;
	uint8_t timeMs;
	uint8_t priority;
	Os_TaskStatus* taskStatus;
	FunctionPointer ptrToTask;
}Os_EventStruct;




#endif /* SRC_USERCODE_OS_OS_TYPES_H_ */
