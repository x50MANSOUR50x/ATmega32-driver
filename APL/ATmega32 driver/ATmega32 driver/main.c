/*
 * 7segment.c
 *
 * Created: 26/10/2024 17:02:25
 * Author : moham
 */ 

#define F_CPU 8000000UL

#include "util/delay.h"
#include "7SEGMENT_interface.h"
#include "BUTTON_interface.h"
#include "LED_interface.h"

int main(void)
{
    /* Replace with your application code */
	SEVEN_SEG_Init(portd);
	SEVEN_SEG_Init(portc);
	BUTTON_Init(porta, pin0);
	BUTTON_Init(portb, pin0);
	LED_Init(portb, pin7);
	unsigned char b1 = BUTTON_Read(porta, pin0);
	unsigned char b2 = BUTTON_Read(portb, pin0);
	unsigned char number1 = 0;
	unsigned char number2 = 0;
	unsigned char whole_number = 0;
	unsigned char password = 25;
	SEVEN_SEG_Write(portc, number1);
	SEVEN_SEG_Write(portd, number2);
    while (1) 
    {
		LED_Off(portb, pin7);
		b1 = BUTTON_Read(porta, pin0);
		if(b1 == 1)
		{
			_delay_ms(500);
			number2++;
			SEVEN_SEG_Write(portc, number2);
			if(number2 >= 9)
			{
				number2 = 0;
				SEVEN_SEG_Write(portc, number2);
				number1++;
				SEVEN_SEG_Write(portd, number1);
			}
		}
		b2 = BUTTON_Read(portb, pin0);
		if(b2 == 1)
		{
			whole_number = (number1 * 10) + number2;
			if(whole_number == password)
			{
				LED_On(portb, pin7);
				_delay_ms(3000);
			}
		}

	}
}

/*
		for(int number1=0; number1<=9; number1++)
		{
			SEVEN_SEG_Write(portd, number1);
			for(int number2=0; number2<=9; number2++)
			{
				SEVEN_SEG_Write(portc, number2);
				_delay_ms(1000);
			}
		}
*/
