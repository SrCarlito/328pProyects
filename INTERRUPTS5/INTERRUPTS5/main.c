/*
 * INTERRUPTS5.c
 *
 * Created: 19-08-2023 7:26:30
 * Author : lolsg
 */ 


#define F_CPU 1000000


#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

void Luz_verde();
void Intermitencia_verde();
void Luz_ambar();
void Luz_roja();


int main(void)
{
	cli();
	
	PCICR = (1<<PCIE0);
	PCMSK0 = (1<<PCINT4)|(1<<PCINT5);
	
	DDRD = 0x00;
	DDRB = 0xff;
	PORTB = 0xff;
	sei();
    while (1) 
    {
		
		Luz_verde();
		Intermitencia_verde();
		Luz_ambar();
		Luz_roja();
		
    }
}

void Luz_verde(){
	PORTD = (1<<PIND0);
	_delay_ms(7000);
	PORTD = 0x00;
}

void Intermitencia_verde()
{
	int i = 5;
	while(i>0){
		PORTD = (1<<PIND0);
		_delay_ms(500);
		PORTD = 0x00;
		_delay_ms(500);
		i++;
	}

	
	
}

void Luz_ambar(){
	PORTD = (1<<PIND1);
	_delay_ms(3000);
	PORTD = 0x00;
	
}

void Luz_roja(){
	
	PORTD = (1<<PIND2);
	_delay_ms(5000);
	PORTD = 0x00;
	
}

ISR(PCINT0_vect){
	
	PORTD = (1<<PIND3);
	_delay_ms(1000);
	PORTD = 0x00;
	
}

ISR(PCINT2_vect){
	PORTD = (1<<PIND4);
	_delay_ms(1000);
	PORTD = 0x00;
	
}
