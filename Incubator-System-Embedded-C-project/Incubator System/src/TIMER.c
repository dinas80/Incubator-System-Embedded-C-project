/*
 * TIMER.c
 *
 * Created: 21/12/2022 15:02:03
 *  Author: Dina
 */ 
#include "TIMER.h"
#include "DIO.h"
#include "std_macros.h"
#include "Datatypes.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

 void PWM_init()
	{
		DIO_vsetPINDir('B',3,1);
		TCCR2A |= (1<<COM2A1) | (1<<WGM21) | (1<<WGM20);	//Non-Inverting Fast PWM mode 3 using OCR A unit
		TCCR2B |= (1<<CS20);	//No-Prescalar
	}



void PWM_setDutyCycle(u8 dutyCycle)
	{
		OCR2A = dutyCycle;	// Duty cycle of 75%
		
	}


	

