#ifndef BBB_REGS_H
#define BBB_REGS_H

/* =========================================================
        CM_PER — Clock Module Peripheral offsets
   ========================================================= */
#define CM_PER_GPMC_CLKCTRL         0x01C
#define CM_PER_UART1_CLKCTRL        0x06C
#define CM_PER_UART2_CLKCTRL        0x070
#define CM_PER_UART3_CLKCTRL        0x074
#define CM_PER_TIMER2_CLKCTRL       0x080
#define CM_PER_TIMER3_CLKCTRL       0x084
#define CM_PER_TIMER4_CLKCTRL       0x088
#define CM_PER_TIMER5_CLKCTRL       0x0EC
#define CM_PER_TIMER6_CLKCTRL       0x0F0
#define CM_PER_TIMER7_CLKCTRL       0x07C
#define CM_PER_GPIO1_CLKCTRL        0x0AC
#define CM_PER_GPIO2_CLKCTRL        0x0B0
#define CM_PER_GPIO3_CLKCTRL        0x0B4
#define CM_PER_I2C1_CLKCTRL         0x048
#define CM_PER_I2C2_CLKCTRL         0x04C
#define CM_PER_SPI0_CLKCTRL         0x05C
#define CM_PER_SPI1_CLKCTRL         0x060

/* =========================================================
                        GPIO offsets 
   ========================================================= */

#define GPIO_REVISION               0x000
#define GPIO_SYSCONFIG              0x010
#define GPIO_SYSSTATUS              0x114
#define GPIO_IRQSTATUS_RAW_0        0x024
#define GPIO_IRQSTATUS_RAW_1        0x028
#define GPIO_IRQSTATUS_0            0x02C
#define GPIO_IRQSTATUS_1            0x030
#define GPIO_IRQSTATUS_SET_0        0x034
#define GPIO_IRQSTATUS_SET_1        0x038
#define GPIO_IRQSTATUS_CLR_0        0x03C
#define GPIO_IRQSTATUS_CLR_1        0x040
#define GPIO_IRQWAKEN_0             0x044
#define GPIO_IRQWAKEN_1             0x048
#define GPIO_SYSSTATUS_RAW          0x114
#define GPIO_CTRL                   0x130
#define GPIO_OE                     0x134
#define GPIO_DATAIN                 0x138
#define GPIO_DATAOUT                0x13C
#define GPIO_LEVELDETECT0           0x140
#define GPIO_LEVELDETECT1           0x144
#define GPIO_RISINGDETECT           0x148
#define GPIO_FALLINGDETECT          0x14C
#define GPIO_DEBOUNCENABLE          0x150
#define GPIO_DEBOUNCINGTIME         0x154
#define GPIO_CLEARDATAOUT           0x190
#define GPIO_SETDATAOUT             0x194

/* =========================================================
                    DMTIMER offsets 
   ========================================================= */
   
#define DMTIMER_TIDR              0x00
#define DMTIMER_TIOCP_CFG         0x10
#define DMTIMER_IRQ_EOI           0x20
#define DMTIMER_IRQSTATUS_RAW     0x24
#define DMTIMER_IRQSTATUS         0x28
#define DMTIMER_IRQENABLE_SET     0x2C
#define DMTIMER_IRQENABLE_CLR     0x30
#define DMTIMER_IRQWAKEEN         0x34
#define DMTIMER_TCLR              0x38
#define DMTIMER_TCRR              0x3C
#define DMTIMER_TLDR              0x40
#define DMTIMER_TTGR              0x44
#define DMTIMER_TWPS              0x48
#define DMTIMER_TMAR              0x4C
#define DMTIMER_TCAR1             0x50
#define DMTIMER_TSICR             0x54
#define DMTIMER_TCAR2             0x58

/* =========================================================
                        UART offsets 
   ========================================================= */
#define UART_RHR                    0x000
#define UART_THR                    0x000
#define UART_DLL                    0x000
#define UART_IER                    0x004
#define UART_DLH                    0x004
#define UART_IIR                    0x008
#define UART_FCR                    0x008
#define UART_EFR                    0x008
#define UART_LCR                    0x00C
#define UART_MCR                    0x010
#define UART_LSR                    0x014
#define UART_MSR                    0x018
#define UART_TCR                    0x018
#define UART_SPR                    0x01C
#define UART_TLR                    0x01C
#define UART_MDR1                   0x020
#define UART_MDR2                   0x024
#define UART_UASR                   0x038
#define UART_SCR                    0x040
#define UART_SSR                    0x044
#define UART_SYSC                   0x054
#define UART_SYSS                   0x058

/* =========================================================
                        Interruption offsets 
   ========================================================= */

#define INTC_REVISION            0x00
#define INTC_SYSCONFIG           0x10
#define INTC_SYSSTATUS           0x14
#define INTC_SIR_IRQ             0x40
#define INTC_SIR_FIQ             0x44
#define INTC_CONTROL             0x48
#define INTC_PROTECTION          0x4C
#define INTC_IDLE                0x50
#define INTC_IRQ_PRIORITY        0x60
#define INTC_FIQ_PRIORITY        0x64
#define INTC_THRESHOLD           0x68
#define INTC_ITR0                0x80
#define INTC_MIR0                0x84
#define INTC_MIR_CLEAR0          0x88
#define INTC_MIR_SET0            0x8C
#define INTC_ISR_SET0            0x90
#define INTC_ISR_CLEAR0          0x94
#define INTC_PENDING_IRQ0        0x98
#define INTC_PENDING_FIQ0        0x9C
#define INTC_ITR1                0xA0
#define INTC_MIR1                0xA4
#define INTC_MIR_CLEAR1          0xA8
#define INTC_MIR_SET1            0xAC
#define INTC_ISR_SET1            0xB0
#define INTC_ISR_CLEAR1          0xB4
#define INTC_PENDING_IRQ1        0xB8
#define INTC_PENDING_FIQ1        0xBC
#define INTC_ITR2                0xC0
#define INTC_MIR2                0xC4
#define INTC_MIR_CLEAR2          0xC8
#define INTC_MIR_SET2            0xCC
#define INTC_ISR_SET2            0xD0
#define INTC_ISR_CLEAR2          0xD4
#define INTC_PENDING_IRQ2        0xD8
#define INTC_PENDING_FIQ2        0xDC
#define INTC_ITR3               0x0E0
#define INTC_MIR3               0x0E4
#define INTC_MIR_CLEAR3         0x0E8
#define INTC_MIR_SET3           0x0EC
#define INTC_ISR_SET3           0x0F0
#define INTC_ISR_CLEAR3         0x0F4
#define INTC_PENDING_IRQ3       0x0F8
#define INTC_PENDING_FIQ3       0x0FC



#define INTC_SYSCONFIG_SOFTRESET            0x02
#define INTC_SYSSTATUS_RESETDONE            0x01
#define INTC_THRESHOLD_PRIORITYTHRESHOLD    0xFF

/* =========================================================
                        PINMUX mode bits 
   ========================================================= */


#define PINMUX_GPIO_OU              0x7
#define PINMUX_GPIO_IN              0x27
#define PINMUX_UART                 0x0
#define PINMUX_I2C                  0x2
#endif