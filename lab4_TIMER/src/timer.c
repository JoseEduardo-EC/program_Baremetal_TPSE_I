#include "hw_types.h"
#include "soc_AM335x.h"
#include "bbb_regs.h"
#include "timer.h"

#define SET_MODE_POSTED       0x02

#define ST_BIT                0x00
#define W_PEND_TCLR           0x00
#define W_PEND_TCRR           0x01
#define W_PEND_TLDR           0x02

/*
========================================================
       NAME: set_POSTED
 PARAMETROS: Registrador base do timer 
    RETORNO: void
DESCRIPTION: Função que ativa o modo POSTED do timer
========================================================
*/
void set_POSTED(unsigned int timer_base){
    HWREG(timer_base + DMTIMER_TSICR) |= (1 << SET_MODE_POSTED);
}

/*
========================================================
       NAME: start_TIMER
 PARAMETROS: Registrador base do timer 
    RETORNO: void
DESCRIPTION: Função que ativa o timer. Primeiro ela verifica se não tem nada pendente e depois seta o bit ST
========================================================
*/
void start_TIMER(unsigned int timer_base){
    //Enquanto for 1, fica no loop
    while((HWREG(timer_base + DMTIMER_TWPS) >> W_PEND_TCLR) & 0x01);

    //Ativa o bit ST
    HWREG(timer_base + DMTIMER_TCLR) |= (1 << ST_BIT);
}

/*
========================================================
       NAME: stop_TIMER
 PARAMETROS: Registrador base do timer 
    RETORNO: void
DESCRIPTION: Função que desliga o timer. Primeiro ela verifica se não tem nada pendente e depois limpa o bit ST
========================================================
*/
void stop_TIMER(unsigned int timer_base){
    //Enquanto for 1, fica no loop
    while((HWREG(timer_base + DMTIMER_TWPS) >> W_PEND_TCLR) & 0x01);

    //Desliga o bit ST
    HWREG(timer_base + DMTIMER_TCLR) &= ~(1 << ST_BIT);
}

/*
========================================================
       NAME: reset_TIMER
 PARAMETROS: Registrador base do timer 
    RETORNO: void
DESCRIPTION: Função que reseta o valor do do contador e do time loader. Primeiro ela verifica se não tem nada pendente
========================================================
*/
void reset_TIMER(unsigned int timer_base){
    while((HWREG(timer_base + DMTIMER_TWPS) >> W_PEND_TCRR) & 0x01);
    HWREG(timer_base + DMTIMER_TCRR) = 0x00;

    while((HWREG(timer_base + DMTIMER_TWPS) >> W_PEND_TLDR) & 0x01);
    HWREG(timer_base + DMTIMER_TLDR) = 0x00;
}

/*
========================================================
       NAME: delay
 PARAMETROS: Registrador base do timer e o tempo fornecido em mili segundos
    RETORNO: void
DESCRIPTION: Função que fica em espera ocupada até que o contador chegue ao valor de ciclos.
             O contador incrementa a 24 Mhz.
1 - Para o timer
2 - reseta o contador TCRR e reseta o time loader
3 - Começa a rodar o timer
4 - Fica dentro do laço até TCRR chegar ao valor de ciclos
5 - Para o timer
========================================================
*/
void delay(unsigned int timer_base, unsigned int mili_segundos){
    unsigned int ciclos = mili_segundos * 24000;

    stop_TIMER(timer_base);

    reset_TIMER(timer_base);

    start_TIMER(timer_base);

    while(HWREG(timer_base + DMTIMER_TCRR ) < ciclos);

    stop_TIMER(timer_base);

}