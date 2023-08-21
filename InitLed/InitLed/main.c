/*
 * InitLed.c
 *
 * Created: 10-08-2023 7:05:18
 * Author : lolsg
 */ 

#include <avr/io.h>


int main(void)
{
		
	DDRD = 0x00;
	PORTD = 0xFF;
	
	DDRB = 0xFF;
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB = PIND ;
    }
}

