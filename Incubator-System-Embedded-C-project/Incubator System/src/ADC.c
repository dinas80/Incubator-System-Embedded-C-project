
#include "ADC_int.h"


	 void ADC_EnableInterrupt()
	{
	
	}
	  void ADC_DisableInterrupt()
	 {
	 
	 }
 
	 void ADC_Init(ADC_ConfigData Data)
	{
		ADMUX  = Data.VoltageReference | VBG; // Set Voltage Reference and Connect the ADC H/W to GND
		ADCSRA =  (1<<ADEN) | Data.Prescaler;
	}

	 void ADC_DeInit()
	{
		ADMUX  = 0x00;
		ADCSRA = 0x00;
		ADC_DisableInterrupt();
	}

	uint16_t ADC_ReadPin(uint8_t Pin)
	{
		uint8_t Low, High;
		ADMUX = (ADMUX & ADC_VOLTAGE_REFERENCE_MASK) | Pin;
		ADCSRA |= (1<<ADSC);
		while (ADCSRA & (1<<ADSC));
		Low  = ADCL;
		High = ADCH;
		return (High<<8) | Low;
	}

	uint16_t ADC_ReadTemperature()
	{
		uint8_t Low, High;
		ADMUX = ADC_VOLTAGE_REFERENCE_IREF | ADC8;
		ADCSRA |= (1<<ADSC);
		while (ADCSRA & (1<<ADSC));
		Low  = ADCL;
		High = ADCH;
		return (((High<<8) | Low) - ADC_TEMP_TOS) / ADC_TEMP_K;
	}
