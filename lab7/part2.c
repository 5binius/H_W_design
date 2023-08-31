#include "address_map_nios2.h"
#include "nios2_ctrl_reg_macros.h"

static volatile int *KEY_ptr = (int *)KEY_BASE;
static volatile int *TIMER_ptr = (int *)TIMER_BASE;

int run = 1;
int count = 0;


int main()
{
	*(KEY_ptr + 2) = 0b1110;
	*(KEY_ptr + 3) = 0b1110;
	*(TIMER_ptr + 1) = 0b1011;
	*(TIMER_ptr + 2) = 0x783f;
	*(TIMER_ptr + 3) = 0x017d;
	*(TIMER_ptr + 1) = 0b0111;

	NIOS2_WRITE_IENABLE(0x3);
	NIOS2_WRITE_STATUS(1);

	volatile int *LEDR_ptr = (int *)LEDR_BASE;

	while (1) *LEDR_ptr = count;
}