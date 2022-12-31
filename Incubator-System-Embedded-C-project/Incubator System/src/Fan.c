/*
 * Fan.c
 *
 * Created: 23/12/2022 20:28:03
 *  Author: Dina
 */ 

#include "Fan.h"

void Fan_Init()
{
	PWM_init();
}

void Fan_On_Automatic()
{
	PWM_setDutyCycle(200);
}
void Fan_On_Manual(u8 speed)
{
	PWM_setDutyCycle(speed);
}
void Fan_Off()
{
	PWM_setDutyCycle(0);
}
