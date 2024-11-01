
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

/*
 segment a:pin0
 segment b:pin1
 segment c:pin2
 segment d:pin3
 segment e:pin4
 segment f:pin5
 segment g:pin6  
        
	     	g f com a b
 
               a
           ---------- 
		   -        -    
	   f   -        -  b
		   -----g-----
		   -        -
	    e  -        -  c
		   ---------- 
		      d
			  
		  e d com c p
*/
#include "DIO_interface.h"
#include "7SEGMENT_interface.h"
#include "7SEGMENT_private.h"

void SEVEN_SEG_Init(unsigned char port)
{
	DIO_SetPortDir(port,0xff);
}
											              // 0 for the first 4 pins and 1 for the last 4 pins
void BCD_to_SEVEN_SEG_Init(unsigned char port, unsigned char half)
{

	if(half == 0)
	{
		DIO_SetPinDir(port, pin0, OUTPUT);
		DIO_SetPinDir(port, pin1, OUTPUT);
		DIO_SetPinDir(port, pin2, OUTPUT);
		DIO_SetPinDir(port, pin3, OUTPUT);
	}
	else if(half == 1)
	{
		DIO_SetPinDir(port, pin4, OUTPUT);
		DIO_SetPinDir(port, pin5, OUTPUT);
		DIO_SetPinDir(port, pin6, OUTPUT);
		DIO_SetPinDir(port, pin7, OUTPUT);
	}
	
}

void SEVEN_SEG_Write(unsigned char port,unsigned char value)  
{
	#if defined CC
	unsigned char seven_seg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
		DIO_WritePort(port,seven_seg[value]);
	#endif		
    #if defined CA
	unsigned char seven_seg[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x0d,~0x47,~0x7f,~0x6f};
		DIO_WritePort(port,seven_seg[value]);
	#endif	
	
}

void SEVEN_SEG_Blink(unsigned char port)  
{
	    #if defined CC
		DIO_WritePort(port,0x08);
		#endif
		#if defined CA
		DIO_WritePort(port,~0x08);
		#endif
}

void BCD_to_SEVEN_SEG_Write(unsigned char port, unsigned char half, unsigned char value)
{
	if(half == 0)
	{
		switch (value)
		{
		case 0:
			DIO_WritePin(port, pin0, 0);
			DIO_WritePin(port, pin1, 0);
			DIO_WritePin(port, pin2, 0);
			DIO_WritePin(port, pin3, 0);
			break;
		case 1:
			DIO_WritePin(port, pin0, 1);
			DIO_WritePin(port, pin1, 0);
			DIO_WritePin(port, pin2, 0);
			DIO_WritePin(port, pin3, 0);
			break;
		case 2:
			DIO_WritePin(port, pin0, 0);
			DIO_WritePin(port, pin1, 1);
			DIO_WritePin(port, pin2, 0);
			DIO_WritePin(port, pin3, 0);
			break;
		case 3:
			DIO_WritePin(port, pin0, 1);
			DIO_WritePin(port, pin1, 1);
			DIO_WritePin(port, pin2, 0);
			DIO_WritePin(port, pin3, 0);
			break;
		case 4:
			DIO_WritePin(port, pin0, 0);
			DIO_WritePin(port, pin1, 0);
			DIO_WritePin(port, pin2, 1);
			DIO_WritePin(port, pin3, 0);
			break;
		case 5:
			DIO_WritePin(port, pin0, 1);
			DIO_WritePin(port, pin1, 0);
			DIO_WritePin(port, pin2, 1);
			DIO_WritePin(port, pin3, 0);
			break;
		case 6:
			DIO_WritePin(port, pin0, 0);
			DIO_WritePin(port, pin1, 1);
			DIO_WritePin(port, pin2, 1);
			DIO_WritePin(port, pin3, 0);
			break;
		case 7:
			DIO_WritePin(port, pin0, 1);
			DIO_WritePin(port, pin1, 1);
			DIO_WritePin(port, pin2, 1);
			DIO_WritePin(port, pin3, 0);
			break;
		case 8:
			DIO_WritePin(port, pin0, 0);
			DIO_WritePin(port, pin1, 0);
			DIO_WritePin(port, pin2, 0);
			DIO_WritePin(port, pin3, 1);
			break;
		case 9:
			DIO_WritePin(port, pin0, 1);
			DIO_WritePin(port, pin1, 0);
			DIO_WritePin(port, pin2, 0);
			DIO_WritePin(port, pin3, 1);
			break;
		default:
			break;
		}
	}
	else if(half == 1)
	{
		switch (value)
			{
			case 0:
				DIO_WritePin(port, pin4, 0);
				DIO_WritePin(port, pin5, 0);
				DIO_WritePin(port, pin6, 0);
				DIO_WritePin(port, pin7, 0);
				break;
			case 1:
				DIO_WritePin(port, pin4, 1);
				DIO_WritePin(port, pin5, 0);
				DIO_WritePin(port, pin6, 0);
				DIO_WritePin(port, pin7, 0);
				break;
			case 2:
				DIO_WritePin(port, pin4, 0);
				DIO_WritePin(port, pin5, 1);
				DIO_WritePin(port, pin6, 0);
				DIO_WritePin(port, pin7, 0);
				break;
			case 3:
				DIO_WritePin(port, pin4, 1);
				DIO_WritePin(port, pin5, 1);
				DIO_WritePin(port, pin6, 0);
				DIO_WritePin(port, pin7, 0);
				break;
			case 4:
				DIO_WritePin(port, pin4, 0);
				DIO_WritePin(port, pin5, 0);
				DIO_WritePin(port, pin6, 1);
				DIO_WritePin(port, pin7, 0);
				break;
			case 5:
				DIO_WritePin(port, pin4, 1);
				DIO_WritePin(port, pin5, 0);
				DIO_WritePin(port, pin6, 1);
				DIO_WritePin(port, pin7, 0);
				break;
			case 6:
				DIO_WritePin(port, pin4, 0);
				DIO_WritePin(port, pin5, 1);
				DIO_WritePin(port, pin6, 1);
				DIO_WritePin(port, pin7, 0);
				break;
			case 7:
				DIO_WritePin(port, pin4, 1);
				DIO_WritePin(port, pin5, 1);
				DIO_WritePin(port, pin6, 1);
				DIO_WritePin(port, pin7, 0);
				break;
			case 8:
				DIO_WritePin(port, pin4, 0);
				DIO_WritePin(port, pin5, 0);
				DIO_WritePin(port, pin6, 0);
				DIO_WritePin(port, pin7, 1);
				break;
			case 9:
				DIO_WritePin(port, pin4, 1);
				DIO_WritePin(port, pin5, 0);
				DIO_WritePin(port, pin6, 0);
				DIO_WritePin(port, pin7, 1);
				break;
			default:
				break;
			}
	}
}