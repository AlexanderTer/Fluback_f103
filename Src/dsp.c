
#include <stm32f1xx.h>
#include "dsp.h"

#include <string.h>
#include <stdlib.h>
#include <math.h>


/**
 * \brief       Функция интегратора методом трапеций (Trapezoidal).
 *
 * \param       integrator: структура с параметрами интегратора.
 * \param       x: вход интегратора.
 *
 * \return      y: сумму интегратора (выход).
 *
 */
inline int32_t Trapezoidal_Integrator_Q(Integrator_Q_Struct * integrator, int32_t x)
{
    // out[n] = s[n-1] + x[n] * k.
    int32_t out = LIMIT(SUM_Q(integrator->sum, MUL_Q(x, integrator->k, Q_USE)), integrator->sat.min, integrator->sat.max);

    // s[n] = out[n] + x[n] * k.
    integrator->sum = SUM_Q(out, MUL_Q(x, integrator->k, Q_USE));

    return out;
}


/**
 * \brief       Функция ПИД-регулятора.
 *
 * \param       pid: структура с параметрами регулятора.
 * \param       x: вход регулятора.
 *
 * \return      y: выход регулятора.
 *
 */

inline int32_t PID_Controller_Q(PID_Controller_Q_Struct * pid, int32_t x)
{
    // Расчёт пропорциональной части.
    int32_t out_p = MUL_Q(x, pid->kp, Q_USE);

    // Расчёт интегральной части.
    int32_t out_i = Trapezoidal_Integrator_Q(&pid->integrator, x);

    return LIMIT(SUM_Q(out_p, out_i), pid->sat.min, pid->sat.max);
}

















