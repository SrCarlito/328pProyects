/*
 * PullUpsAplication2.c
 *
 * Created: 07-08-2023 6:43:37
 * Author : lolsg
 */ 

#include <avr/io.h>
#include <avr/delay.h>


int main(void)
{
	DDRB |= (1<<DDB0);
	DDRC |= (1<<DDC0);
	DDRD &= ~(1<<DDD7);
	PORTD = (1 << 7);

    while (1) 
    {
		PORTB |= (1<<PORTB0);
		_delay_ms(100);
		PORTB &=~ (1<<PORTB0);
		_delay_ms(100);
		
		if(PIND & (1<<PORTD7))
		{
			PORTC |= (1<<PORTC0);
		}
		else
		{
			PORTC &=~ (1<<PORTC0);	
		}	
    }
}

