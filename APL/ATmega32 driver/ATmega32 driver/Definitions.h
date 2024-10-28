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

#ifndef DEFINITIONS_H
#define DEFINITIONS_H
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed long int32_t;
typedef unsigned long uint32_t;
#define Bit_Set(Byte,Bit) (Byte|=(1<<Bit))
#define Bit_Clear(Byte,Bit) (Byte&=~(1<<Bit))
#define Bit_Toggle(Byte,Bit) (Byte^=(1<<Bit))
#define Bit_Read(Byte,Bit) ((Byte&(1<<Bit))>>Bit)
#define False 0
#define True 1
#define Limit(Value,Min,Max) ((Value<Min)?Min:((Value>Max)?Max:Value))
#define Difference_Between(A,B) ((A>B)?(A-B):(B-A))
#define Absolute(A) ((A>0.0)?(A):(0.0-A))
#define Round(Value,Type) ((Type)(Value+0.5))
#endif
