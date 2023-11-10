#define LCD_WDATA PORTA
#define LCD_WINST PORTA
#define LCD_RDATA PINA

#define LCD_CTRL PORTG
#define LCD_EN 0
#define LCD_RW 1
#define LCD_RS 2

#define RIGHT 1
#define LEFT 0

typedef unsigned int Word;
typedef unsigned char Byte;

#define sei() asm("sei")
#define cli() asm("cli")

void LCD_Data(Byte ch);
void LCD_Comm(Byte ch);
void LCD_CHAR(Byte c);
void LCD_STR(char *str);
void LCD_pos(unsigned char row, unsigned char col);
void LCD_Clear(void);
void LCD_Init(void);
void Display_Shift(int direction);
void Cursor_Shift(int direction);
void Cursor_Home(void);
void Cur_ON(void);
void LCD_OFF(void);
void LL(void);
void RR(void);
void Entry(unsigned char ID, unsigned char SD);
void LCD_OVER(void);
void USART1_init(void);void putch_USART1(char data);void puts_USART1(char *str);void text00(void);void text01(void);void text03(void);void init_devices1(void);