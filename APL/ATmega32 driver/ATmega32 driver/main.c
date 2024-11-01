/*
 * 7segment.c
 *
 * Created: 26/10/2024 17:02:25
 * Author : mansour
 */ 

#define F_CPU 8000000UL

#include "util/delay.h"
#include "7SEGMENT_interface.h"
#include "BUTTON_interface.h"
#include "LED_interface.h"


int main(void)
{
	LED_Init(porta, pin0); // Green
	LED_Init(porta, pin1); // Yellow
	LED_Init(porta, pin2); // Red
	
	BUTTON_Init(portb, pin0);
	BUTTON_Init(portb, pin1);
	BUTTON_Init(portb, pin2);
	BUTTON_Init(portb, pin3);
	
	BUTTON_Init(portb, pin7);
	
	BCD_to_SEVEN_SEG_Init(portc, 0);
	BCD_to_SEVEN_SEG_Init(portc, 1);
	BCD_to_SEVEN_SEG_Init(portd, 0);
	BCD_to_SEVEN_SEG_Init(portd, 1);
	
	unsigned char seven_segment_1 = 0;
	unsigned char seven_segment_2 = 0; 
	unsigned char seven_segment_3 = 0; 
	unsigned char seven_segment_4 = 0; 
	
	unsigned int password = 1234;
	unsigned int check; 
	
    while (1) 
    {
		BCD_to_SEVEN_SEG_Write(portc, 0, seven_segment_1);
		BCD_to_SEVEN_SEG_Write(portc, 1, seven_segment_2);
		BCD_to_SEVEN_SEG_Write(portd, 0, seven_segment_3);
		BCD_to_SEVEN_SEG_Write(portd, 1, seven_segment_4);
		
		LED_Off(porta, pin0);
		LED_Off(porta, pin1);
		LED_Off(porta, pin2);
		
		if(BUTTON_Read(portb, pin0))
		{
			seven_segment_4++;
			_delay_ms(500);
		}
		
		if(BUTTON_Read(portb, pin1))
		{
			seven_segment_3++;
			_delay_ms(500);
		}
		
		if(BUTTON_Read(portb, pin2))
		{
			seven_segment_2++;
			_delay_ms(500);
		}
		
		if(BUTTON_Read(portb, pin3))
		{
			seven_segment_1++;
			_delay_ms(500);
		}
		
		if(BUTTON_Read(portb, pin7))
		{
			_delay_ms(500);
			
			LED_On(porta, pin1);
			_delay_ms(1000);
			LED_Off(porta, pin1);
			_delay_ms(1000);
			LED_On(porta, pin1);
			_delay_ms(1000);
			LED_Off(porta, pin1);
			_delay_ms(1000);
			LED_On(porta, pin1);
			_delay_ms(1000);
			LED_Off(porta, pin1);
			
			check = (seven_segment_4 * 1000) + (seven_segment_3 * 100) + (seven_segment_2 * 10) + (seven_segment_1);	
		
			if(check == password)
			{
				LED_On(porta, pin0);
				_delay_ms(3000);
			}
			else
			{
				LED_On(porta, pin2);
				_delay_ms(3000);
			}		
		}	
	}
}

