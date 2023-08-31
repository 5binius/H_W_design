#include "address_map_nios2.h"

volatile int *TIMER_ptr=(int *)TIMER_BASE;
extern int count;
extern int run;

void timer_ISR()
{
	*TIMER_ptr = 0;
	if (run==1) 
	count += 1;
	if (count == 1024) count = 0;
	return;
}