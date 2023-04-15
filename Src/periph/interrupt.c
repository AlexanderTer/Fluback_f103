#include <stm32f1xx.h>
#include "interrupt.h"
#include "gpio.h"
#include "control.h"

void interrupt_init(void)
{
	// Устанавливаем приоритет прерывания.
	NVIC_SetPriority(ADC1_2_IRQn, 1);

	// Разрешаем прерывание глобально.
	NVIC_EnableIRQ(ADC1_2_IRQn);

}


