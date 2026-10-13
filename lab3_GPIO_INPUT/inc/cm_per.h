#ifndef CM_PER_H
#define CM_PER_H

//Endereços para clock do BUTAO
#define CM_PER_GPIO1_CLKCTRL                    0xAC
//Endereços para clock de Leds
#define CM_PER_GPIO2_CLKCTRL                    0xB0
#define CM_PER_GPIO3_CLKCTRL                    0xB4
//Ligar o clock
#define CONF_CM_PER_CLKCTRL_MODULEMODE_ENABLE  0x2


void set_cmp(void);
#endif