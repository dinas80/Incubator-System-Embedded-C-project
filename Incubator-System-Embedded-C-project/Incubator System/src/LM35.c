/*
 * LM35.c
 *
 * Created: 23/12/2022 20:34:16
 *  Author: Dina
 */ 

#include "LM35.h"

	u16 AdcValue=0;
	volatile u16 temperature =0 ;
	volatile u8 val =0 ;
	volatile u8 H=0;
	volatile u8 T=0;
	volatile u8 U=0;

void LM35_Init()
{
	
		/* ADC Configuration and Init */
		ADC_ConfigData ADC_Data;
		ADC_Data.Prescaler = ADC_PRESCALER_128;
		ADC_Data.VoltageReference = ADC_VOLTAGE_REFERENCE_AVCC;
		ADC_Init(ADC_Data);
}

u8 get_reading()
{
	   AdcValue =  ADC_ReadPin(ADC0);
	   temperature=((u16) AdcValue/2.2);
	   U = temperature%10;
	   val=(u8)( (temperature )/10);
	   T = val%10;
	   val =(u8) val/10;
	   H= val%10;
	    LCD_movecursor(0,0);
	    LCD_vSend_char ((T)+48);
	    LCD_movecursor(1,2);
	    LCD_vSend_char((U)+48);
		transmit_buf[2] = T+48;
		transmit_buf[3] = U+48;
		transmit_buf[4]= 255 ;
	   return temperature;
}


	 
	    
	   
	    