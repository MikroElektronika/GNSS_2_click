/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_GNSS2_types.h"

uint32_t timerCounter = 0;

static void gnss2_configTimer()
{
    T1CON	 = 0x8000;
    T1IE_bit = 1;
    T1IF_bit = 0;
    IPC0	 = IPC0 | 0x1000;
    PR1		 = 4000;
}

void Timer_interrupt() iv IVT_ADDR_T1INTERRUPT
{
    T1IF_bit = 0;
	timerCounter++;
    gnss2_tick();
}
