//com.h

#ifndef _COM_H
#define _COM_H
#include <reg52.h>
#include <intrins.h>

#define uint unsigned int
#define uchar unsigned char

#define fosc  12000000	          //����Ƶ�� ��λ hz
#define Tosc  1*1000000/fosc	  //ʱ������ ��λ ΢��
#define Tm  Tosc*12				  //�������� ��λ ΢��

#define msCount  1000/Tm          //1ms����ֵ

void delay(uint  i) ;	
void delayus(uint i );
void delayms(uint i); 

#endif