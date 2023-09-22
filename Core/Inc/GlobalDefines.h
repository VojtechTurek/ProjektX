/*
 * GlobalDefines.h
 *
 *  Created on: Jul 20, 2023
 *      Author: vojte
 */

#ifndef SRC_USERCODE_GLOBALDEFINES_H_
#define SRC_USERCODE_GLOBALDEFINES_H_

#include "stm32f0xx_ll_gpio.h"

#define TRUE 1
#define FALSE 0

#define LED_BUILTIN LL_GPIO_PIN_4
#define BUTTON_ON_OFF LL_GPIO_PIN_1
#define EXTERNAL_LED LL_GPIO_PIN_0

#define GENERAL_ARRAY_ROWS(arr) (sizeof(arr)/sizeof(*arr)

typedef void (*FunctionPointer)();

#ifndef _BOOLEAN_
typedef __uint8_t boolean ;
#define _BOOLEAN_
#endif

#endif /* SRC_USERCODE_GLOBALDEFINES_H_ */
