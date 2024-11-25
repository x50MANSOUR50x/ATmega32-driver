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
   
#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_



#define   ADPS0   0
#define   ADPS1   1
#define   ADPS2   2
#define   ADIE    3
#define   ADIF    4
#define   ADSC    6
#define   ADEN    7
#define   MUX0    0
#define   MUX1    1
#define   MUX2    2
#define   REFS0   6
#define   REFS1   7

        /*       REGISTERS ADDRESSES FOR ADC        */

		
// #define  ADC                  *((volatile unsigned short*)(0x0024))
#define  ADCL                 *((volatile unsigned char*)(0x0024))
#define  ADCH                 *((volatile unsigned char*)(0x0025))
#define  ADCSRA               *((volatile unsigned char*)(0x0026)) 
#define  ADMUX                *((volatile unsigned char*)(0x0027))
#endif 
