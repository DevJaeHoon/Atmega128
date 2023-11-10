/*
 * LED.c
 *
 * Created: 2020-10-14 오후 9:40:52
 *  Author: jaeun
 */ 

#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
void PB_LShift(unsigned long ms)
{
	int i, j;
	unsigned char LED=0xfe; //좌에서 우로 이동할 때의 초기값
	
	for(i=0;i<8;i++)
	{
		for(j=0;j<ms;j++)
		{
			_delay_ms(1);
		}
		PORTB=LED;
		LED=(LED<<1)|0x01;
	}
}
void PB_RShift(unsigned long ms)
{
	int i, j;
	unsigned char LED=0x7f;  //우에서 좌로 이동할 때의 초기값
	
	for(i=0;i<8;i++)
	{
		for(j=0;j<ms;j++)
		{
			_delay_ms(1);
		}
		PORTB=LED;
		LED=(LED>>1)|0x80;
	}
}
void PB_Flash(unsigned long ms)
{
	int i, j;
	unsigned char LED = 0xff;
	
	for(i=0; i<8; i++)
	{
		PORTB = LED;
		for(j=0;j<ms;j++)
		{
			_delay_ms(1);
		}
		LED = ~LED;
	}
}
void PB_Toggle(unsigned long ms)
{
	int i, j;
	unsigned char LED = 0xf0;
	
	for(i=0; i<8; i++)
	{
		PORTB = LED;
		for(j=0;j<ms;j++)
		{
			_delay_ms(1);
		}
		LED = ~LED;
	}
}