#include "hw_types.h"
#include "soc_AM335x.h"
#include "bbb_regs.h"
#include "clock.h"

#define MODULEMODE_ENABLE        0x2
#define IDLEST_MASK              0x3

/*
========================================================
       NAME: set_CLOCK
 PARAMETROS: offset do periférico
    RETORNO: void
DESCRIPTION: Função que que habilitar o clock no periférico. Após isso, ira fazer a leitura 
             dos bits de status (16 e 17), para saber se ainda estão em transição.
========================================================
*/

void set_CLOCK(unsigned int offset){
    HWREG(SOC_CM_PER_REGS + offset) |= MODULEMODE_ENABLE;

    while((HWREG(SOC_CM_PER_REGS + offset) >> 16) & IDLEST_MASK);
}