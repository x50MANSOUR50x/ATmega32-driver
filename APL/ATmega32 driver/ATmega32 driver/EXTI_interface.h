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

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
void EXTI_vEnable(unsigned char EXTI_PIN);
void EXTI_vActiveMode(unsigned char EXTI_PIN,unsigned char EXTI_MODE);
void EXTI_vDisable(unsigned char EXTI_PIN);
// Bits of GICR to configure which external interrupt pins active
#define  EXTI0                    0
#define  EXTI1                    1
#define  EXTI2                    2
#define  FALLING                  0
#define  RISING                   1
#endif /* EXTI_INTERFACE_H_ */
