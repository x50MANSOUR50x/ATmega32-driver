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
	LED_Init(portc, pin0);
	BUTTON_Init(porta, pin0);
	BUTTON_Enable_Internal_PullUp(porta, pin0);
    while (1) 
    {
		if(!BUTTON_Read(porta, pin0))
		{
			_delay_ms(500);
			LED_Off(portc, pin0);
			_delay_ms(2000);
		}
		else
		{
			LED_On(portc, pin0);
		}
    }
}

