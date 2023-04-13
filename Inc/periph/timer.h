#ifndef __TIMER_H__
#define __TIMER_H__


void timer_init(void);
void setFrecuency(uint32_t frecuency);
void PFM_Enable (void);
void PFM_Disable (void);
void syncDisable(void);
void syncEnable(void);

#endif
