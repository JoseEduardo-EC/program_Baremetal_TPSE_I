#include "soc_AM335x.h"
#include "hw_types.h"
#include "bbb_regs.h"
#include "pad.h"

/*
========================================================
       NAME: set_PINMUX
 PARAMETROS: offset do pino e a ativação para a sua função
    RETORNO: void
DESCRIPTION: Função que ativa a multiplexação do pino para o modulo desejado.
========================================================
*/
void set_PINMUX(unsigned int offset, unsigned int mode){
    HWREG(SOC_CONTROL_REGS + offset) |= mode;
}