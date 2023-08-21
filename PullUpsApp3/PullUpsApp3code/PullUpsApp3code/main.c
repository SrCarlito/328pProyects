/*
 * PullUpsApp3code.c
 *
 * Created: 09-08-2023 20:21:35
 * Author : lolsg
 */ 

#include <avr/io.h>


int main(void)
{
    DDRB = 0x00;
	DDRC = 0xFF;
	
	PORTB = 0xFF;
	
	
    while (1) 
    {
		PORTC = PINB;
    }
}

