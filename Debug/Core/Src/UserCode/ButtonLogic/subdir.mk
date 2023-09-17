################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/UserCode/ButtonLogic/ButtonHandler_Main.c 

OBJS += \
./Core/Src/UserCode/ButtonLogic/ButtonHandler_Main.o 

C_DEPS += \
./Core/Src/UserCode/ButtonLogic/ButtonHandler_Main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/UserCode/ButtonLogic/%.o Core/Src/UserCode/ButtonLogic/%.su Core/Src/UserCode/ButtonLogic/%.cyclo: ../Core/Src/UserCode/ButtonLogic/%.c Core/Src/UserCode/ButtonLogic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32F030x6 -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-UserCode-2f-ButtonLogic

clean-Core-2f-Src-2f-UserCode-2f-ButtonLogic:
	-$(RM) ./Core/Src/UserCode/ButtonLogic/ButtonHandler_Main.cyclo ./Core/Src/UserCode/ButtonLogic/ButtonHandler_Main.d ./Core/Src/UserCode/ButtonLogic/ButtonHandler_Main.o ./Core/Src/UserCode/ButtonLogic/ButtonHandler_Main.su

.PHONY: clean-Core-2f-Src-2f-UserCode-2f-ButtonLogic

