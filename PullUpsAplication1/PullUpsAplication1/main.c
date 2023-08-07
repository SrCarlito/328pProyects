/*
 * PullUpsAplication1.c
 *
 * Created: 07-08-2023 5:45:59
 * Author : lolsg
 */ 
#define F_CPU 20000000UL


#include <avr/io.h>
#include <avr/delay.h>




int main(void)
{
	DDRB &= ~_BV(0);  //_BV(0) -> 1 >> BIT 0;
	DDRB |= _BV(0);	//PORTB INPUT 
	PORTB = 0xFF;	//PULL-UPS<B> ON
	DDRC = 0xFF;	//PORTC OUTPUT
	PORTC = 0x00;	//???
    /* Replace with your application code */
    while (1) 
    {
			if (!(PINB & (1<<0)))
			{
				PORTC = 0x0A;
				
			}else
			{
				PORTC = 0X05;
				
			}
    }
}

