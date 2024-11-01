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

#ifndef SEVEN_SEG_INTERFACE_H_
#define SEVEN_SEG_INTERFACE_H_

void SEVEN_SEG_Init(unsigned char port);
void SEVEN_SEG_Write(unsigned char port,unsigned char value);
void SEVEN_SEG_Blink(unsigned char port);
void BCD_to_SEVEN_SEG_Init(unsigned char port, unsigned char half);
void BCD_to_SEVEN_SEG_Write(unsigned char port, unsigned char half, unsigned char value);


#define porta   'A'
#define portb   'B'
#define portc   'C'
#define portd   'D'

#endif /* SEVEN_SEG_INTERFACE_H_ */ 