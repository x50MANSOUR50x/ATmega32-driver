/**********************************************************************************************/
/*                                                                                            */
/*  Author       : Mansour                                                                    */
/*  Last Updated : 4/11/2024, 11:39 AM                                                        */
/*  Version      : 1.0                                                                        */
/*  Description  : interface                                                                  */
/*                                                                                            */
/*  Changelog    :                                                                            */
/*     - v1.1 (4/11/2024): Modifies the file to make the interupts 0 and 1 uses all           */
/* 						   of its mode not only rising and falling.                           */
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

// Mode 	ISC01 ISC00  (The first number is for The 0 in EXTI0)
// LOW  	0     0		
// CHANGE   0     1		
// FALLING  1     0		
// RISING   1     1		

// Mode 	ISC11 ISC10  (The first number is for The 1 in EXTI1)
// LOW  	0     0		
// CHANGE   0     1		
// FALLING  1     0		
// RISING   1     1		

// Mode 	ISC2 (For EXTI2)
// FALLING  1	
// RISING   0     	

void EXTI_vActiveMode(unsigned char EXTI_PIN,unsigned char EXTI_MODE)
{ 

	switch (EXTI_PIN)
	{
	case EXTI0:
		switch (EXTI_MODE)
		{
			case LOW:
				Bit_Set(SREG, GIE);
				Bit_Clear(MCUCR, ISC00);
				Bit_Clear(MCUCR, ISC01);
				break;
			case CHANGE:
				Bit_Set(SREG, GIE);
				Bit_Set(MCUCR, ISC00);
				Bit_Clear(MCUCR, ISC01);
				break;
			case FALLING:
				Bit_Set(SREG, GIE);
				Bit_Clear(MCUCR, ISC00);
				Bit_Set(MCUCR, ISC01);
				break;
			case RISING:
				Bit_Set(SREG, GIE);
				Bit_Set(MCUCR, ISC00);
				Bit_Set(MCUCR, ISC01);
				break;
			default:
				break;
		}
		break;
	case EXTI1:
		switch (EXTI_MODE)
		{
			case LOW:
				Bit_Set(SREG, GIE);
				Bit_Clear(MCUCR, ISC10);
				Bit_Clear(MCUCR, ISC11);
				break;
			case CHANGE:
				Bit_Set(SREG, GIE);
				Bit_Set(MCUCR, ISC10);
				Bit_Clear(MCUCR, ISC11);
				break;
			case FALLING:
				Bit_Set(SREG, GIE);
				Bit_Clear(MCUCR, ISC10);
				Bit_Set(MCUCR, ISC11);
				break;
			case RISING:
				Bit_Set(SREG, GIE);
				Bit_Set(MCUCR, ISC10);
				Bit_Set(MCUCR, ISC11);
				break;
			default:
				break;
		}
		break;
	case EXTI2:
		switch (EXTI_MODE)
		{
			case FALLING:
				Bit_Set(SREG, GIE);
				Bit_Set(MCUCSR, ISC2);
				break;
			case RISING:
				Bit_Set(SREG, GIE);
				Bit_Clear(MCUCSR, ISC2);
				break;
			default:
				break;
		}
		break;
	default:
		break;
	}



	/*
	if (EXTI_MODE == FALLING   && EXTI_PIN ==EXTI0)
	{
		Bit_Set(SREG, GIE);
		Bit_Clear(MCUCR, ISC00);
		Bit_Set(MCUCR, ISC01);
	}
    else if (EXTI_MODE == RISING   && EXTI_PIN ==EXTI0)
    {
		Bit_Set(SREG,7);
		Bit_Set(MCUCR,ISC00);
		Bit_Set(MCUCR,ISC01);
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
	*/
}

void EXTI_vDisable(unsigned char EXTI_PIN)
{
	Bit_Clear(SREG,GIE);
	switch(EXTI_PIN)
	{
		case 0:
		Bit_Clear(GICR,INT0);
		break;
		case 1:
		Bit_Clear(GICR,INT1);
		break;
		case 2:
		Bit_Clear(GICR,INT2);
		break;
		}
}
	
	