#ifndef __DSP_H__
#define __DSP_H__



#define FS (100.e3)             // Частота дискретизации (частота коммутации), [Гц].
#define TS (1./(FS))            // Период дискретизации (период коммутации), [с].


#define LIMIT(x, min, max) ( ((x) < (min)) ? (min) : ( ((x) > (max)) ? (max) : (x) ) )
#define Q_USE       (16)

#define SUM_Q(a, b)     ( (a) + (b) )
#define SUB_Q(a, b)     ( (a) - (b) )
#define MUL_Q(a, b)  ( (int32_t)(((int64_t)(a)*(int64_t)(b)) >> (Q_USE)) )
#define DIV_Q(a, b)  ( (int32_t)(((int64_t)(a) << (Q_USE)) / (int64_t)(b)) )

#define F2Q(f)   ( (int32_t)((1 << (Q_USE)) * (f)) )
#define Q20(i)   ( (int32_t)(((i) + (1 << ((Q_USE) - 1))) >> (Q_USE)) )
#define Q2F(i)   ( (float)Q20((i), (Q_USE)) )
//#define Q2F(i)   ( (float) (i) / ((2) << (Q_USE-1)) )








typedef struct
{
    int32_t k;        // Коэффициент интегратора (включает период дискретизации).
    int32_t sum;      // Сумма интегратора (выход).
    int32_t c;        // Переменая для накопления погрешности интегрирования в алгоритме Кэхэна.

    struct
    {
        int32_t min;  // Мин. значение суммы.
        int32_t max;  // Макс. значение суммы.

    } sat;  // Структура с параметрами ограничителя суммы.

} Integrator_Q_Struct;  // Структура параметров интегратора.



typedef struct
{
    int32_t kp;       // Коэффициент пропорциональной части.
    int32_t kb;       // Коэффициент обратной связи в алгоритме Back-calculation.

    Integrator_Q_Struct integrator;   // Интегральная часть.

    int32_t bc;        // Переменная обратной связи в алгоритме Back-calculation.

    struct
    {
        int32_t min;  // Мин. значение выхода.
        int32_t max;  // Макс. значение выхода.

    } sat;  // Структура с параметрами ограничителя выхода.

} PID_Controller_Q_Struct;    // Структура параметров ПИД-регулятора.





int32_t Trapezoidal_Integrator_Q(Integrator_Q_Struct * integrator, int32_t x);
int32_t PID_Controller_Q(PID_Controller_Q_Struct * pid, int32_t x);


#endif













