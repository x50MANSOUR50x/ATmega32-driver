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

#include "DIO_interface.h"
#include "BUTTON_interface.h"
void BUTTON_Init(unsigned char port,unsigned char pin)
{
	DIO_SetPinDir(port,pin,0);
}
unsigned char BUTTON_Read(unsigned char port,unsigned char pin)
{
	unsigned char x;
	x= DIO_ReadPin(port,pin);
	return x;
}
void BUTTON_Enable_Internal_PullUp(unsigned char port,unsigned char pin)
{
	DIO_Enable_Internal_PullUp(port,pin);
}
