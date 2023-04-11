#include <stm32f1xx.h>
#include <stdint.h>
#include "gpio.h"

void gpio_init(void)
{
	// Включаем тактовый сигнал порта GPIOA.
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	// Режим порта - reserved, альтернативная функция - PushPull
	GPIOA->CRH |=  GPIO_CRH_MODE8  | GPIO_CRH_CNF8_1;
	GPIOA->CRH &= ~(GPIO_CRH_CNF8_0);

	// Очистить регистр данных
	GPIOA->ODR = 0x0000;
}
