#ifndef __GPIO_H__
#define __GPIO_H__


#define setBit(GPIO,pin) (GPIO->BSRR |= 1 << pin)
#define resetBit(GPIO,pin) (GPIO->BRR |= 1 << pin)

void gpio_init(void);


#endif
