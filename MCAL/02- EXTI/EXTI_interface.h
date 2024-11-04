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

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void EXTI_vEnable(unsigned char EXTI_PIN);
void EXTI_vActiveMode(unsigned char EXTI_PIN,unsigned char EXTI_MODE);
void EXTI_vDisable(unsigned char EXTI_PIN);

// Bits of GICR to configure which external interrupt pins active
#define  EXTI0                    0
#define  EXTI1                    1
#define  EXTI2                    2

// Modes of the external interrupts
      // The falling edge of the interrupt pin generates an interrupt request. 1 -> 0
#define  FALLING                  0
      // The rising  edge of the interrupt pin generates an interrupt request. 0 -> 1
#define  RISING                   1
      // The low level of the interrupt pin generates an interrupt request. 0
#define  LOW                      2
      // Any logical change on the interrupt pin generates an interrupt request. 0 -> 1 or 1 -> 0
#define  CHANGE                   3

#endif /* EXTI_INTERFACE_H_ */