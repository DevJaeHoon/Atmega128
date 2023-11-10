#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include "CLCD.h"

void LCD_Data(Byte ch)
{
	LCD_CTRL |= (1<<LCD_RS);
	LCD_CTRL &= ~(1<<LCD_RW);
	LCD_CTRL |= (1<<LCD_EN);
	_delay_us(50);
	LCD_WDATA = ch;
	_delay_us(50);
	LCD_CTRL &= ~(1<<LCD_EN);
	
}

void LCD_Comm(Byte ch)
{
	LCD_CTRL &= ~(1<<LCD_RS);
	LCD_CTRL &= ~(1<<LCD_RW);
	LCD_CTRL |= (1<<LCD_EN);
	_delay_us(50);
	LCD_WINST = ch;
	_delay_us(50);
	LCD_CTRL &= ~(1<<LCD_EN);

}

void LCD_CHAR(Byte c)
{
	LCD_Data(c);
	_delay_ms(1);
}

void LCD_STR(char *str)
{
	while(*str != 0)
	{
		LCD_CHAR(*str);
		str++;
	}
}

void LCD_pos(unsigned char row, unsigned char col)
{
	LCD_Comm(0x80 | (col+row*0x40));
}

void LCD_Clear(void)
{
	LCD_Comm(0x01);
	_delay_ms(2);
}

void LCD_Init(void)
{
	LCD_Comm(0x38);
	_delay_ms(2);
	LCD_Comm(0x38);
	_delay_ms(2);
	LCD_Comm(0x38);
	_delay_ms(2);
	LCD_Comm(0x0c);
	_delay_ms(2);
	LCD_Comm(0x06);
	_delay_ms(2);
	LCD_Clear();
}

void Display_Shift(int direction)
{if(direction == RIGHT)
	{
		LCD_Comm(0x1c);
		_delay_ms(1);
	}else if (direction==LEFT)
	{
		LCD_Comm(0x10);
		_delay_ms(1);
	}
}

void Cursor_Shift(int direction)
{
	if(direction == RIGHT)
	{
		LCD_Comm(0x14);
		_delay_ms(1);
	} else if(direction == LEFT)
	{
		LCD_Comm(0x10);
		_delay_ms(1);
	}
}

void Cursor_Home(void)
{
	LCD_Comm(0x02);
	_delay_ms(2);
}


void LCD_ON(void)
{
	LCD_Comm(0x0c);
	_delay_ms(2);
}

void LCD_OFF(void)
{
	LCD_Comm(0x08);
	_delay_ms(2);
}

void Cur_ON(void)
{
	LCD_Comm(0x0e);
	_delay_ms(2);
}


void Entry(unsigned char ID, unsigned char SD)
{
	if(ID == 1)
	{ if(SD == 0)
		{LCD_Comm(0x06);
		_delay_ms(1);} else if(SD == 1)
		{
			LCD_Comm(0x07);
			_delay_ms(1);
		}
	} else if(ID == 0)
	{ if(SD == 0)
		{LCD_Comm(0x04);
		_delay_ms(1);} else if(SD == 1)
		{
			LCD_Comm(0x05);
			_delay_ms(1);
		}
	}
}

////
void USART1_init(void){	UCSR1A = 0x00;                        // 1배속 전송모드	UCSR1C = (1<<UCSZ11) | (1<<UCSZ10);    // 0x06;	// Data : 8 bit	// Parity: Disabled	// Asynchronous mode	UCSR1B = 0x08;                        // TXEN1 = 1	UBRR1H = 0x00;                        // Set baud rate hi	UBRR1L = 0x07;                        // Set baud rate lo	// baud rate : 115200}void putch_USART1(char data){	while( !(UCSR1A & (1<<UDRE1)));	UDR1 = data;}void puts_USART1(char *str){	while(*str != 0) {		putch_USART1(*str);		str++;	}}void init_devices1(void)
{
	USART1_init();
	sei();
	
}void text00(void){	char array[] = "GameOver\r\n";	init_devices1();	_delay_ms(1000);	putch_USART1('\r');			putch_USART1('\n');			puts_USART1(array);	while(1) {		_delay_ms(500);		putch_USART1('P');		_delay_ms(100);		putch_USART1('R');		_delay_ms(100);		putch_USART1('E');		_delay_ms(100);		putch_USART1('S');		_delay_ms(100);		putch_USART1('S');		_delay_ms(100);				putch_USART1(' ');		_delay_ms(100);				putch_USART1('b');		_delay_ms(100);		putch_USART1('u');		_delay_ms(100);		putch_USART1('t');		_delay_ms(100);		putch_USART1('t');		_delay_ms(100);		putch_USART1('o');		_delay_ms(100);		putch_USART1('n');		break;	}	}		void text01(void)	{		char array[] = "GameClear\r\n";		init_devices1();		_delay_ms(1000);		putch_USART1('\r');		putch_USART1('\n');		puts_USART1(array);		while(1) {			_delay_ms(200);			putch_USART1('P');			_delay_ms(100);			putch_USART1('R');			_delay_ms(100);			putch_USART1('E');			_delay_ms(100);			putch_USART1('S');			_delay_ms(100);			putch_USART1('S');			_delay_ms(100);						putch_USART1(' ');			_delay_ms(100);						putch_USART1('b');			_delay_ms(100);			putch_USART1('u');			_delay_ms(100);			putch_USART1('t');			_delay_ms(100);			putch_USART1('t');			_delay_ms(100);			putch_USART1('o');			_delay_ms(100);			putch_USART1('n');			break;}		}				void text03(void)		{							char array[] = "Serial Communication Test\r\n";
		init_devices1();
		_delay_ms(5000);
		putch_USART1('\r');
		putch_USART1('\n');
		puts_USART1(array);
		putch_USART1('\r');
		putch_USART1('\n');
		while(1) {
			putch_USART1(27);
			putch_USART1('[');
			putch_USART1('2');
			putch_USART1('J');
			putch_USART1(27);
			putch_USART1('[');
			putch_USART1('H');
		break;}
		}