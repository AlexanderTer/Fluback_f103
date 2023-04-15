#ifndef __GPIO_H__
#define __GPIO_H__


#define setPin(GPIO,pin) (GPIO->BSRR |= 1 << pin)
#define resetPin(GPIO,pin) (GPIO->BRR |= 1 << pin)

void gpio_init(void);


#endif
