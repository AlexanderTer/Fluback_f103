#include "stm32f1xx.h"
#include <stdint.h>
#include "timer.h"

/**
 * Инициализация таймера 1 в режиме ЧИМ
 */
void timer_init(void)
{

	// Включаем тактирование таймера TIM1.
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	// Включение автоперезагрузки.
	TIM1->CR1 |= TIM_CR1_ARPE;

	// Предделитель счётчика 1
	TIM1->PSC = 0;

	// Врехний предел счёта
	TIM1->ARR = 65535;

	// Регистр сравнения канала 1 на половину периода
	TIM1->CCR1 = 30000;
	TIM1->CCR2 = 100;
	TIM1->CCR3 = 0x00;
	TIM1->CCR4 = 0x00;

	TIM1->CCMR1 = (TIM_CCMR1_OC1PE | TIM_CCMR1_OC1M |
	TIM_CCMR1_OC2PE | TIM_CCMR1_OC2M);

	TIM1->CCER = (TIM_CCER_CC1E | /*TIM_CCER_CC1P*|*/
	TIM_CCER_CC1NE | /*TIM_CCER_CC1NP*|*/
	TIM_CCER_CC2E | /*TIM_CCER_CC2P*|*/
	TIM_CCER_CC2NE /*|*TIM_CCER_CC2NP*/);

	TIM1->BDTR = (TIM_BDTR_MOE | ((4 << 5) | 10));
	TIM1->CR1|=TIM_CR1_CEN;

}
