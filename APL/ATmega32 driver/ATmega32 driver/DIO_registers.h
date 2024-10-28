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

#ifndef REGISTERS_H
#define REGISTERS_H
#define Register_At_Address(Address) (*((volatile uint8_t*)(Address)))

//AVR Status Register
#define SREG	Register_At_Address(0x5F)//Status Register  


//GPIO Port A
#define PINA	Register_At_Address(0x39)//Port D Input Pins Register //39
#define DDRA	Register_At_Address(0x3A)//Port D Data Direction Register//3A
#define PORTA	Register_At_Address(0x3B)//Port D Data Register //3B

//GPIO Port B
#define PINB	Register_At_Address(0x36)//Port B Input Pins Register
#define DDRB	Register_At_Address(0x37)//Port B Data Direction Register
#define PORTB	Register_At_Address(0x38)//Port B Data Register
//GPIO Port C
#define PINC	Register_At_Address(0x33)//Port C Input Pins Register
#define DDRC	Register_At_Address(0x34)//Port C Data Direction Register
#define PORTC	Register_At_Address(0x35)//Port C Data Register
//GPIO Port D
#define PIND	Register_At_Address(0x30)//Port D Input Pins Register
#define DDRD	Register_At_Address(0x31)//Port D Data Direction Register
#define PORTD	Register_At_Address(0x32)//Port D Data Register

#endif
