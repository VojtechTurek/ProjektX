/*
 * LedHandler.h
 *
 *  Created on: Jul 20, 2023
 *      Author: vojte
 */

#ifndef SRC_USERCODE_LEDHANDLER_LEDHANDLER_H_
#define SRC_USERCODE_LEDHANDLER_LEDHANDLER_H_

#include "stdint.h"
#include "main.h"
#include "stm32f0xx_ll_gpio.h"

void LedHandler_MainFunction();

void LedHandler_TurnOnLED();

void LedHandler_TurnOffLED();

void LedHandler_Init();

#endif /* SRC_USERCODE_LEDHANDLER_LEDHANDLER_H_ */
