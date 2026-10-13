#include "hw_types.h"
#include "soc_AM335x.h"
#include "dir.h"

void set_dir_OU(unsigned int module, unsigned int bit){
    if(module == 0) HWREG(SOC_GPIO_0_REGS + GPIO_OE) &= ~(1 << bit);
    if(module == 1) HWREG(SOC_GPIO_1_REGS + GPIO_OE) &= ~(1 << bit);
    if(module == 2) HWREG(SOC_GPIO_2_REGS + GPIO_OE) &= ~(1 << bit);
    if(module == 3) HWREG(SOC_GPIO_3_REGS + GPIO_OE) &= ~(1 << bit);
}
//buutau
void set_dir_IN(unsigned int module, unsigned int bit){
    if(module == 1) HWREG(SOC_GPIO_1_REGS + GPIO_OE) |= (1 << bit);
    if(module == 2) HWREG(SOC_GPIO_2_REGS + GPIO_OE) |= (1 << bit);
    if(module == 3) HWREG(SOC_GPIO_3_REGS + GPIO_OE) |= (1 << bit);
}
