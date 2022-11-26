//serial.c

#include "serial.h"

void serialInit(void)
{	   
	SCON = 0x50;	 //串口工作方式1，8位异步，波特可变，允许接收  	
	TMOD = (0x20|(TMOD&0x0F)) ;//定时器1工作方式2:8位自动重载
	PCON = 0x00;
	TH1=TL1 = 0xFD ;//波特率为9600 fosc = 12M时，误差8.5% 	,fosc=11.0592M,无误差 
	TR1 = 1; //启动定时器 
}

void serialSendByte(char c)
{
	SBUF = c;
	while(TI==0);
	TI = 0;
} 

void serialSendString(char* str)
{
	while(*str)
	   serialSendByte(*str++);
}  

//本函数有bug，如果一直未收到数据，
//程序将在此卡死
//串口接收最好使用中断方式实现 
char  serialReceive(void)
{
 	while(RI==0);
	RI = 0;
	return SBUF; 
}