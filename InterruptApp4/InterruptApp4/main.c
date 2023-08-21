/*
 * InterruptApp4.c
 *
 * Created: 16-08-2023 11:03:03
 * Author : lolsg
 */ 

#define F_CPU 4000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include <avr/>



int delay = 20;


int main(void)
{
	cli();
	
	DDRD = 0x00;
	DDRB = 0xff;
	
	PORTD = 0xff; //Pull ups on;
	
	PCICR = (1<<PCIE2);	//
	PCMSK2 = (1<<PCINT16)|(1<<PCINT18); //Habilita interrupciones PCINTX
	
	sei();
	
    while (1) 
    {
		PORTB |= (1<<PINB0);
		_delay_ms(20);
		PORTB &= ~(1<<PINB0)  ;
		_delay_ms(100);
    }
}

ISR(PCINT0_vect){
	
	PORTB |= (1<<PINB1);
	_delay_ms(300);
	PORTB &= ~(1<<PINB1);
	
}
