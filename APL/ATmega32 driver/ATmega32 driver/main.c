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
	LED_Init(portc, pin1);
	//LED_Init(porta, pin7);
	EXTI_vEnable(EXTI0);
	// EXTI_vActiveMode(EXTI0, LOW);
	EXTI_vActiveMode(EXTI0, CHANGE);
	// EXTI_vActiveMode(EXTI0, FALLING);
	// EXTI_vActiveMode(EXTI0, RISING);
    while (1) 
    {
		LED_On(portc, pin1);
	}
}

ISR(INT0_vect)
{
	// EXTI_vDisable(EXTI0);
	LED_Off(portc, pin1);
	_delay_ms(3000);
	// EXTI_vEnable(EXTI0);
}


