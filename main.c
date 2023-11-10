#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#define ADC_AVCC_TYPE 0x40
#include "CLCD.h"
#include "buzzer.h"
#include "LED.h"

void Port_Init(void)
{
	DDRA = 0xFF; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0xFF;
	DDRD = 0x00; PORTD = 0x00;
	DDRG = 0x0F; PORTG = 0x00;
}

void init_devices(void)
{
	cli();
	Port_Init();
	LCD_Init();
	sei();
}void ADC_Init(void)     //ADC initialization
{
	ADCSRA = 0x00;        // ADC Disable
	ADMUX  = 0x00;         // Select adc input 0 (ADC0)
	ACSR   = 0x80;        // Analog Comparator Disable
	ADCSRA = 0xC3;        // ADEN, ADSC, 분주비 8 Conversion time: 6uS
}unsigned int Read_Adc_Data(unsigned char adc_input)   // ADC 읽어 들이기
{
	unsigned int adc = 0;
	ADCSRA = 0xC3;                                // Conversion time: 6uS
	ADMUX  = adc_input | ADC_AVCC_TYPE;            // adc  사용 핀 설정
	ADCSRA |= 0x40;                                // Wait for the AD conversion to complete
	while((ADCSRA & 0x10) != 0x10);
	adc += ADCL + ( ADCH * 256 );                // 2 byte 데이터로 변환
	ADCSRA = 0x00;                                // ADC Disable
	return adc;
}
void CGRAM_Set()
{
	int i;
	Byte life[] = {0x0a, 0x1f, 0x1f, 0x1f, 0x0e, 0x04, 0x00, 0x00};
	Byte car[]= {0x1c, 0x1e, 0x12, 0x13, 0x1f, 0x1e, 0x1e, 0x1c};
	LCD_Comm(0x40);
	_delay_ms(1);
	for(i=0; i<8; i++)
	{
		LCD_Data(life[i]);
		_delay_ms(1);
	}
	LCD_Comm(0x48);
	_delay_ms(1);
	for(i=0; i<8; i++)
	{
		LCD_Data(car[i]);
		_delay_ms(1);
	}
}


void game(){
	int i;
	char str_0[] = "START";
	char str_1[] = "GAME CLEAR";
	char str_2[] = "Look at";
	char str_3[] = "the TeraTerm";

	char sw;
	int GAO;

	while(1)
	
	{ LCD_Clear(); LCD_pos(0,8); LCD_CHAR(0x33); _delay_ms(500);S_Good(); PORTB=0x1f; _delay_ms(500);
		LCD_Clear(); LCD_pos(0,8);LCD_CHAR(0x32); S_Good(); PORTB=0x3f; _delay_ms(1000);
		LCD_Clear(); LCD_pos(0,8);LCD_CHAR(0x31); S_Good(); PORTB=0x7f; _delay_ms(1000);
		LCD_Clear(); LCD_pos(0,6);LCD_STR(str_0); S_Push(); PORTB=0xff; _delay_ms(1000);
		LCD_Clear();
		
		
		LCD_pos(0,0); LCD_Data(0x01);
		
		
		for (i=1; i<80; i++) {
			
			sw = 0xe0;
			sw = (0xf0 & PIND);
			
			
			switch (sw) {
				case 0xe0 : {LCD_pos(0,0); LCD_Data(0x01); LCD_pos(1,0); LCD_CHAR(0x20); LCD_CHAR(0x20); GAO=0; break;}
				case 0xd0 : {LCD_pos(1,0); LCD_Data(0x01); LCD_pos(0,0); LCD_CHAR(0x20); LCD_CHAR(0x20); GAO=1; break;}
			}
			
			
if (i<=8){
	LCD_pos(0,8-i); LCD_CHAR(0x20);
	if(i<8){Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==8 && GAO==0) LCD_OVER();}

if (i<=12){
	LCD_pos(1,12-i); LCD_CHAR(0x20);
	Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);
if(i==12 && GAO==1) LCD_OVER();}

if (i<=16){
	LCD_pos(0,16-i); LCD_CHAR(0x20);
	if(i<16){Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==16 && GAO==0) LCD_OVER();}

if(i>=4){if(i<=20){
	LCD_pos(1,20-i); LCD_CHAR(0x20);
Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==20 && GAO==1) LCD_OVER();}

if(i>=8){if(i<=24){
	LCD_pos(0,24-i); LCD_CHAR(0x20);
	if(i<24){Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}}
if(i==24 && GAO==0) LCD_OVER();}

if(i>=12){if(i<=28) {
	LCD_pos(1,28-i); LCD_CHAR(0x20);
Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==28 && GAO==1) LCD_OVER();}

if(i>=16){if(i<=32) {
	LCD_pos(0,32-i); LCD_CHAR(0x20);
	if(i<32){Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}}
if(i==32 && GAO==0) LCD_OVER();}

if(i>=20){if(i<=36){
	LCD_pos(1,36-i); LCD_CHAR(0x20);
Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==36 && GAO==1) LCD_OVER();}

if(i>=24){if(i<=40){
	LCD_pos(0,40-i); LCD_CHAR(0x20);
	if(i<40){Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}}
if(i==40 && GAO==0) LCD_OVER();}

if(i>=28){if(i<=44){
	LCD_pos(1,44-i); LCD_CHAR(0x20);
Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==44 && GAO==1) LCD_OVER();}

if(i>=31){if(i<=47){
	LCD_pos(1,47-i); LCD_CHAR(0x20);
Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==47 && GAO==1) LCD_OVER();}

if(i>=34){if(i<=50){
	LCD_pos(1,50-i); LCD_CHAR(0x20);
Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==50 && GAO==1) LCD_OVER();}

if(i>=37){if(i<=53){
	LCD_pos(0,53-i); LCD_CHAR(0x20);
	if(i<53){Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}}
if(i==53 && GAO==0) LCD_OVER();}

if(i>=41){if(i<=57){
	LCD_pos(1,57-i); LCD_CHAR(0x20);
Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==57 && GAO==1) LCD_OVER();}

if(i>=44){if(i<=60){
	LCD_pos(0,60-i); LCD_CHAR(0x20);
	if(i<60){Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}}
if(i==60 && GAO==0) LCD_OVER();}

if(i>=48){if(i<=64){
	LCD_pos(1,64-i); LCD_CHAR(0x20);
Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==64 && GAO==1) LCD_OVER();}

if(i>=52){if(i<=68){
	LCD_pos(0,68-i); LCD_CHAR(0x20);
	if(i<68){Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}}
if(i==68 && GAO==0) LCD_OVER();}

if(i>=56){if(i<=72){
	LCD_pos(1,72-i); LCD_CHAR(0x20);
Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==72 && GAO==1) LCD_OVER();}

if(i>=59){if(i<=75){
	LCD_pos(0,75-i); LCD_CHAR(0x20);
	if(i<75){Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}}
if(i==75 && GAO==0) LCD_OVER();}

if(i>=62){if(i<=78){
	LCD_pos(1,78-i); LCD_CHAR(0x20);
Cursor_Shift(LEFT); Cursor_Shift(LEFT); LCD_CHAR(0xff);}
if(i==78 && GAO==1) LCD_OVER();}

_delay_ms(300);



}
unsigned int Adc_data = 0;
double voltage = 0;
unsigned long weight = 0;


LCD_Clear();
LCD_pos(0,0);LCD_STR(str_1);
PB_RShift(200);
PB_LShift(200);
PORTB=0xff;

ADC_Init();
LCD_Init();

LCD_Clear();

LCD_pos(0,0); LCD_STR(str_2);
LCD_pos(1,0); LCD_STR(str_3);
_delay_ms(1000);
text01();
while(1){
	Adc_data = Read_Adc_Data(2);
	voltage = Adc_data/204.6;                // (1023/5)
	weight = (voltage+0.057)*4.119*1000;     // unit: gram
	
	if(weight > 5000){
	break;}
}

text03();
game();


}


}

int main(void)
{
	init_devices();
	CGRAM_Set();
	char start1[] = "start to";
	char start2[] = "press button";
	unsigned int Adc_data = 0;
	double voltage = 0;
	unsigned long weight = 0;
	ADC_Init();
	LCD_Init();
	LCD_pos(0,0); LCD_STR(start1);
	LCD_pos(1,0); LCD_STR(start2);
	
	while(1){
		Adc_data = Read_Adc_Data(2);
		voltage = Adc_data/204.6;                // (1023/5)
		weight = (voltage+0.057)*4.119*1000;     // unit: gram
		
		if(weight > 5000) {
			
			break;}
			
		
		
		
		
	}
	LCD_Clear();
	game();
}
void LCD_OVER(void)
{
	char str_5[] = "GAME OVER";
	char str_2[] = "Look at";
	char str_3[] = "the TeraTerm";
	unsigned int Adc_data = 0;
	double voltage = 0;
	unsigned long weight = 0;
	ADC_Init();
	LCD_Init();
	S_Error();
	LCD_Clear();
	
	LCD_pos(0,4);LCD_STR(str_5);
	PB_Flash(400);
	PORTB=0xff;

	LCD_Clear();
	LCD_pos(0,0); LCD_STR(str_2);
	LCD_pos(1,0); LCD_STR(str_3);
	_delay_ms(500);
	text00();
	while(1){

		Adc_data = Read_Adc_Data(2);
		voltage = Adc_data/204.6;                // (1023/5)
		weight = (voltage+0.057)*4.119*1000;     // unit: gram
		
		if(weight > 5000){ 
		break;}
	}
	text03();
	LCD_Clear();
	LCD_pos(1,0); LCD_CHAR(0x20);
	game();
}