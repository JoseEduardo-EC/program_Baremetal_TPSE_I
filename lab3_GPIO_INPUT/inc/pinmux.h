#ifndef PINMUX_H
#define PINMUX_H

/*
======================================
Endereço para PINMUX dos pinos físicos
======================================
*/
//endereço para PINMUX (Botão)
#define CONF_GPMC_A1                           0x844    //GPIO1_17
#define CONF_GPMC_AD13                         0x834
//Endereços para PINMUX Leds internos
#define CONF_GPMC_A5                           0x854    //GPIO1_21
#define CONF_GPMC_A6                           0x858    //GPIO1_22
#define CONF_GPMC_A7                           0x85C    //GPIO1_23
#define CONF_GPMC_A8                           0x860    //GPIO1_24
//Endereços para PINMUX Led externo
#define CONF_LCD_DATA_1                        0x8A4    //GPIO2_7

#define CONF_GPMC_MODE_GPIO                    0x7      // So para output
#define CONF_GPMC_MODE_GPIO_IN                 0x27     //output + RXACTIVE (bit 5)

void set_PINMUX_GPIO(void);

#endif