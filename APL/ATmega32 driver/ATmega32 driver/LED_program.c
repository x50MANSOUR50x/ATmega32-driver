/**********************************************************************************************/
/* Author       : Ammar                                                   */
/* Date         : 31/7/2021 02:14:30 PM                                                       */
/* version      : 01                                                                          */
/**********************************************************************************************/
#include "DIO_interface.h"
#include "Definitions.h"
void LED_Init(uint8_t port,uint8_t pin)
{
	DIO_SetPinDir(port,pin,OUTPUT);
}
void LED_On(uint8_t port,uint8_t pin)
{
	DIO_WritePin(port,pin,1);
}
void LED_Off(uint8_t port,uint8_t pin)
{
	DIO_WritePin(port,pin,0);
}
void LED_Toggle(uint8_t port,uint8_t pin)
{
	DIO_TogglePin(port,pin);
}
uint8_t LED_ReadStatus(uint8_t port,uint8_t pin)
{
	uint8_t led_status;
	led_status=DIO_ReadPin(port,pin);
	return led_status;
}
