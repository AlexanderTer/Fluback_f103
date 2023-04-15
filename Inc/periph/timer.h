#ifndef __TIMER_H__
#define __TIMER_H__


void timer_init(void);
void setFrecuency(int32_t current);
void PFM_Enable (void);
void PFM_Disable (void);
void syncDisable(void);
void syncEnable(void);

#endif
