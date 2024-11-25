/*
 * ATmega32_driver.c
 *
 * Created: 2/11/2024 17:02:25
 * Author : mansour
 */ 

#define F_CPU 8000000UL

#include "util/delay.h"
#include "avr/interrupt.h"

#include "LED_interface.h"
#include "7SEGMENT_interface.h"
#include "EXTI_interface.h"


int main(void)
{
	char value;
		
	BCD_to_SEVEN_SEG_Init(portc, 0);
	BCD_to_SEVEN_SEG_Init(portc, 1);
	
	EXTI_vEnable(EXTI0);
	EXTI_vActiveMode(EXTI0, FALLING);	
	EXTI_vEnable(EXTI1);
	EXTI_vActiveMode(EXTI1, FALLING);	
	
    while (1) 
    {
		for(char value = 0; value < 10; value++)
		{
			BCD_to_SEVEN_SEG_Write(portc, 0, value);
			BCD_to_SEVEN_SEG_Write(portc, 1, value);
			_delay_ms(500);
		}
	}
}

ISR(INT0_vect)
{
		for(char value = 0; value < 10; value++)
			{
				BCD_to_SEVEN_SEG_Write(portc, 0, value);
				_delay_ms(500);
			}
}

ISR(INT1_vect)
{
	for(char value = 9; value >= 0 ; value--)
		{
			BCD_to_SEVEN_SEG_Write(portc, 1, value);
			_delay_ms(500);
		}
}
