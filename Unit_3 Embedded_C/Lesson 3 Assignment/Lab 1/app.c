#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth:HERP" ;
unsigned char const string_buffer2[100] = "learn-in-depth:HERP" ;
unsigned char const string_buffer3[100] = "learn-in-depth:HERP" ;

void main(void)
{
	Uart_Send_string (string_buffer);
}