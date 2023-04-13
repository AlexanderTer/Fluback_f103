#include <stm32f1xx.h>
#include "dsp.h"
#include "control.h"

Measure_Struct Measure =
{
#define V25 (F2Q(0.76, Q_USE))
#define AV_SLOPE (F2Q(2.5 * 0.001, Q_USE))
#define K_ADC (3.3 / 4096.)

    .scale =
    {

        .uout = F2Q(K_ADC, Q_USE),
        .iL = F2Q(K_ADC, Q_USE),
		.u_tl = F2Q(K_ADC, Q_USE),
		.reserved = F2Q(K_ADC, Q_USE),
    },

};

/**
 * \brief Прерывание - обработчик окончания преобразования группы каналов АЦП
 */
void adc_data_handler(void)
{
	Measure.data.uout =  ADC1->DR;
	Measure.data.iL = ADC1->JDR2;
	Measure.data.u_tl =  ADC1->JDR3;
	Measure.data.reserved =  ADC1->JDR4;
}

