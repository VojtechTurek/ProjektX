################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/OS/Os.c 

OBJS += \
./Core/Src/OS/Os.o 

C_DEPS += \
./Core/Src/OS/Os.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/OS/%.o Core/Src/OS/%.su Core/Src/OS/%.cyclo: ../Core/Src/OS/%.c Core/Src/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x6 -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-OS

clean-Core-2f-Src-2f-OS:
	-$(RM) ./Core/Src/OS/Os.cyclo ./Core/Src/OS/Os.d ./Core/Src/OS/Os.o ./Core/Src/OS/Os.su

.PHONY: clean-Core-2f-Src-2f-OS

