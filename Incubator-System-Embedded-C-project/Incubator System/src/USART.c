
#define F_CPU 16000000UL // Defining the CPU Frequency
#include "std_macros.h"
#include "Datatypes.h"
#include <avr/io.h>      // Contains all the I/O Register Macros
#include <util/delay.h>  // Generates a Blocking Delay
#include "USART.h"

void USART_Init()
{
	// Set Baud Rate
	UBRR0H = BAUD_PRESCALER >> 8;
	UBRR0L = BAUD_PRESCALER;
	
	// Set Frame Format
	UCSR0C = (3<<UCSZ00);
	
	// Enable Receiver and Transmitter
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
}

void USART_TransmitChar(u8 DataByte)
{
while (( UCSR0A & (1<<UDRE0)) == 0); // Do nothing until UDR is ready
UDR0 = DataByte;
}

u8 USART_ReceiveChar(void)
{
	/*Wait for UDR receive buffer to be filled with data*/
	while(READ_BIT(UCSR0A,RXC0)==0);
	/*Receive data from UDR receive buffer*/
	return UDR0 ;
}

void USART_SendString(u8 *ptr)
{
	while(*ptr!=255)
	{
	USART_TransmitChar(*ptr);
		ptr++;
		_delay_ms(100);
	}
}

void UART_getLine(char* buf, uint8_t n)
{
	uint8_t bufIdx = 0;
	char c;

	// while received character is not carriage return
	// and end of buffer has not been reached
	do
	{
		// receive character
		c = USART_ReceiveChar();

		// store character in buffer
		buf[bufIdx++] = c;
	}
	while((bufIdx < n) && (c != '!'));

	// ensure buffer is null terminated
	
}

void UART_puts(char* s)
{
	// transmit character until NULL is reached
	while(*s > 0) USART_TransmitChar(*s++);
}