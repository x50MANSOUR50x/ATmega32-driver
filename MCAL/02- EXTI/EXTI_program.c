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
#include "EXTI_registers.h"
#include "EXTI_interface.h"


void EXTI_vEnable(unsigned char EXTI_PIN)
{
	switch(EXTI_PIN)
	{
		case 0:
		Bit_Set(GICR,INT0);
		break;
		case 1:
		Bit_Set(GICR,INT1);
		break;
		case 2:
		Bit_Set(GICR,INT2);
		break;
	}
}

void EXTI_vActiveMode(unsigned char EXTI_PIN,unsigned char EXTI_MODE)
{ 
	if (EXTI_MODE == FALLING   && EXTI_PIN ==EXTI0)
	{
		Bit_Set(SREG,7);
		Bit_Set(MCUCR,ISC01);
		Bit_Clear(MCUCR,ISC00);
	}
    else if (EXTI_MODE == RISING   && EXTI_PIN ==EXTI0)
    {
		Bit_Set(SREG,7);
		Bit_Set(MCUCR,ISC01);
		Bit_Set(MCUCR,ISC00);
    }
    else if (EXTI_MODE == FALLING   && EXTI_PIN ==EXTI1)
    { 
		Bit_Set(SREG,7);
	    Bit_Set(MCUCR,ISC11);
	    Bit_Clear(MCUCR,ISC10);   
    }	
    else if (EXTI_MODE == RISING   && EXTI_PIN ==EXTI1)
    {
		Bit_Set(SREG,7);
	    Bit_Set(MCUCR,ISC10);
	    Bit_Set(MCUCR,ISC11);
    }
    else if (EXTI_MODE == FALLING   && EXTI_PIN ==EXTI2)
    {
		Bit_Set(SREG,7);
        Bit_Set(MCUCSR,ISC2);
    }
    else if (EXTI_MODE == RISING   && EXTI_PIN ==EXTI2)
    {
		Bit_Set(SREG,7);
        Bit_Clear(MCUCSR,ISC2);
    }
}

void EXTI_vDisable(unsigned char EXTI_PIN)
{
	switch(EXTI_PIN)
	{
		case 0:
		Bit_Clear(GICR,INT0);
		Bit_Clear(SREG,7);
		break;
		case 1:
		Bit_Clear(GICR,INT1);
		Bit_Clear(SREG,7);
		break;
		case 2:
		Bit_Clear(GICR,INT2);
		Bit_Clear(SREG,7);
		break;
		}
}
	
	