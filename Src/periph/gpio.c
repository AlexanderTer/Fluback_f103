#include <stm32f1xx.h>
#include "gpio.h"




void gpio_init(void)
{
	// Включаем такирование портов.
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

	// Настройка PA8 - ЧИМ -----------------------------------------
	// 50 MHZ, Режим порта -  альтернативная функция - PushPull
	GPIOA->CRH |= GPIO_CRH_MODE8 | GPIO_CRH_CNF8_1;
	GPIOA->CRH &= ~(GPIO_CRH_CNF8_0);

	// Настройка PA1 - SYNC ----------------------------------------
	// 50 MHZ, Режим порта -  альтернативная функция - PushPull
	GPIOA->CRL |= GPIO_CRL_MODE1 | GPIO_CRL_CNF1_1;
	GPIOA->CRL &= ~(GPIO_CRL_CNF1_0);

	// Настройка PB12 - пин дебага -----------------------------------
	// 50 MHZ, Режим порта -  альтернативная функция - PushPull
	GPIOB->CRH |= GPIO_CRH_MODE12;
	GPIOB->CRH &= ~(( GPIO_CRH_CNF12_0)| GPIO_CRH_CNF12_1);

	// Аналоговые входы ---------------------------------------------
	GPIOA->CRL &= ~(GPIO_CRL_MODE3 | GPIO_CRL_MODE4 | GPIO_CRL_MODE5 | GPIO_CRL_MODE6);
	GPIOA->CRL &= ~(GPIO_CRL_CNF3 | GPIO_CRL_CNF4 | GPIO_CRL_CNF5 | GPIO_CRL_CNF6);
	//PA3 - Uout ADCI_N3
	//PA4 - Iout ADCI_N4
	//PA5 - TL   ADCI_N5
	//PA6 - не опеределено ADCI_N6

}
