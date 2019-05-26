#include <xparameters.h>
#include <xgpio.h>		// already in platform.h
#include "platform.h"

#include <stdio.h>
#include "xil_printf.h"


// Helper function for the binary printing
void print_binary(u32);

int main()
{
	// inits the uart
	init_platform();
	XGpio the_gpio;
	u32 mask1;
	u32 read_val;
	u32 gray_val;

	if(XGpio_Initialize(&the_gpio, XPAR_AXI_GPIO_0_DEVICE_ID))
	{
		print("XGpio Initialize failed");
		return -1;
	}
	// set the gpio to an input and get the data mask
	XGpio_SetDataDirection(&the_gpio, 1, 0x000000FF);
	mask1 = XGpio_GetDataDirection(&the_gpio, 1);


	// needed for task2
	//XGpio_SetDataDirection(&the_gpio, 2, 0x00000000);
	//mask1 = XGpio_GetDataDirection(&the_gpio, 1);

	// print is a simplified version of printf for printing over uart
	print("Hello World\n\r");

	while (1)
	{
		read_val = XGpio_DiscreteRead(&the_gpio, 0) & mask1;
		// conversion: gn = rn+1 xor rn
		gray_val = (read_val >> 1) ^ read_val;
		print_binary(gray_val);
	}

	// should never be reached
	cleanup_platform();
	return 0;
}

void print_binary(u32 in)
{
	for (int i = 0; i < 32; i++)
	{
		((in >> i) & 0x1) == 1 ? putchar('1') : putchar('0');
	}
	putchar('\r');
	putchar('\n');
}


