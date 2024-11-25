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

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#define   A0      0
#define   A1      1
#define   A2      2
#define   A3      3
#define   A4      4
#define   A5      5
#define   A6      6
#define   A7      7
void           ADC_Init(unsigned char pin);
unsigned short ADC_Read(unsigned char pin);
#endif /* ADC_INTERFACE_H_ */