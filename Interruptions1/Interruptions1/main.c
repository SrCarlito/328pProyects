/*
 * Interruptions1.c
 *
 * Created: 12-08-2023 9:09:31
 * Author : lolsg
 */ 

#define F_CPU 4000000
#include <avr/io.h>
#include <avr/interrupt.h>


//***********Crear sistemas de botones par aumentar o disminuir la velocidad de parpadeo de un LED**************

int main(void)
{
	cli(); //Deshabilita interrupciones globales
	
	EICRA = (1<<2);
	EIMSK = (1<<1);
	
	DDRB = (1<<DDB0);
	DDRD = ~(1<<DDD3);
	PORTD = ~(1<<PORTD3);
	
	
	
	sei(); //Habilita interrupciones globales
    /* Replace with your application code */
	
    while (1) 
    {}
	
}

ISR(INT1_vect)
{
	
	PORTB ^= (1<<PINB0);
	
}



