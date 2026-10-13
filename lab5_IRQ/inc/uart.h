#ifndef UART_H
#define UART_H

void putch(unsigned int uart_base, unsigned char c);

unsigned char getch(unsigned int uart_base);

void prints(unsigned int uart_base, const char *str);

#endif