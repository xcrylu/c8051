//serial.c

#include "serial.h"

void serialInit(void)
{	   
	SCON = 0x50;	 //���ڹ�����ʽ1��8λ�첽�����ؿɱ䣬�������  	
	TMOD = (0x20|(TMOD&0x0F)) ;//��ʱ��1������ʽ2:8λ�Զ�����
	PCON = 0x00;
	TH1=TL1 = 0xFD ;//������Ϊ9600 fosc = 12Mʱ�����8.5% 	,fosc=11.0592M,����� 
	TR1 = 1; //������ʱ�� 
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

//��������bug�����һֱδ�յ����ݣ�
//�����ڴ˿���
//���ڽ������ʹ���жϷ�ʽʵ�� 
char  serialReceive(void)
{
 	while(RI==0);
	RI = 0;
	return SBUF; 
}