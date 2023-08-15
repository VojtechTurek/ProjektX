/*
 * Os.h
 *
 *  Created on: 23. 7. 2023
 *      Author: vojte
 */

#ifndef SRC_OS_OS_H_
#define SRC_OS_OS_H_

#include "stdint.h"

void Os_Init();

uint32_t Os_GetMs();

void Os_Scheduler();

#endif /* SRC_OS_OS_H_ */
