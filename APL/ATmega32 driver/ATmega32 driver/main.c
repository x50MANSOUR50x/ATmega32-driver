/*
 * 7segment.c
 *
 * Created: 26/10/2024 17:02:25
 * Author : mansour
 */ 

#define F_CPU 8000000UL

#include "util/delay.h"
#include "7SEGMENT_interface.h"


int main(void)
{
	BCD_to_SEVEN_SEG_Init(portc, 0);
	BCD_to_SEVEN_SEG_Init(portc, 1);
	
    while (1) 
    {
		for(unsigned char i=0; i<10; i++)
		{
			BCD_to_SEVEN_SEG_Write(portc, 0, i);
			for(unsigned char j=0; j < 10; j++)
				{
						BCD_to_SEVEN_SEG_Write(portc, 1, j);
						_delay_ms(100);
				}
		}
	}
}

