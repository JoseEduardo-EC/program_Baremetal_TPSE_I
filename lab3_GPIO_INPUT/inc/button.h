#ifndef BUTTON_H
#define BUTTON_H

#define DELAY_NORMAL                           1000000
#define DELAY_TURBO                            50000

#define GPIO_SETDATAOUT                        0x194
#define GPIO_CLEARDATAOUT                      0x190
#define GPIO_DATAIN                            0x138

extern volatile unsigned int flag_ordem;
extern volatile unsigned int flag_timer;

void verifica_botao1(void);
void verifica_botao2(void);
void GPIO_ordem0(void);
void GPIO_ordem1(void);

#endif