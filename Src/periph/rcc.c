#include <stm32f1xx.h>
#include "rcc.h"

void rcc_init(void)
{
	//SystemInit();

	// Сбросить тактирование всех шин
	RCC->AHBENR = 0xFFFFFFFF;
	RCC->AHBENR = 0x00000000;

	RCC->APB1RSTR = 0xFFFFFFFF;
	RCC->APB1RSTR = 0x00000000;

	RCC->APB2RSTR = 0xFFFFFFFF;
	RCC->APB2RSTR = 0x00000000;

	// Обновление переменной с частотой тактирования
	//SystemCoreClockUpdate();

	// Включение питания RCC
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;

	// Запуск от HSE
	RCC->CR |= RCC_CR_HSEON;

	// Ожидание включеия внешнего генератора
	while (!(RCC->CR & RCC_CR_HSERDY))
		;

	RCC->CR |= RCC_CR_HSEBYP; // HSE crystal oscillator  bypassed

	// Выключение PLL
	RCC->CR &= ~RCC_CR_PLLON;
	while (RCC->CR & RCC_CR_PLLRDY)
		;
	// Сигнал HSE делится на 2 - 16 / 2 = 8 MHz
	RCC->CFGR |= RCC_CFGR_PLLXTPRE;

	// Настройка умножителя на 9 : 8 * 9 = 72 MHz
	RCC->CFGR |= RCC_CFGR_PLLMULL9;

	// Выбор HSE как источника для PLL
	RCC->CFGR |= RCC_CFGR_PLLSRC;

	// Делитель для шины APB1 на 2 -  частота 36 MHz
	RCC->CFGR |= RCC_CFGR_PPRE1_2;

	// Делитель АЦП на 6 - частота 12 MHZ
	RCC->CFGR |= RCC_CFGR_ADCPRE_1;

	// Настройка latancy на 2 для 72 МГц
	FLASH->ACR |= FLASH_ACR_LATENCY_2;

	RCC->CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY))
		;
	// Выбор PLL как основного источника тактирования
	RCC->CFGR |= RCC_CFGR_SW_PLL;

	//SystemCoreClockUpdate();
}
