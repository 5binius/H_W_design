 
/*KEY_ISR*/

#include "address_map_nios2.h"

extern volatile int *KEY_ptr;
extern int HEX_on;

void key_service(int num) 
{
	int temp = 0;
	char HEX3 = (HEX_on >> 24);
	char HEX2 = (HEX_on >> 16);
	char HEX1 = (HEX_on >> 8);
	char HEX0 = HEX_on;

	if (num == 0) HEX0 = HEX0 ^ 0b00111111;
	else if (num == 1) HEX1 = HEX1 ^ 0b00000110;
	else if (num == 2) HEX2 = HEX2 ^ 0b01011011;
	else HEX3 = HEX3 ^ 0b01001111;

	temp = temp | HEX3;
	temp = temp << 8;
	temp = temp | HEX2;
	temp = temp << 8;
	temp = temp | HEX1;
	temp = temp << 8;
	temp = temp | HEX0;
	HEX_on = temp;
}

void pushbutton_ISR()
{
	int press = *(KEY_ptr + 3);
	int flag = *(KEY_ptr + 3);
	int key[4] = { 0 };
	int i;
	*(KEY_ptr + 3) = press;

	key[3] = flag & 0b1000;
	key[2] = flag & 0b0100;
	key[1] = flag & 0b0010;
	key[0] = flag & 0b0001;

	for (i = 0; i < 4; i++) {
		if (key[i] != 0) key_service(i);
	}
	return;
}

