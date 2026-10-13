#include "soc_AM335x.h"
#include "hw_types.h"
#include "bbb_regs.h"
#include "clock.h"
#include "pad.h"
#include "gpio.h"
#include "wdt.h"
#include "timer.h"
#include "uart.h"
#include "intc.h"

#define GPIO1_2     0x808 //led 1
#define GPIO1_3     0x80C //led 2
#define GPIO1_7     0x81C //led 3


#define GPIO1_16    0x840 //botão 1
#define GPIO1_28    0x878 //botão 2



void _main(){
    //Seta clock dos periféricos
    set_CLOCK(CM_PER_GPIO1_CLKCTRL);
    set_CLOCK(CM_PER_TIMER7_CLKCTRL);
    
    //seta o modo POSTED do timer
    set_POSTED(SOC_DMTIMER_7_REGS);
    
    //Desabilita o whatchdog
    disable_watchdog();
    


    //Ativar o INTC
    AINTC_init();


    //leds
    set_PINMUX(GPIO1_2, PINMUX_GPIO_OU);
    set_PINMUX(GPIO1_3, PINMUX_GPIO_OU);
    set_PINMUX(GPIO1_7, PINMUX_GPIO_OU);
    //botões
    set_PINMUX(GPIO1_16, PINMUX_GPIO_IN);
    set_PINMUX(GPIO1_28, PINMUX_GPIO_IN);
    //saida
    set_dir(SOC_GPIO_1_REGS, 0, 2);
    set_dir(SOC_GPIO_1_REGS, 0, 3);
    set_dir(SOC_GPIO_1_REGS, 0, 7);
    //entrada
    set_dir(SOC_GPIO_1_REGS, 1, 16);
    set_dir(SOC_GPIO_1_REGS, 1, 28);




    //Ativando a interrupção em INTC
    AINTC_enableIRQ(98);    //GPIO1
    AINTC_enableIRQ(95);    //DMTIMER7

    //Habilitando o periférico a mandar o sinal de interrupção
    gpio_setIRQ(SOC_GPIO_1_REGS, 16);
    gpio_setIRQ(SOC_GPIO_1_REGS, 28);

    //menu
    prints(SOC_UART_0_REGS, "\033[H\033[J");
    prints(SOC_UART_0_REGS, "==========MENU==========\n\r");
    prints(SOC_UART_0_REGS, "1 - 0.5 Hz\n\r");
    prints(SOC_UART_0_REGS, "2 - 2.0 Hz\n\r");
    prints(SOC_UART_0_REGS, "3 - 4.0 Hz\n\r");
    prints(SOC_UART_0_REGS, "========================\n\r");
    
    //Inicialização das variaveis globais de interrupção do botão
    frequencia = 0;
    contador = 0;

    //Variavel so para guardar o valor de delay
    volatile unsigned int tempo;

    do
    {

        switch (frequencia)
        {
        case 0:
            tempo = 1000;
            break;
        case 1:
            tempo = 250;
            break;
        case 2:
            tempo = 125;
            break;
        default:
            break;
        }

        
        switch (contador)
        {
        case 0:
            gpio_on(SOC_GPIO_1_REGS, 2);
            timer_setupOverflow(SOC_DMTIMER_7_REGS, tempo);

            gpio_off(SOC_GPIO_1_REGS, 2);
            gpio_on(SOC_GPIO_1_REGS, 3);
            timer_setupOverflow(SOC_DMTIMER_7_REGS, tempo);

            gpio_off(SOC_GPIO_1_REGS, 3);
            gpio_on(SOC_GPIO_1_REGS, 7);
            timer_setupOverflow(SOC_DMTIMER_7_REGS, tempo);

            gpio_off(SOC_GPIO_1_REGS, 7);
            break;
        case 1:
            gpio_on(SOC_GPIO_1_REGS, 7);
            timer_setupOverflow(SOC_DMTIMER_7_REGS, tempo);

            gpio_off(SOC_GPIO_1_REGS, 7);
            gpio_on(SOC_GPIO_1_REGS, 3);
            timer_setupOverflow(SOC_DMTIMER_7_REGS, tempo);

            gpio_off(SOC_GPIO_1_REGS, 3);
            gpio_on(SOC_GPIO_1_REGS, 2);
            timer_setupOverflow(SOC_DMTIMER_7_REGS, tempo);

            gpio_off(SOC_GPIO_1_REGS, 2);

            break;
        case 2:
            gpio_on(SOC_GPIO_1_REGS, 2);
            gpio_on(SOC_GPIO_1_REGS, 3);
            gpio_on(SOC_GPIO_1_REGS, 7);

            timer_setupOverflow(SOC_DMTIMER_7_REGS, tempo);

            gpio_off(SOC_GPIO_1_REGS, 2);
            gpio_off(SOC_GPIO_1_REGS, 3);
            gpio_off(SOC_GPIO_1_REGS, 7);

            timer_setupOverflow(SOC_DMTIMER_7_REGS, tempo);
        default:
            break;
        }
    
    } while (1);
    

    
}


