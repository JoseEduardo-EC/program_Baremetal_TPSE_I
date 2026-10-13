#ifndef GPIO_H
#define GPIO_H

void set_dir(unsigned int gpio_base, unsigned int dir, unsigned int bit); 

void gpio_on(unsigned int gpio_base, unsigned int bit);

void gpio_off(unsigned int gpio_base, unsigned int bit);
#endif