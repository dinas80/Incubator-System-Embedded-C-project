/*
 * Fan.h
 *
 * Created: 23/12/2022 20:28:19
 *  Author: Dina
 */ 


#ifndef FAN_H_
#define FAN_H_

#include "TIMER.h"
void Fan_Init();
void Fan_On_Automatic();
void Fan_On_Manual(u8 speed);
void Fan_Off();




#endif /* FAN_H_ */