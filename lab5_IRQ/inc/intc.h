#ifndef INTC_H
#define INTC_H

void AINTC_init(void);

void AINTC_enableIRQ(unsigned int irq);

void ISR_Handler(void);

void gpio_ISR(void);

void timer_ISR(void);

extern volatile unsigned int contador;
extern volatile unsigned int frequencia;

extern volatile unsigned int flag;
#endif