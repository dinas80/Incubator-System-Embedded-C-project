#ifndef USART_H
#define USART_H
#include "Datatypes.h"



#define USART_BAUDRATE 9600 // Desired Baud Rate
#define BAUD_PRESCALER (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void USART_Init();
void USART_TransmitChar(u8 DataByte);
void USART_SendString( u8 *ptr);
u8 USART_ReceiveChar(void);
#endif // MYUART_H_INCLUDED