#include "address_map_nios2.h"

extern volatile int *KEY_ptr;
extern int run;

void pushbutton_ISR()
{
	volatile int *TIMER_ptr = (int *)TIMER_BASE;
	volatile int *KEY_ptr = (int *)KEY_BASE;

	int press = *(KEY_ptr + 3);
	*(KEY_ptr + 3) = 0b1111;
	
	if (press & 0x8) {
		if (run) { *(TIMER_ptr + 1) = 0b1011; }
		else { *(TIMER_ptr + 1) = 0b0111; }
		run = run ^ 1;
	}
	return;
}