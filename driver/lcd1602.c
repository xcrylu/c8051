
#include "lcd1602.h"

void  wc51r(unsigned char  i);
void  wc51ddr(unsigned char  i);
void  fbusy(void);

//初始化函数
void  lcd1602Init()
{
	wc51r(0x38);      	//使用8位数据,显示两行,使用5×7的字型
	wc51r(0x0c);     	//显示器开,光标关,字符不闪烁
	wc51r(0x06);     	//字符不动,光标自动右移一格
	wc51r(0x01);     	//清屏
}
//检查忙函数
void  fbusy()
{
	LCD_PORT=0Xff;
	LCD_RS=0;
	LCD_RW=1;
	LCD_E=0; 
	LCD_E=1;
	while (LCD_PORT&0x80){//忙,等待
		LCD_E=0;
		LCD_E=1;
	}      //忙,等待
}
//写命令函数
void  wc51r(unsigned char  j)
{
	fbusy();
	LCD_E=0;
	LCD_RS=0;
	LCD_RW=0;
	LCD_E=1;
	LCD_PORT=j;
	LCD_E=0;
}
//写数据函数
void  wc51ddr(unsigned char  j)
{
	fbusy();
	LCD_E=0;
	LCD_RS=1;
	LCD_RW=0;
	LCD_E=1;
	LCD_PORT=j;
	LCD_E=0;
}
/*字符串显示函数
入口参数：
raw：行号； col：列号；length：字符串长度； *str：字符串*/
void  lcd1602WriteString(unsigned char row,
						unsigned char col,
						unsigned char length,
						unsigned char *str)
{
	unsigned char i;
	wc51r(0x80+0x40*row+col);
	for (i=0;i<length;i++)	{
		wc51ddr(*str);
		str++;
	}
}

void lcd1602WriteChar(unsigned char row,
					  unsigned char col,
					  char ch)
{
  	wc51r(0x80+0x40*row+col);
	wc51ddr(ch);

}