/*
 * ATmega32_driver.c
 *
 * Created: 2/11/2024 17:02:25
 * Author : Ahmed Amin Semsemaha
 */ 

#define F_CPU 8000000UL

#include "util/delay.h"

#include "ADC_interface.h"

unsigned short read_value;


int main(void)
{
	ADC_Init(0);
	
    while (1) 
    {
		read_value = ADC_Read(0);
	}
}