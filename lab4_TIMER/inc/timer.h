#ifndef TIMER_H
#define TIMER_H

void set_POSTED(unsigned int timer_base);

void start_TIMER(unsigned int timer_base);

void stop_TIMER(unsigned int timer_base);

void reset_TIMER(unsigned int timer_base);

void delay(unsigned int timer_base, unsigned int mili_segundos);

#endif