#ifndef __CONTROL_H__
#define __CONTROL_H__

/**
 * \brief Структура данных от АЦП.
 */
typedef struct
{

	struct
	{

		int32_t uout;         // Выходное напряжения, [В].
		int32_t iL;           // Ток реактора (входной ток), [А].
		int32_t u_tl;         // Напряжение на TL.
		int32_t reserved;     // Зарезервированный вход
		int32_t power;        // Мощность

	} data, scale; // data = scale * x + shift - рассчитанные значения.

// scale - коэффициенты масштабирования.

} Measure_Struct;   // Структура с параметрами измерений.
extern Measure_Struct Measure;

/**
 * \brief Структура защит
 */
typedef struct
{
	int32_t uout_max;         // Максимальное выходное напряжения, [В] * 2^16.
	int32_t uout_min;         // Минимальное выходное напряжения, [В] * 2^16.
	int32_t iL_max;           // Выходной ток, [А] * 2^16.
	int32_t power_max;        // Максимальная мощность, [Вт] * 2^16

} Protect_Struct;   // Структура с параметрами защит.
extern Protect_Struct Protect;

void adc_data_handler(void);
void ADC1_2_IRQHandler(void);
void checkProtect(void);



#endif
