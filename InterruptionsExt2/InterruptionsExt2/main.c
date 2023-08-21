/*
 * InterruptionsExt2.c
 *
 * Created: 14-08-2023 7:19:18
 * Author : lolsg
 */ 
#define F_CPU 1000000

#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int retardo = 1000;

void function_retardo();

int main(void)
{
    cli();
	
	EICRA = (1<<ISC11); 
	EIMSK = 0X03;
	
	DDRB = 0xff;
	DDRD = 0x00;
	PORTD = (1<<PORTD2)|(1<<PORTD3);
	
	sei();

    while (1) {
		for(int x = 0; x <256; x++)
		{
			PORTB = x;
			function_retardo();
			
		}
    }
}

ISR(INT0_vect){
	retardo = retardo +50;
}

ISR(INT1_vect){
	retardo = retardo-50;
}



void function_retardo(){
	for(int a = retardo; a <=2000;a++){
		_delay_ms(1);
	}
}

