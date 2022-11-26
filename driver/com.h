//com.h

#ifndef _COM_H
#define _COM_H
#include <reg52.h>
#include <intrins.h>

#define uint unsigned int
#define uchar unsigned char

#define fosc  12000000	          //晶振频率 单位 hz
#define Tosc  1*1000000/fosc	  //时钟周期 单位 微秒
#define Tm  Tosc*12				  //机器周期 单位 微妙

#define msCount  1000/Tm          //1ms计数值

void delay(uint  i) ;	
void delayus(uint i );
void delayms(uint i); 

#endif