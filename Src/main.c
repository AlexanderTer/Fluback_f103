#include "stm32f1xx.h"
#include <stdint.h>
#include "rcc.h"
#include "gpio.h"
#include "timer.h"

float a = 3.f;
uint32_t frec = 65535;
uint32_t flag = 0;

int main(void)
{
	rcc_init();
	gpio_init();
	timer_init();
	adc_init();
	interrupt_init();

	while (1)
	{

		//for(uint32_t i = 0; i< 10000;i++){	asm("nop");};


		for(uint32_t i = 0; i< 10000;i++){	asm("nop");};

		asm("nop");

	}
}
