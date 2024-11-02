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


   
#ifndef EXTI_REGISTERS_H_
#define EXTI_REGISTERS_H_
        /*       REGISTERS ADDRESSES FOR EXTI        */
#define  SREG                   *((volatile unsigned char*)(0x005F)) 
#define  GICR                   *((volatile unsigned char*)(0x005B))
#define  GIFR                   *((volatile unsigned char*)(0x005A))
#define  MCUCR                  *((volatile unsigned char*)(0x0055))
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

#endif 
