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

#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_
void BUTTON_Init(unsigned char port,unsigned char pin);
unsigned char BUTTON_Read(unsigned char port,unsigned char pin);
void BUTTON_Enable_Internal_PullUp(unsigned char port,unsigned char pin);
#define porta   'A'
#define portb   'B'
#define portc   'C'
#define portd   'D'
#define HIGH     1
#define LOW      0
#define pin0     0
#define pin1     1
#define pin2     2
#define pin3     3
#define pin4     4
#define pin5     5
#define pin6     6
#define pin7     7
#define OUTPUT 1
#define INPUT 0
#endif /* BUTTON_INTERFACE_H_ */