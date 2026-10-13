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
 PARAMETROS: Endereço base do GPIO, bit 
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
 PARAMETROS: Endereço base do GPIO, bit 
    RETORNO: void
DESCRIPTION: Função que coloca o gpio em nível baixo
========================================================
*/

void gpio_off(unsigned int gpio_base, unsigned int bit){
    HWREG(gpio_base + GPIO_CLEARDATAOUT) |= (1 << bit);
}

/*
========================================================
       NAME: gpio_setIRQ
 PARAMETROS: Endereço base do GPIO, bit 
    RETORNO: void
DESCRIPTION: Função que habilita a irq no pino do GPIO 
             Seta como ocorre a irq, (borda de subida 0->1)
========================================================
*/


void gpio_setIRQ(unsigned int gpio_base, unsigned int bit){
    //Seta interrupção
    HWREG(gpio_base + GPIO_IRQSTATUS_SET_0) |= (1 << bit);

    //Seta como ocorre
    HWREG(gpio_base + GPIO_RISINGDETECT) |= (1 << bit);
}

/*
========================================================
       NAME: gpio_clearIRQ
 PARAMETROS: Endereço base do GPIO, bit 
    RETORNO: void
DESCRIPTION: Função que limpa a flag de interrupção, sem ela o GPIO fica disparando infinitamente
========================================================
*/

void gpio_clearIRQ(unsigned int gpio_base, unsigned int  bit){
    HWREG(gpio_base + GPIO_IRQSTATUS_0) = (1 << bit);
}
