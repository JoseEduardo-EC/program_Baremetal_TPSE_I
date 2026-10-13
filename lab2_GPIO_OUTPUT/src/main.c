#include "soc_AM335x.h"
#include "hw_types.h"
#include "wdt.h"

//Endereço para clock
#define CM_PER_GPIO1_CLKCTRL                   0xAC
#define CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE 0x2

//Endereço para PINMUX dos pinos físicos
#define CONFIG_GPMC_BE1                        0x878
#define CONF_GPMC_A5                           0x854
#define CONF_GPMC_A6                           0x858
#define CONF_GPMC_A7                           0x85C
#define CONF_GPMC_A8                           0x860
//setar como GPIO
#define CONF_GPMC_MODE_GPIO                    0x7

//Endereços para GPIO
#define GPIO_OE                                0x134
#define GPIO_SETDATAOUT                        0x194
#define GPIO_CLEARDATAOUT                      0x190

#define TIME                                   1000000


//Setar o clock do GPIO1. (Base cm_per + ofsset), depois eu seto o segundo bit menos significativo.
void set_cmp_GPIO1(void){
    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |= CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE;
}

//Definir o PINMUX como GPIO. (Base control_regs + ofssets), depois seto 111 para enable
void set_PINMUX_GPIO1(void){
    HWREG(SOC_CONTROL_REGS + CONFIG_GPMC_BE1) |= CONF_GPMC_MODE_GPIO;
    HWREG(SOC_CONTROL_REGS + CONF_GPMC_A5) |= CONF_GPMC_MODE_GPIO;
    HWREG(SOC_CONTROL_REGS + CONF_GPMC_A6) |= CONF_GPMC_MODE_GPIO;
    HWREG(SOC_CONTROL_REGS + CONF_GPMC_A7) |= CONF_GPMC_MODE_GPIO;
    HWREG(SOC_CONTROL_REGS + CONF_GPMC_A8) |= CONF_GPMC_MODE_GPIO;
}

//Mudar a direção do GPIO1 para saída
void set_dir_GPIO1(unsigned int bit){
    HWREG(SOC_GPIO_1_REGS + GPIO_OE) &= ~(1 << bit);
}

//Função que altera o nível lógico do GPIO1
void GPIO_level(int bit){

    HWREG(SOC_GPIO_1_REGS + GPIO_SETDATAOUT) |= (1 << bit);
    //Quando esse laço acabar, ele vai alterar o nível lógico de alto para baixo
    for(volatile int i = 0; i < TIME; i++);
    HWREG(SOC_GPIO_1_REGS + GPIO_CLEARDATAOUT) |= (1 << bit); 
    
}

int _main(){
    //Desabilitar o WATCHDOG
    disable_watchdog();

    set_cmp_GPIO1();

    //Verificar, através do bit 16 e 17 se o módulo terminou a transição e ficou funcional
    while ((HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) >> 16) & 0x3);

    set_PINMUX_GPIO1();
    
    //Led externo
    set_dir_GPIO1(28);
    //Led USR
    set_dir_GPIO1(21);
    set_dir_GPIO1(22);
    set_dir_GPIO1(23);
    set_dir_GPIO1(24);

    while (1)
    {
        //Led USR
        GPIO_level(21);
        GPIO_level(22);
        GPIO_level(23);
        GPIO_level(24);
        //Led externo
        GPIO_level(28);
    }
    

}