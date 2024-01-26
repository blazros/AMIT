/*
 * Dupl_7-Segments.c
 *
 * Created: 27/01/2024 12:12:20 am
 * Author : ahmed
 */ 
#define SET_BIT(REG,BIT_NUM)    REG|=(1<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM)    REG&=(~(1<<BIT_NUM))
#define TOG_BIT(REG,BIT_NUM)    REG^=(1<<BIT_NUM)
#define GET_BIT(REG,BIT_NUM)    ((REG>>BIT_NUM)&1)
#define F_CPU 16000000

#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
	/* Replace with your application code */
	int ssd[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b001100110, 0b11101101, 0b11111101, 0b00000111, 0b11111111, 0b11101111};
	int i = 0, j = 0;
	
	
	DDRB = 0b00000000;	// Input Button
	DDRC = 0b01111111;	// Output 7-Segments
	DDRD = 0b00000110;	// Output Enables En1 : D1- En2 : D2
	
	PORTD = 0b00000000;	// Both Enabled as Default
	PORTC = ssd[0];		// Prints 0 on 7-Segments as Default
	
	while (1)
	{
		if(GET_BIT(PINB,0) == 1)
		{
			if(i < 10)
			{
				CLR_BIT(PORTD,2);
				SET_BIT(PORTD,1);
				PORTC = ssd[i++];
				_delay_ms(200);
			}
			else if(i > 9)
			{
				i = 0;
				SET_BIT(PORTD,2);
				CLR_BIT(PORTD,1);
				PORTC = ssd[++j];
				_delay_ms(200);
			}
		}
	}
}

