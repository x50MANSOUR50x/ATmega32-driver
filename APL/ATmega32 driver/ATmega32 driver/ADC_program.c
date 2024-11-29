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

#include "ADC_registers.h"
#include "ADC_interface.h"
#include "Definitions.h"
void           ADC_Init(unsigned char pin)
{
	 /*ADC_INIT*/
	Bit_Set(ADMUX,REFS0); //AVCC with external capacitor at AREF pin
	/* configure channel */
	if(pin == 0) // channel 0
	 {
		 
	 }
	 else if(pin == 1)  // channel 1
	 {
		 Bit_Set(ADMUX,MUX0); 
	 }
	 else if(pin == 2)  // channel 2
	 {
		 Bit_Set(ADMUX,MUX1); 
	 }
	 else if(pin == 3)  // channel 3
	 {
		 Bit_Set(ADMUX,MUX0); 
		 Bit_Set(ADMUX,MUX1); 
	 }
	 else if(pin == 4)  // channel 4
	 {
		 Bit_Set(ADMUX,MUX2); 
	 }
	 else if(pin == 5)  // channel 5
	 {
		 Bit_Set(ADMUX,MUX0); 
		 Bit_Set(ADMUX,MUX2); 
	 }
	 else if(pin == 6)  // channel 6
	 {
		 Bit_Set(ADMUX,MUX1);
         Bit_Set(ADMUX,MUX2); 		 
	 } 
	 else   // channel 7
	 {
		  Bit_Set(ADMUX,MUX0); 
		  Bit_Set(ADMUX,MUX1); 
		  Bit_Set(ADMUX,MUX2); 
	 }
	Bit_Set(ADCSRA,ADEN); //Enable ADC
	/*SET clock of ADC,ADPS0 default zero*/
	Bit_Set(ADCSRA,ADPS2);
	Bit_Set(ADCSRA,ADPS1);
	/*ADC_END_INIT*/
}
unsigned short ADC_Read(unsigned char pin)
{
	unsigned short read_value;
	Bit_Set(ADCSRA,ADSC); //start conversion ADC
	while(Bit_Read(ADCSRA,ADSC)==1);
	//while(Bit_Read(ADCSRA,ADIF)==0);
	//Bit_Set(ADCSRA,ADIF); //clear flag of ADC
	read_value=ADCL;
	read_value|=(ADCH<<8);
	return read_value;
}    