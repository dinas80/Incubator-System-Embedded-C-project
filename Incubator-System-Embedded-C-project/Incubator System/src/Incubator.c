/*
 * Incubator.c
 *
 * Created: 24/12/2022 02:28:56
 *  Author: Dina
 */ 
#include "Incubator.h"
#include <stdio.h> 

void Data_recieveing (void)
{

	UART_getLine(buf, 10);
	start_bit = buf[0];
	
	if (start_bit == '@')
	{   Mode = buf[1]; 
	    Minimum_temp = buf[2]; Minimum_temp_1 = buf[3]; 
	    Maximum_temp = buf[4]; Maximum_temp_1 = buf[5]; 
	    Fan_state = buf[6]; 
	    Lamp_state = buf[7];
	    Fan_speed = buf[8]; Fan_speed_1 = buf[9];
		for(u8 i=0;i<=9;i++){buf[i]=0;}
        u8_Minimum_temp = ((u8)Minimum_temp)+((((u8)Minimum_temp_1)*10));
		u8_Maximum_temp = ((u8)Maximum_temp)+((((u8)Maximum_temp_1)*10));
		Fan_speed_u8 =  (((u8)(Fan_speed))+(u8)((Fan_speed_1)*10));
	    _delay_ms(500);
		LCD_clearscreen();
				
		
		}
	
}

void Automatic_mode()
{
	read_temperature = get_reading();
	while (read_temperature < u8_Minimum_temp)
	{
		read_temperature = get_reading();
		LCD_vSend_string(" C, LOW TEMP ");
		temp = (char)read_temperature;
	    transmit_buf[0] = 'L';
		transmit_buf[1]='_';
	    USART_SendString(transmit_buf);
		Relay_On();
		_delay_ms(1000);
		if(buf[0]=='@')break;
	}
		Relay_Off();
	while (read_temperature > u8_Maximum_temp)
	{
		read_temperature = get_reading();
		LCD_vSend_string(" C, HIGH TEMP ");
		temp = (char)read_temperature;
		transmit_buf[0] ='H';
		transmit_buf[1] = '_';
 	USART_SendString(transmit_buf);
		Fan_On_Automatic();
			_delay_ms(1000);
			if(buf[0]=='@')break;
	}
	Fan_Off();
	LCD_vSend_string(" C, OKAY ");
		temp = (char)read_temperature;
		transmit_buf[0] = 'O';
		transmit_buf[1]='_';
		USART_SendString(transmit_buf);
	_delay_ms(1000);

}

void Manual_mode()
{
	read_temperature = get_reading();
	if (read_temperature < u8_Minimum_temp)
	{
		read_temperature = get_reading();
		LCD_vSend_string(" C, LOW TEMP ");
				temp = (char)read_temperature;
				transmit_buf[0] = 'L';
				transmit_buf[1]='_';
			USART_SendString(transmit_buf);
	}
	else if (read_temperature > u8_Maximum_temp)
	{
		read_temperature = get_reading();
		LCD_vSend_string(" C, HIGH TEMP ");
				temp = (char)read_temperature;
			    transmit_buf[0] = 'H';
			    transmit_buf[1]='_';
                USART_SendString(transmit_buf);
	}
	else {
	LCD_vSend_string(" C, OKAY ");
			temp = (char)read_temperature;
			transmit_buf[0] = 'O';
			transmit_buf[1]='_';
			USART_SendString(transmit_buf);}
	
	if (Fan_state == 'Y'&& Lamp_state == 'Y' )
	{
		Fan_On_Manual(Fan_speed_u8);
			Relay_On();
	}
	else if (Fan_state == 'Y'&& Lamp_state == 'N')
	{
		Fan_On_Manual(Fan_speed_u8);
		Relay_Off();
	
	}
	else if (Fan_state == 'N'&& Lamp_state == 'Y')
	{
		Fan_Off();
		Relay_On();
	}
	else if (Fan_state == 'N'&& Lamp_state == 'N')
	{
		Fan_Off();
		Relay_Off();
	}
	
}

void Mode_select()
{
	switch (Mode)
	{
		case 'A': Automatic_mode();
		case 'M': Manual_mode();
	}
}

void System_init()
{
	
		LCD_vInit();
		LM35_Init();
		USART_Init();
		Fan_Init();
		Relay_Init();
		LCD_movecursor(0,0);
		LCD_vSend_string("WELCOME TO INC.");
		LCD_movecursor(2,2);
		LCD_vSend_string("SYS.");
		_delay_ms(3000);
		LCD_clearscreen();

}

void System_main_function(void)
{
	
			Data_recieveing();
			Mode_select();
}