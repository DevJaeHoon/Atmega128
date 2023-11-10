#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include "buzzer.h"
void delay_us_Melody(int data)
{
	int i;
	for(i=0;i<data;i++)
	{
		_delay_us(1);
	}
}
void Sound(unsigned int ch, unsigned int time)
{
	unsigned int tim;
	
	tim = ch;
	tim = tim*1000 / time;
	
	while(tim--){
		MelOn;
		delay_us_Melody(time);
		MelOff;
		delay_us_Melody(time);
	}
}
void S_Good(void)
{
	Sound(BB,LLa );
	
			
}

void S_Error(void)
{
	Sound(BB, LSi );
	_delay_ms(200);
	Sound(BB,LLa );
	_delay_ms(200);
	Sound(BB,LSo );
	_delay_ms(200);
	Sound(BB,LDo );
}
void S_Push(void)
{
	Sound(BB, HDo );
}
void S_Start(void)
{
	Sound(BB,HDo);
	Sound(SB,HRe);
	Sound(BB,HMi);
	Sound(SB,HFa);
	Sound(BB,HSo);
	Sound(SB,HLa);
	Sound(BB,HSi);
	Sound(SB,hDo);
}
void S_S1(void)
{
	Sound(BB,BDo);
	Sound(BB,BMi);
	Sound(BB,BSo);
	Sound(BB,HDo);
}
void S_S2(void)
{
	Sound(BB,HDo);
	Sound(BB,HMi);
}
void S_S3(void)
{
	Sound(BB,LDo);
}

void S_S4(void)
{
	Sound(BB,BDo);
	Sound(BB,BMi);
	Sound(BB,BSo);
}
void S_S5(void)
{
	Sound(RB,LDo);
}
void S_S6(void)
{
	Sound(LB,LDo);
	
}
void S_S7(void)
{
	Sound(BB,BDo);
	Sound(BB,HDo);
}