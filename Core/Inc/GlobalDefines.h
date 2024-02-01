/*
 * GlobalDefines.h
 *
 *  Created on: Jul 20, 2023
 *      Author: vojte
 */

#ifndef SRC_USERCODE_GLOBALDEFINES_H_
#define SRC_USERCODE_GLOBALDEFINES_H_

#include "stm32f0xx_ll_gpio.h"

#define LED_BUILTIN LL_GPIO_PIN_4
#define BUTTON_ON_OFF LL_GPIO_PIN_1
#define EXTERNAL_LED LL_GPIO_PIN_8

#define GENERAL_ARRAY_ROWS(arr) (sizeof(arr)/sizeof(*arr))

typedef void (*FunctionPointer)();

#endif /* SRC_USERCODE_GLOBALDEFINES_H_ */
