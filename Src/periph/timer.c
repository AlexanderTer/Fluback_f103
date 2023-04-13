#include "stm32f1xx.h"
#include "timer.h"

extern uint32_t frec;
/**
 * Инициализация таймера 1 в режиме ЧИМ
 */
void timer_init(void)
{

	// ------------------------------------- Инициализация таймера 1
	// Включаем тактирование таймера TIM1.
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	// Включение автоперезагрузки.
	TIM1->CR1 |= TIM_CR1_ARPE;

	// Предделитель счётчика 1
	TIM1->PSC = 0;

	// Врехний предел счёта
	TIM1->ARR = 0;

	// Регистр сравнения канала 1 на половину периода
	TIM1->CCR1 = 17;

	// Исходное значение не нулевое, обнуляем.
	TIM1->CCMR1 = 0;

	// Включение переноса данных в регистр сравннеия из регистра предварительной загрузки.
	TIM1->CCMR1 |= TIM_CCMR1_OC1PE;

	//PWM mode 1 - 1 пока не достигли регистра сравнения, 0 - после достижения.
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;

	// Подключения прямого канала к регистру сравнения 1
	TIM1->CCER = 0;
	TIM1->CCER |= TIM_CCER_CC1E;

	// Главное подключение выхода
	TIM1->BDTR = 0;
	TIM1->BDTR |= TIM_BDTR_MOE;

	TIM1->CR1 |= TIM_CR1_CEN;

	// ---------------------- Инициализация таймера 2 -----------------------

	// Включаем тактирование таймера TIM2.
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	// Включение автоперезагрузки.
//	TIM2->CR1 |= TIM_CR1_ARPE;

	// Врехний предел счёта
	TIM2->ARR = 720-1; // F_CPU / 100 KHZ = 720

	// Регистр сравнения канала 2
	TIM2->CCR2 = 50;

	// Включение переноса данных в регистр сравннеия из регистра предварительной загрузки.
//	TIM2->CCMR1 = 0;
	//TIM2->CCMR1 |= TIM_CCMR1_OC2PE;

	//PWM mode 1 - 1 пока не достигли регистра сравнения, 0 - после достижения.
	TIM2->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1;

	// Подключения прямого канала к регистру сравнения 1
	TIM2->CCER = 0;
	TIM2->CCER |= TIM_CCER_CC2E;

	// Включение счёта
	TIM2->CR1 |= TIM_CR1_CEN;
}

/**
 * \brief Функция установки регистра частоты с сохранением длительности импульса
 */
void setFrecuency(uint32_t frecuency)
{
	/*
	 * 4 MHZ - ARR = 18
	 * 0.1 kHz - ARR = 720
	 * CCR1 = 17 постоянно
	 */

	TIM1->ARR = frecuency;

}
/**
 *\brief Функция включения ЧИМ.
 */
void PFM_Enable (void)
{
	TIM1->CCER |= TIM_CCER_CC1E;
}

/**
 *\brief Функция выключения ЧИМ.
 */
void PFM_Disable (void)
{
	TIM1->CCER &= ~TIM_CCER_CC1E;
}

/**
 *\brief Функция выключения сигнала синхронизации.
 */
void syncDisable(void)
{
	TIM2->CCER &= ~TIM_CCER_CC2E;

}

/**
 *\brief Функция включения сигнала синхронизации.
 */
void syncEnable(void)
{
	TIM2->CCER |= TIM_CCER_CC2E;

}
