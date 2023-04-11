#include "stm32f1xx.h"
#include <stdint.h>
#include "rcc.h"
#include "gpio.h"
#include "timer.h"

float a = 3.f;



int main(void)
{
	rcc_init();
	gpio_init();
	timer_init();

	while (1)
	{
		a++;
		if (a == 10)
			a = 0;
	}
}
