#include "wdt.h"
#include "soc_AM335x.h"
#include "hw_types.h"


//Ofssets do WATCHDOG
#define WDT_WSPR                       0x48
#define WDT_WWPS                       0x34

/*
========================================================
       NAME: disable_watchdog
 PARAMETROS: void
    RETORNO: void
DESCRIPTION: Função que era desabilitar o watchdog. 
1- Primeiro ela escreve 0xAAAA no registrador WSPR. 
2- Ler o bit 4 do WWPS para verificar se já terminou a transição.
3- Escreve 0x5555 em WSPR.
4- Ler o bit 4 do WWPS para verificar se já terminou a transição.
========================================================
*/
void disable_watchdog(void){
    //base + ofsset WDT_WSPR
    //Escrever 0xAAAA 
    HWREG(SOC_WDT_1_REGS + WDT_WSPR) = 0xAAAA;
    //Enquanto estiver em transição
    while(HWREG(SOC_WDT_1_REGS + WDT_WWPS) & (1 << 4));
    //base + ofsset WDT_WSPR
    //Escrever 0x5555
    HWREG(SOC_WDT_1_REGS + WDT_WSPR) = 0x5555;
    //Enquanto estiver em transição
    while(HWREG(SOC_WDT_1_REGS + WDT_WWPS) & (1 << 4));   

}