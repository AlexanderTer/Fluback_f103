################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c 

OBJS += \
./Src/main.o 

C_DEPS += \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Git Local/Flyback_f103/CMSIS/Core/Include" -I"C:/Git Local/Flyback_f103/CMSIS/Device/ST/STM32F1xx" -I"C:/Git Local/Flyback_f103/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Git Local/Flyback_f103/Inc/periph" -I"C:/Git Local/Flyback_f103/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.d ./Src/main.o ./Src/main.su

.PHONY: clean-Src

