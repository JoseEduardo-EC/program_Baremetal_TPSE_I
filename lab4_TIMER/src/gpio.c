#include "hw_types.h"
#include "soc_AM335x.h"
#include "bbb_regs.h"
#include "gpio.h"


/*
========================================================
       NAME: set_dir
 PARAMETROS: Endereço base do GPIO a direção e o bit 
    RETORNO: void
DESCRIPTION: Função que ativa a direção do pino para trabalhar como saída (dir = 0) ou entrada (dir = 1)
========================================================
*/
void set_dir(unsigned int gpio_base, unsigned int dir, unsigned int bit){
    switch (dir)
    {
        //Saída
    case 0:
        HWREG(gpio_base + GPIO_OE) &= ~(1 << bit);
        break;
        //Entrada
    case 1:
        HWREG(gpio_base + GPIO_OE) |= (1 << bit);
        break;       
    default:
        break;
    }
}

/*
========================================================
       NAME: gpio_on
 PARAMETROS: Offset do pino, bit 
    RETORNO: void
DESCRIPTION: Função que coloca o gpio em nível alto
========================================================
*/

void gpio_on(unsigned int gpio_base, unsigned int bit){
    HWREG(gpio_base + GPIO_SETDATAOUT) |= (1 << bit);
}


/*
========================================================
       NAME: gpio_off
 PARAMETROS: Offset do pino, bit 
    RETORNO: void
DESCRIPTION: Função que coloca o gpio em nível baixo
========================================================
*/

void gpio_off(unsigned int gpio_base, unsigned int bit){
    HWREG(gpio_base + GPIO_CLEARDATAOUT) |= (1 << bit);
}