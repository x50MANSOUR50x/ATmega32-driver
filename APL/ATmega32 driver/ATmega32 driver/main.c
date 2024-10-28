/*
 * ATmega32driver(main).c
 *
 * Created: 27/10/2024 10:14:32
 * Author : Mansour
 */ 

#define F_CPU 8000000UL
#include "util/delay.h"

#include "LED_interface.h"

int main(void)
{
    /* Replace with your application code */
	LED_Init(porta, pin0);
	LED_Init(portb, pin0);
	LED_Init(portc, pin0);
    while (1) 
    {
		// Green led on
		LED_On(porta, pin0);
		LED_Off(portb, pin0);
		LED_Off(portc, pin0);
		_delay_ms(3000);
		
		//Yellow led on
		LED_Off(porta, pin0);
		LED_On(portb, pin0);
		LED_Off(portc, pin0);
		_delay_ms(1000);
		
		//Yellow led on
		LED_Off(porta, pin0);
		LED_Off(portb, pin0);
		LED_On(portc, pin0);
		_delay_ms(3000);
    }
}

