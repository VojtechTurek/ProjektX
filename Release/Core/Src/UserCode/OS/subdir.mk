################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/UserCode/OS/Os.c 

OBJS += \
./Core/Src/UserCode/OS/Os.o 

C_DEPS += \
./Core/Src/UserCode/OS/Os.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/UserCode/OS/%.o Core/Src/UserCode/OS/%.su Core/Src/UserCode/OS/%.cyclo: ../Core/Src/UserCode/OS/%.c Core/Src/UserCode/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32F030x6 -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-UserCode-2f-OS

clean-Core-2f-Src-2f-UserCode-2f-OS:
	-$(RM) ./Core/Src/UserCode/OS/Os.cyclo ./Core/Src/UserCode/OS/Os.d ./Core/Src/UserCode/OS/Os.o ./Core/Src/UserCode/OS/Os.su

.PHONY: clean-Core-2f-Src-2f-UserCode-2f-OS

