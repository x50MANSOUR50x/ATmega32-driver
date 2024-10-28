/*
 * ATmega32driver(main).c
 *
 * Created: 27/10/2024 10:14:32
 * Author : Mansour
 */ 

#define F_CPU 8000000UL
#include "util/delay.h"

#include "LED_interface.h"
#include "BUTTON_interface.h"

int main(void)
{
    /* Replace with your application code */
	LED_Init(portc, pin0); // Green
	LED_Init(portc, pin1); // Yellow
	LED_Init(portc, pin2); // Red
	BUTTON_Init(porta, pin0);
	
	unsigned char counter = 0;
    while (1) 
    {
		counter = 0;
		
		LED_Off(portc, pin0);
		LED_Off(portc, pin1);
		LED_Off(portc, pin2);
		
		while(BUTTON_Read(porta, pin0))
		{
			_delay_ms(1000);
			counter++;
			
			if(counter >= 5 && counter < 10)
			{
				LED_On(portc, pin0);
				LED_Off(portc, pin1);
				LED_Off(portc, pin2);
				//_delay_ms(3000);
			}
			else if(counter >= 10 && counter < 15)
			{
				LED_Off(portc, pin0);
				LED_On(portc, pin1);
				LED_Off(portc, pin2);
				//_delay_ms(3000);
			}
			else if(counter >= 15)
			{
				LED_Off(portc, pin0);
				LED_Off(portc, pin1);
				LED_On(portc, pin2);
				//_delay_ms(3000);
			}
		}
    }
}

