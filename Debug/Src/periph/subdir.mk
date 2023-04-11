################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/periph/gpio.c \
../Src/periph/rcc.c \
../Src/periph/timer.c 

OBJS += \
./Src/periph/gpio.o \
./Src/periph/rcc.o \
./Src/periph/timer.o 

C_DEPS += \
./Src/periph/gpio.d \
./Src/periph/rcc.d \
./Src/periph/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Src/periph/%.o Src/periph/%.su: ../Src/periph/%.c Src/periph/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Git Local/Flyback_f103/CMSIS/Core/Include" -I"C:/Git Local/Flyback_f103/CMSIS/Device/ST/STM32F1xx" -I"C:/Git Local/Flyback_f103/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Git Local/Flyback_f103/Inc/periph" -I"C:/Git Local/Flyback_f103/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-periph

clean-Src-2f-periph:
	-$(RM) ./Src/periph/gpio.d ./Src/periph/gpio.o ./Src/periph/gpio.su ./Src/periph/rcc.d ./Src/periph/rcc.o ./Src/periph/rcc.su ./Src/periph/timer.d ./Src/periph/timer.o ./Src/periph/timer.su

.PHONY: clean-Src-2f-periph

