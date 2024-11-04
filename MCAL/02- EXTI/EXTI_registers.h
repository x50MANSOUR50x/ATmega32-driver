/**********************************************************************************************/
/*                                                                                            */
/*  Author       : Mansour                                                                    */
/*  Last Updated : 4/11/2024, 11:39 AM                                                        */
/*  Version      : 1.0                                                                        */
/*  Description  : interface                                                                  */
/*                                                                                            */
/*  Changelog    :                                                                            */
/*     - v1.1 (4/11/2024): Modifies the file to make the interupts 0 and 1 uses all           */
/* 						   of its mode not only rising and falling.               */
/**********************************************************************************************/


   
#ifndef EXTI_REGISTERS_H_
#define EXTI_REGISTERS_H_
        /*       REGISTERS ADDRESSES FOR EXTI        */
      // Status Register
#define  SREG                   *((volatile unsigned char*)(0x005F)) 
      // General Interrupt Control Register
#define  GICR                   *((volatile unsigned char*)(0x005B))
      // General Interrupt Flag Register
#define  GIFR                   *((volatile unsigned char*)(0x005A))
      // Microcontroller Unit Control Register
#define  MCUCR                  *((volatile unsigned char*)(0x0055))
      // Microcontroller Unit Control and Status Register
#define  MCUCSR                 *((volatile unsigned char*)(0x0054))

// Bits of GICR to configure which external interrupt pins active
#define  INT0                    6
#define  INT1                    7
#define  INT2                    5

// Bits of MCUCR,MCUCSR to configure Modes of external Interrupt
#define  ISC00                   0
#define  ISC01                   1
#define  ISC10                   2
#define  ISC11                   3
#define  ISC2                    6

     // Global Interrupt Enable
#define GIE 7 // bit 7 in the status register

#endif /*EXTI_REGISTERS_H_*/
