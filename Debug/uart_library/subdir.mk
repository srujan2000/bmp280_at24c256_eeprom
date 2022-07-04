################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../uart_library/uart.c 

OBJS += \
./uart_library/uart.o 

C_DEPS += \
./uart_library/uart.d 


# Each subdirectory must supply rules for building sources it contributes
uart_library/%.o uart_library/%.su: ../uart_library/%.c uart_library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VETx -c -I../Inc -I"C:/stmcube32/bmp280_at24c256/i2c_library" -I"C:/stmcube32/bmp280_at24c256/uart_library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-uart_library

clean-uart_library:
	-$(RM) ./uart_library/uart.d ./uart_library/uart.o ./uart_library/uart.su

.PHONY: clean-uart_library

