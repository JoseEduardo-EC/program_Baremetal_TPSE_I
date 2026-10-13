#include "hw_types.h"
#include "soc_AM335x.h"
#include "bbb_regs.h"
#include "wdt.h"
#include "clock.h"
#include "pad.h"
#include "gpio.h"
#include "timer.h"
#include "uart.h"

//-----------------------------------------------------------------------

#define GPMC_AD14                       0x838   //GPIO1_14

//-----------------------------------------------------------------------



void _main(){
    //Clock da GPIO módulo 1
    set_CLOCK(CM_PER_GPIO1_CLKCTRL);
    //Clock do TIMER módulo 7
    set_CLOCK(CM_PER_TIMER7_CLKCTRL);

    //Multiplexação do pino para módulo GPIO
    set_PINMUX(GPMC_AD14, PINMUX_GPIO);

    //Seta a direção do pino configurado para GPIO como para saída
    set_dir(SOC_GPIO_1_REGS, 0, 14);

    //Liga o modo POSTED
    set_POSTED(SOC_DMTIMER_7_REGS);

    //Desabilita o WTD
    disable_watchdog();

    //Variavel para registrar o tempo do delay
    unsigned int time;
    
    do
    {
        //Menu
        
        prints(SOC_UART_0_REGS, "==========MENU==========\n\r");
        prints(SOC_UART_0_REGS, "1 - 0.5 Hz\n\r");
        prints(SOC_UART_0_REGS, "2 - 1.0 Hz\n\r");
        prints(SOC_UART_0_REGS, "3 - 2.0 Hz\n\r");
        prints(SOC_UART_0_REGS, "========================\n\r");
        prints(SOC_UART_0_REGS, "ESCOLHA: \n\r");
        


        //Variavel que vai receber a opção da frequência
        unsigned char option = getch(SOC_UART_0_REGS);

        //Printar na tela a opção escolhida
        putch(SOC_UART_0_REGS, option);
        prints(SOC_UART_0_REGS, "\n\r");

        switch (option)
        {
        case '1':
            time = 100;    //delay = 100 mili_seg (0,1 seg) -> f = 10 hz 
            break;
        case '2':
            time = 50;     //delay = 50 mili_seg (0,05 seg) -> f = 20 hz
            break;
        case '3':
            time = 25;    //delay = 25 mili_seg (0,025 seg) -> f = 40 hz
            break;
        default:
            prints(SOC_UART_0_REGS, "VALOR INVALIDO. TENTE NOVAMENTE......\n\r");
            continue;
        }

        //Loop para fazer o ciclo rodar 5 vezes
        for(volatile unsigned int i = 0; i < 5; i++){
            prints(SOC_UART_0_REGS, "LED on......\n\r");

            //Liga o LED
            gpio_on(SOC_GPIO_1_REGS, 14);
            delay(SOC_DMTIMER_7_REGS, time);    //Delay de time segundos

            
            prints(SOC_UART_0_REGS, "LED OFF.....\n\r");    

            //Desliga LED
            gpio_off(SOC_GPIO_1_REGS, 14);   
            delay(SOC_DMTIMER_7_REGS, time);    //Delay de time segundos
            
        }
    } while (1);
    
}