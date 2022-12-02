//lcd1602.c 

#ifndef _LCD1602_H
#define _LCD1602_H

#include <reg52.h> 

#define LCD_PORT   P0      //LCD 数据口
	sbit LCD_RS = P1^7;
	sbit LCD_RW = P1^6;
	sbit LCD_E  = P1^5;
	
	//初始化函数
	void lcd1602Init(void);
	void lcd1602Clean(void);

	void lcd1602WriteChar(unsigned char row,
					  unsigned char col,
					  char ch);
	
	/*字符串显示函数
		入口参数：
		raw：行号； col：列号；length：字符串长度； *str：字符串
	*/
	void lcd1602WriteString(unsigned char   row,
	                        unsigned char   col,
							unsigned char   length,
							unsigned char   *str);


#endif