#include "hw_types.h"
#include "soc_AM335x.h"
#include "bbb_regs.h"
#include "uart.h"

#define LSR_RXFIFOE     0x00
#define LSR_TXFIFOE     0x05

/*
========================================================
       NAME: putch
 PARAMETROS: Registrador base da UART e o caracter
    RETORNO: void
DESCRIPTION: Função que escreve no no registrador THR e esse byte é enviado pelo pino TX
1 - primeiro ela tem que verificar se o buffer (TXFIFOE) estar vázio, ou sejá, não tem nem um caracter já registrado no THR
2 - Depois ela escreve no registrador
========================================================
*/

void putch(unsigned int uart_base, unsigned char c){
    while(!(HWREG(uart_base + UART_LSR) & (1 << LSR_TXFIFOE)));

    HWREG(uart_base + UART_THR) = c;
}

/*
========================================================
       NAME: getch
 PARAMETROS: Registrador base da UART
    RETORNO: O caracter lido
DESCRIPTION: Função que lê o byte do registrador RHR que foi transmitido pelo pino RX
1 - Primeiro ela verifica se chegou algum byte novo no buffer (RXFIFOE)
2 - Depois ele lê do registrador RHR
========================================================
*/
unsigned char getch(unsigned int uart_base){
    while(!(HWREG(uart_base + UART_LSR) & (1 << LSR_RXFIFOE)));

    return HWREG(uart_base + UART_RHR);
}

/*
========================================================
       NAME: prints
 PARAMETROS: Registrador base da UART e string
    RETORNO: void
DESCRIPTION: Função que percorre a string até encontar um \0 e a cada caracter lido, chama a função putch para transmitir esse carcter
========================================================
*/
void prints(unsigned int uart_base, const char *str){
    for(volatile int i = 0; str[i] != '\0'; i++){
        putch(uart_base, str[i]);
    }
}