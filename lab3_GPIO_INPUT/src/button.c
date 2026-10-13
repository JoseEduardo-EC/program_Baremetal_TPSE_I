#include "hw_types.h"
#include "soc_AM335x.h"
#include "button.h"


volatile unsigned int timer_atual = DELAY_NORMAL;
void GPIO_level(unsigned int bit){
    HWREG(SOC_GPIO_1_REGS + GPIO_SETDATAOUT) |= (1 << bit);

    for(volatile unsigned int i = 0; i < timer_atual; i++);

    HWREG(SOC_GPIO_1_REGS + GPIO_CLEARDATAOUT) |= (1 << bit);
}

volatile unsigned int flag_ordem = 0;
void verifica_botao1(void){
    if((HWREG(SOC_GPIO_1_REGS + GPIO_DATAIN) >> 17 /*GPIO1_17*/) & 1){
        flag_ordem ^= 1;

        while((HWREG(SOC_GPIO_1_REGS + GPIO_DATAIN) >> 17) & 1);
    }
}


volatile unsigned int flag_timer = 0;
void verifica_botao2(void){

    if((HWREG(SOC_GPIO_1_REGS + GPIO_DATAIN) >> 19/*GPIO3_19*/) & 1)
    {
        flag_timer ^= 1;

        if(flag_timer == 1){
            timer_atual = DELAY_TURBO;
            HWREG(SOC_GPIO_2_REGS + GPIO_SETDATAOUT) |= (1 << 7)/*GPIO2_7*/;
        }

        if(flag_timer == 0){
            timer_atual = DELAY_NORMAL;
            HWREG(SOC_GPIO_2_REGS + GPIO_CLEARDATAOUT) |= (1 << 7);
        }

        while((HWREG(SOC_GPIO_1_REGS + GPIO_DATAIN) >> 19) & 1);
    }
    
}

void GPIO_ordem0(void){
    GPIO_level(21);

    verifica_botao1();
    if(flag_ordem == 1) return;
    verifica_botao2();

    GPIO_level(22);

    verifica_botao1();
    if(flag_ordem == 1) return;
    verifica_botao2();

    GPIO_level(23);

    verifica_botao1();
    if(flag_ordem == 1) return;
    verifica_botao2();

    GPIO_level(24);

    verifica_botao1();
    if(flag_ordem == 1) return;
    verifica_botao2();

}

void GPIO_ordem1(void){
    GPIO_level(24);

    verifica_botao1();
    if(flag_ordem == 0) return;
    verifica_botao2();

    GPIO_level(23);

    verifica_botao1();
    if(flag_ordem == 0) return;
    verifica_botao2();

    GPIO_level(22);

    verifica_botao1();
    if(flag_ordem == 0) return;
    verifica_botao2();

    GPIO_level(21);

    verifica_botao1();
    if(flag_ordem == 0) return;
    verifica_botao2();   
}