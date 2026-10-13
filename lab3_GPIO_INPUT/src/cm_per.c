#include "cm_per.h"
#include "hw_types.h"
#include "soc_AM335x.h"

//Função para setar o clock do GPIO1 e GPIO2
void set_cmp(void){
    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |= CONF_CM_PER_CLKCTRL_MODULEMODE_ENABLE;
    //Verificar, através do bit 16 e 17 se o módulo terminou a transição e ficou funcional
    while ((HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) >> 16) & 0x3);

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO2_CLKCTRL) |= CONF_CM_PER_CLKCTRL_MODULEMODE_ENABLE;
    //Verificar, através do bit 16 e 17 se o módulo terminou a transição e ficou funcional
    while ((HWREG(SOC_CM_PER_REGS + CM_PER_GPIO2_CLKCTRL) >> 16) & 0x3);

    HWREG (SOC_CM_PER_REGS + CM_PER_GPIO3_CLKCTRL) |= CONF_CM_PER_CLKCTRL_MODULEMODE_ENABLE;
    //Verificar, através do bit 16 e 17 se o módulo terminou a transição e ficou funcional
    while ((HWREG(SOC_CM_PER_REGS + CM_PER_GPIO3_CLKCTRL) >> 16) & 0x3);
}