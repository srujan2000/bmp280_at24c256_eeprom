################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../i2c_library/i2c.c 

OBJS += \
./i2c_library/i2c.o 

C_DEPS += \
./i2c_library/i2c.d 


# Each subdirectory must supply rules for building sources it contributes
i2c_library/%.o i2c_library/%.su: ../i2c_library/%.c i2c_library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VETx -c -I../Inc -I"C:/stmcube32/bmp280_at24c256/i2c_library" -I"C:/stmcube32/bmp280_at24c256/uart_library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-i2c_library

clean-i2c_library:
	-$(RM) ./i2c_library/i2c.d ./i2c_library/i2c.o ./i2c_library/i2c.su

.PHONY: clean-i2c_library

