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
	unsigned char value;
	
	LED_Init(porta, pin1); // Green
	LED_Init(porta, pin4); // Yellow
	LED_Init(porta, pin7); // Red
	
	BCD_to_SEVEN_SEG_Init(portc, 0);
	
	EXTI_vEnable(EXTI0);
	EXTI_vActiveMode(EXTI0, FALLING);	
	EXTI_vEnable(EXTI1);
	EXTI_vActiveMode(EXTI1, FALLING);	
	EXTI_vEnable(EXTI2);
	EXTI_vActiveMode(EXTI2, FALLING);
    while (1) 
    {
		for(value = 0; value < 10; value++)
		{
			BCD_to_SEVEN_SEG_Write(portc, 0, value);
			_delay_ms(500);
		}
	}
}

ISR(INT0_vect)
{
	// EXTI_vDisable(EXTI0);
	for(unsigned char counter=0; counter < 4; counter++)
	{
		LED_On(porta, pin1);
		LED_Off(porta, pin4);
		LED_Off(porta, pin7);
		_delay_ms(100);
		LED_Off(porta, pin1);
		_delay_ms(100);
	}
	for(unsigned char counter=0; counter < 4; counter++)
	{
		LED_Off(porta, pin1);
		LED_On(porta, pin4);
		LED_Off(porta, pin7);
		_delay_ms(100);
		LED_Off(porta, pin4);
		_delay_ms(100);
	}	
	for(unsigned char counter=0; counter < 4; counter++)
	{
		LED_Off(porta, pin1);
		LED_Off(porta, pin4);
		LED_On(porta, pin7);
		_delay_ms(100);
		LED_Off(porta, pin7);
		_delay_ms(100);
	}
	// EXTI_vEnable(EXTI0);
}

ISR(INT1_vect)
{
	// EXTI_vDisable(EXTI0);
		LED_On(porta, pin1);
		LED_Off(porta, pin4);
		LED_Off(porta, pin7);
		_delay_ms(2000);
		LED_Off(porta, pin1);
		LED_On(porta, pin4);
		LED_Off(porta, pin7);
		_delay_ms(1000);
		LED_Off(porta, pin1);
		LED_Off(porta, pin4);
		LED_On(porta, pin7);
		_delay_ms(2000);
		LED_Off(porta, pin1);
		LED_Off(porta, pin4);
		LED_Off(porta, pin7);
	// EXTI_vEnable(EXTI0);
}

ISR(INT2_vect)
{
	// EXTI_vDisable(EXTI0);
	for(unsigned char counter=0; counter < 10; counter++)
	{
		LED_On(porta, pin1);
		_delay_ms(150);
		LED_Off(porta, pin1);
		LED_On(porta, pin4);
		_delay_ms(150);
		LED_Off(porta, pin4);		
		LED_On(porta, pin7);		
		_delay_ms(150);
		LED_Off(porta, pin7);
	}
	// EXTI_vEnable(EXTI0);
}





