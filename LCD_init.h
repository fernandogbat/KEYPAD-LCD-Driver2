#define LCD_DATA GPIOB
#define LCD_CTRL GPIOA
#define RS 0x20
#define RW 0x40
#define EN 0x80
void LCD_init(void);
void LCD_command(unsigned char command);
//void LCD_data(unsigned char data);
void delayUs(int n);
void delayMs(int n);
