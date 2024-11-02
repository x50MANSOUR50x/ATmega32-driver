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
#include "EXTI_interface.h"


int main(void)
{
	LED_Init(porta, pin0);
	LED_Init(porta, pin7);
	EXTI_vEnable(EXTI0);
	EXTI_vActiveMode(EXTI0, RISING);
    while (1) 
    {
		LED_On(porta, pin0);
		_delay_ms(1000);
		LED_Off(porta, pin0);
		_delay_ms(1000);
	}
}

ISR(INT0_vect)
{
	// EXTI_vDisable(EXTI0);
	LED_On(porta, pin7);
	_delay_ms(1000);
	LED_Off(porta, pin7);
	_delay_ms(1000);
	LED_On(porta, pin7);
	_delay_ms(1000);
	LED_Off(porta, pin7);
	_delay_ms(1000);
	LED_On(porta, pin7);
	_delay_ms(1000);
	LED_Off(porta, pin7);
	_delay_ms(1000);
	// EXTI_vEnable(EXTI0);
}


