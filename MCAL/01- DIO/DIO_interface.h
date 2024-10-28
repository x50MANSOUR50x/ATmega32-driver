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

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
void DIO_SetPinDir (unsigned char port,unsigned char pin, unsigned char dir);
void DIO_WritePin (unsigned char port,unsigned char pin, unsigned char val);
void DIO_TogglePin (unsigned char port,unsigned char pin);
unsigned char DIO_ReadPin (unsigned char port,unsigned char pin);
void DIO_SetPortDir (unsigned char port,unsigned char dir);
void DIO_WritePort (unsigned char port,unsigned char val);
void DIO_TogglePort (unsigned char port);
unsigned char DIO_ReadPort (unsigned char port);
void DIO_Enable_Internal_PullUp (unsigned char port,unsigned char pin);
#define porta   'A'
#define portb   'B'
#define portc   'C'
#define portd   'D'
#define HIGH     1
#define LOW      0
enum port{pin0,pin1,pin2,pin3,pin4,pin5,pin6,pin7};
#define OUTPUT 1
#define INPUT 0

#endif /* DIO_INTERFACE_H_ */