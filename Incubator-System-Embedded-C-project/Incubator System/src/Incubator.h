/*
 * Incubator.h
 *
 * Created: 24/12/2022 02:28:39
 *  Author: Dina
 */ 


#ifndef INCUBATOR_H_
#define INCUBATOR_H_
#define F_CPU 16000000UL
#include <util/delay.h>


#include "Datatypes.h"
#include "DIO.h"
#include "LM35.h"
#include "USART.h"

#include "LCD.h"
#include "TIMER.h"
#include "Fan.h"

#include "Relay.h"


char start_bit;
u8 read_temperature;
char Minimum_temp;
char Minimum_temp_1;
char Maximum_temp;
char Maximum_temp_1;
char Mode;
char Fan_state;
char Lamp_state;
char Fan_speed;
char Fan_speed_1;
char end_bit;
u8 Fan_speed_u8;
u8 u8_Maximum_temp;
u8 u8_Minimum_temp;
char buf[10];
char temp;

void Data_recieveing (void);
void Automatic_mode(void);
void Manual_mode(void);
void Mode_select(void);
void System_init(void);
void System_main_function(void);




#endif /* INCUBATOR_H_ */