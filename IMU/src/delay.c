/*
 * delay.c
 *
 *  Created on: 6 mar 2017
 *      Author: Arek
 */

#include <stdint.h>
#include "delay.h"

volatile static uint32_t timer_ms = 0;

void SysTick_Handler()
{
 if (timer_ms)
 timer_ms--;
}

void delay_ms(int time)
{
 timer_ms = time;
 while (timer_ms);
}
