/**********************************************************************************************/
/*                                                                                            */
/*  Author       : Mansour                                                                    */
/*  Last Updated : 21/10/2024, 07:22 AM                                                       */
/*  Version      : 1.0                                                                        */
/*  Description  : interface                                                                  */
/*                                                                                            */
/*  Changelog    :                                                                            */
/*     - v1.0 (21/10/2024): Initial version created.                                          */
/*                                                                                            */
/*  License      : <Specify license type here if applicable>                                  */
/*                                                                                            */
/**********************************************************************************************/

#include "Definitions.h"
#include "DIO_interface.h"
#include "DIO_registers.h"
void DIO_SetPinDir (uint8_t port,uint8_t pin, uint8_t dir)
{
	switch(port)
	{
	    //portA
		case porta:
		if(dir==OUTPUT)
		{
			//DDRA|=(1<<pin);
			Bit_Set(DDRA,pin);
		}
		else
		{
			//DDRA&=~(1<<pin);
			Bit_Clear(DDRA,pin);
		}
		break;
		//portB
		case portb:
		if(dir==OUTPUT)
		{
			//DDRB|=(1<<pin);
		    Bit_Set(DDRB,pin);
		}
		else
		{
			//DDRB&=~(1<<pin);
			Bit_Clear(DDRB,pin);
		}
		break;
		//portC
		case portc:
		if(dir==OUTPUT)
		{
			//DDRC|=(1<<pin);
			Bit_Set(DDRC,pin);
		}
		else
		{
			//DDRC&=~(1<<pin);
			Bit_Clear(DDRC,pin);
		}
		break;
		//portD
		case portd:
		if(dir==OUTPUT)
		{
			//DDRD|=(1<<pin);
			Bit_Set(DDRD,pin);
		}
		else
		{
			//DDRD&=~(1<<pin);
			Bit_Clear(DDRD,pin);
		}
		break;
	}
}
void DIO_WritePin (uint8_t port,uint8_t pin, uint8_t val)
{
	switch(port)
	{
		//portA
		case porta:
		if(val==OUTPUT)
		{
			//PORTA|=(1<<pin);
			Bit_Set(PORTA,pin);
		}
		else
		{
			//PORTA&=~(1<<pin);
			Bit_Clear(PORTA,pin);
		}
		break;
		//portB
		case portb:
		if(val==OUTPUT)
		{
			//PORTB|=(1<<pin);
			Bit_Set(PORTB,pin);
		}
		else
		{
			//PORTB&=~(1<<pin);
			Bit_Clear(PORTB,pin);
		}
		break;
		//portC
		case portc:
		if(val==OUTPUT)
		{
			//PORTC|=(1<<pin);
			Bit_Set(PORTC,pin);
		}
		else
		{
			//PORTC&=~(1<<pin);
			Bit_Clear(PORTC,pin);
		}
		break;
		//portD
		case portd:
		if(val==OUTPUT)
		{
			//PORTD|=(1<<pin);
			Bit_Set(PORTD,pin);
		}
		else
		{
			//PORTD&=~(1<<pin);
			Bit_Clear(PORTD,pin);
		}
		break;
	}
}

void DIO_TogglePin (uint8_t port,uint8_t pin)
{
	switch(port)
	{
		//portA
		case porta:
		    PORTA^=(1<<pin);
		break;
		//portB
		case portb:
		    PORTB^=(1<<pin);
		break;
		//portC
		case portc:
			PORTC^=(1<<pin);
		break;
		//portD
		case portd:
			PORTD^=(1<<pin);
		break;
	}
}

uint8_t DIO_ReadPin (uint8_t port,uint8_t pin)
{
uint8_t value=0;
	switch(port)
	{
		//portA
		case porta:
		value=((PINA&(1<<pin))>>pin);
		break;
		//portB
		case portb:
		value=((PINB&(1<<pin))>>pin);
		break;
		//portC
		case portc:
		value=((PINC&(1<<pin))>>pin);
		break;
		//portD
		case portd:
		value=((PIND&(1<<pin))>>pin);
		break;
	}
return value;
}

void DIO_SetPortDir (uint8_t port,uint8_t dir)
{
	switch(port)
	{
		//portA
		case porta:
		DDRA=dir;
		break;
		//portB
		case portb:
		DDRB=dir;
		break;
		//portC
		case portc:
		DDRC=dir;
		break;
		//portD
		case portd:
		DDRD=dir;
		break;
	}
}
void DIO_WritePort (uint8_t port,uint8_t val)
{
	switch(port)
	{

		//portA
		case porta:
		PORTA=val;
		break;
		//portB
		case portb:
		PORTB=val;
		break;
		//portC
		case portc:
		PORTC=val;
		break;
		//portD
		case portd:
		PORTD=val;
		break;
	}
}
void DIO_TogglePort (uint8_t port)
{
	switch(port)
	{
		//portA
		case porta:
		PORTA=~PORTA;
		break;
		//portB
		case portb:
		PORTB=~PORTB;
		break;
		//portC
		case portc:
		PORTC=~PORTC;
		break;
		//portD
		case portd:
		PORTD=~PORTD;
		break;
	}
}
uint8_t DIO_ReadPort (uint8_t port)
{
uint8_t value=0;
	switch(port)
	{
		//portA
		case porta:
		value=PINA;
		break;
		//portB
		case portb:
		value=PINB;
		break;
		//portC
		case portc:
		value=PINC;
		break;
		//portD
		case portd:
		value=PIND;
		break;
	}
return value;
}
void DIO_Enable_Internal_PullUp (uint8_t port,uint8_t pin)
{
	switch(port)
	{
		//portA
		case porta:
			PORTA|=(1<<pin);
		break;
		//portB
		case portb:
			PORTB|=(1<<pin);
		break;
		//portC
		case portc:
			PORTC|=(1<<pin);
		break;
		//portD
		case portd:
			PORTD|=(1<<pin);
		break;
	}
}

