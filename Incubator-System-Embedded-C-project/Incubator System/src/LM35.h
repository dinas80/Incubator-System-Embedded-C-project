/*
 * LM35.h
 *
 * Created: 23/12/2022 20:34:30
 *  Author: Dina
 */ 



#ifndef LM35_H_
#define LM35_H_

#include "ADC_int.h"
#include "Datatypes.h"


  char transmit_buf[5];


  u8 get_reading(void);
  void LM35_Init(void);


#endif /* LM35_H_ */