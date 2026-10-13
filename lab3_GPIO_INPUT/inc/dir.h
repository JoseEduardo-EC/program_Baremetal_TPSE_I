#ifndef DIR_H
#define DIR_H

//Endereços para GPIO
#define GPIO_OE                                0x134

void set_dir_OU(unsigned int module, unsigned int bit);

void set_dir_IN(unsigned int module, unsigned int bit);
#endif