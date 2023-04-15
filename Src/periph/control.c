#include <stm32f1xx.h>
#include "dsp.h"
#include "control.h"
#include "gpio.h"
#include "timer.h"



Measure_Struct Measure =
{

#define K_ADC (3.3f / 4096.f)

    .scale =
    {

        .uout = F2Q(K_ADC),
        .iL = F2Q(K_ADC),
		.u_tl = F2Q(K_ADC),
		.reserved = F2Q(K_ADC),
    },

};

Protect_Struct Protect =
{
	.uout_max = F2Q(13.0f),
	.uout_min = F2Q(1.0f),
	.iL_max = F2Q(15.0f),
	.power_max = F2Q(150.0f),
};




/*
 * \brief Обработчик прерывания АЦП2.
 */
void ADC1_2_IRQHandler(void)
{
	//setPin(GPIOB, 12);

	// Сброс флага прерывания.
	ADC2->SR &= ~ADC_SR_JEOC;

	// Обработка данных ацп.
	adc_data_handler();

	// Проаерка программных защит
	checkProtect();



	// Проверка уровня TL c применением гистерезиса.
	if (Measure.data.u_tl < F2Q(0.5f))
	{
		//PFM_Disable();
		//syncDisable();
	}
	else if (Measure.data.u_tl > F2Q(0.8f))
	{
		//PFM_Enable();
		//syncEnable();
	}

	// Замодулировать сигнал тока.
	setFrecuency(Measure.data.iL);

}

/**
 * \brief Прерывание - обработчик окончания преобразования группы каналов АЦП.
 */
inline void adc_data_handler(void)
{
	Measure.data.uout = MUL_Q(Measure.scale.uout, F2Q(ADC1->DR));
	Measure.data.iL = MUL_Q(Measure.scale.iL, F2Q(ADC2->DR));
	Measure.data.u_tl = MUL_Q(Measure.scale.u_tl, F2Q(ADC1->JDR1));
	Measure.data.power =  MUL_Q(Measure.data.uout,Measure.data.iL);

}

inline void checkProtect(void)
{
	if(Measure.data.uout > Protect.uout_max) PFM_Disable();
	else PFM_Enable();
	if(Measure.data.iL > Protect.iL_max)  PFM_Disable();
	else PFM_Enable();
	if(Measure.data.power > Protect.power_max) PFM_Disable();
	else PFM_Enable();
}

