#ifndef __CONTROL_H__
#define __CONTROL_H__

typedef struct
{

	struct
	{

		int32_t uout;         // Выходное напряжения, [В].
		int32_t iL;           // Ток реактора (входной ток), [А].
		int32_t u_tl;         // Напряжение на TL.
		int32_t reserved;     // Зарезервированный вход

	} data, scale; // data = scale * x + shift - рассчитанные значения.

							   // scale - коэффициенты масштабирования.

} Measure_Struct;   // Структура с параметрами измерений.
extern Measure_Struct Measure;


void adc_data_handler(void);
#endif
