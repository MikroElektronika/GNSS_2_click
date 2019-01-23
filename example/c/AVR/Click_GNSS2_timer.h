/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_GNSS2_types.h"

uint32_t timerCounter = 0;

static void gnss2_configTimer()
{
    SREG_I_bit = 1; 
    TCCR1A = 0x80;
    TCCR1B = 0x09;
    OCR1AH = 0x1F; 
    OCR1AL = 0x3F; 
    OCIE1A_bit = 1; 
}

void Timer_interrupt() org IVT_ADDR_TIMER1_COMPA
{
    gnss2_tick();
	timerCounter++;
}