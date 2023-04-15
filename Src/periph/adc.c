#include <stm32f1xx.h>
#include "adc.h"


/**
 * \brief Функция инициализации
 */
void adc_init(void)
{
	//PC0 - Uout ADCI_N10
	//PC1 - Iout ADCI_N11
	//PC2 - TL   ADCI_N12
	//PC3 - не опеределено ADCI_N13

	// Разрешаем тактирование АЦП.
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;

	// Включаем АЦП.
	ADC1->CR2 |= ADC_CR2_ADON;
	ADC2->CR2 |= ADC_CR2_ADON;

	// Дождаться не менее 10 мкс
	for (int i = 0; i < 1000; i++)
		asm("nop");

	// Начать калибровку и дождаться её окончания.
	ADC1->CR2 |= ADC_CR2_CAL;
	while (ADC1->CR2 & ADC_CR2_CAL);

	ADC1->CR2 |= ADC_CR2_CAL;
	while (ADC1->CR2 & ADC_CR2_CAL);

	// Внешнее события для регуляронй группы - Timer3 TRIGO_event.
	ADC1->CR2 |= 4 << ADC_CR2_EXTSEL_Pos;
	ADC2->CR2 |= 4 << ADC_CR2_EXTSEL_Pos;

	// Включение триггера выборки регулярной группы.
	ADC1->CR2 |= ADC_CR2_EXTTRIG;
	ADC2->CR2 |= ADC_CR2_EXTTRIG;

	// Автоматический режим инжектированной группы - преобразование начнётся после всех регулярных каналов.
	ADC1->CR1 |= ADC_CR1_JAUTO;
	ADC2->CR1 |= ADC_CR1_JAUTO;

	// Включить режим сканирования.
	ADC1->CR1 |= ADC_CR1_SCAN;
	ADC2->CR1 |= ADC_CR1_SCAN;

	// Количество преобразований регулярной группы - 1 по дефолту.
	// Выбор канала первого преобразования регулярной группы.
	ADC1->SQR3 |= 3 << ADC_SQR3_SQ1_Pos;   // CH3 Uout
	ADC2->SQR3 |= 4 << ADC_SQR3_SQ1_Pos;   // CH4 IL

	// Количество преобразований инжектированных каналов - 1 по дефолту.
	// Выбор каналов инжектированной группы.
	ADC1->JSQR |= 5 << ADC_JSQR_JSQ4_Pos; //СH5 - TL.
	ADC2->JSQR |= 6 << ADC_JSQR_JSQ4_Pos; // CH6 - Reserved.

	// Устанавливаем длительность выборки в тактах АЦП:28.5 CLK
	ADC1->SMPR2 |= (3 << ADC_SMPR2_SMP3_Pos);
	ADC2->SMPR2 |= (3 << ADC_SMPR2_SMP4_Pos);
	ADC1->SMPR2 |= (3 << ADC_SMPR2_SMP5_Pos);
	ADC2->SMPR2 |= (3 << ADC_SMPR2_SMP6_Pos);

	// Включение прерывания после окончания регулярной группы
	ADC2->CR1 |= ADC_CR1_JEOCIE;

}
