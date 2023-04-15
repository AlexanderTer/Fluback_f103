#include "stm32f1xx.h"
#include <stdint.h>
#include "rcc.h"
#include "gpio.h"
#include "timer.h"
#include "dsp.h"
#include "control.h"
#include "adc.h"
#include "interrupt.h"

float current;
uint32_t arr;
int main(void)
{
	rcc_init();
	gpio_init();
	timer_init();
	adc_init();
	interrupt_init();

	// Включить сигналы PFM и синхронизации.
	PFM_Enable();
	syncEnable();
	while (1)
	{



	}
}
