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

/*
 * \brief Обработчик прерывания АЦП1
 */
void ADC1_2_IRQHandler(void)
{

	// Сброс флага прерывания.
	ADC1->SR &= ~ADC_SR_JEOC;
	adc_data_handler();
}
