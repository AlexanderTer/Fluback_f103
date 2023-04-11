#include "stm32f1xx.h"
#include <stdint.h>
#include "rcc.h"
#include "gpio.h"
#include "timer.h"

float a = 3.f;
 uint32_t frec = 65535;


int main(void)
{
	rcc_init();
	gpio_init();
	timer_init();

	while (1)
	{
		setFrecuency();
		for(uint32_t i = 0;i<40000;i++){};
		frec++;
		if (frec > 722)frec = 18;
	}
}
