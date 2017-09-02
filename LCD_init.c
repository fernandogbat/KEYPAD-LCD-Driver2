//Initializes LCD for character display, 8-bits 2 lines
//Works for Hitachi HD44780 and Tinharp/ Shenzhen Eone  1602A
//Author :Israel N Gbati
//Date : 5/05/16
//Location  : Shimoda Village Yokohama Japan
#include "TM4C123.h"                    // Device header
#include "LCD_init.h"


void LCD_init(void)
{
	SYSCTL->RCGCGPIO |=0x01;							 //Clock for GPIOA
	SYSCTL->RCGCGPIO |=0x02; 							 //Clock for GPIOB
	LCD_CTRL->DIR |=0xE0;   							 //PA5-7 as output
	LCD_CTRL->DATA |=0xE0;
	LCD_DATA->DIR =0xFF;   							 //All PB as output
	LCD_DATA->DATA =0xFF;
	
	delayMs(20);        
	LCD_command(0x30);
	delayMs(5);
	LCD_command(0x30);
	delayUs(100);
	LCD_command(0x30);
	
  LCD_command(0x38);
	LCD_command(0x06);
	LCD_command(0x01);
	LCD_command(0x0F);
	
	
}

void delayMs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3180; j++)
            {}  // do nothing for 1 ms 
}

// delay n microseconds (16 MHz CPU clock) 
void delayUs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3; j++)
            {}  
}

void LCD_command(unsigned char command)
{
	LCD_CTRL->DATA =0;// Reset Rs=0, Rw=0
	LCD_CTRL->DATA =command;
	LCD_CTRL->DATA = EN;
	delayUs(0);
	LCD_CTRL->DATA =0;
	if(command <4){
	  delayMs(2);   
	}
		else{
			delayUs(37);  
	}
	
}
/*
void LCD_data(unsigned char data)
{
	LCD_DATA->DATA = RS;
	LCD_DATA->DATA =data;
	LCD_CTRL->DATA = EN |RS;
	delayUs(0);
	LCD_CTRL->DATA =0;
	delayUs(40);
}
*/