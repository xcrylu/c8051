

//I2c.c
#include "i2c.h"
#include <intrins.h>

void I2C_Start(void)  				// 起始条件子程序
{
	SDA = 1;
	SCL = 1;
	_nop_();
	SDA = 0;
	_nop_();
}
void I2C_Stop(void)   				// 停止条件子程序
{
	SDA = 0;
	SCL = 1;
	_nop_();
	SDA = 1;
	_nop_();
}
void I2C_ACK(void)   				// 应答子程序
{
	SDA = 0;
	_nop_();
	SCL = 1;
	_nop_();
	SCL = 0;
}

void I2C_NCK(void)   				// 应答子程序
{
	SCL = 0;
	SDA = 1;
	_nop_();
	SCL = 1;
	_nop_();
	SCL = 0;
}

/**
* 读ACK，
* 返回值：  0   ；NCK
*           1   ：ACK
*/
unsigned char  I2C_CheckACK(void)
{	
	unsigned char ret = 0;
	SCL = 0;
	SDA = 1;//设置引脚为输入模式
	SCL = 1;
	_nop_();

	if(SDA==1)  ret = 0;
	else ret =  1;

	SCL = 0;

	return ret;
		
}
void I2C_WriteByte(unsigned char ch) 			// 发送数据子程序,ch为要发送的数据
{
	unsigned char BitCounter = 8; 		//位数控制
	unsigned char tmp; 					//中间变量控制
	do
	{
		tmp = ch;
		SCL = 0;
		_nop_();
		if ((tmp&0x80)==0x80)	//如果最高位是１
			SDA = 1;
		else
			SDA = 0;
		SCL = 1;
		tmp = ch<<1;			//左移
		ch = tmp; 
		BitCounter--;			
	} while(BitCounter);

	SCL = 0;
}

unsigned char I2C_ReadByte(void)
{
	unsigned char BitCounter = 8; 		//位数控制
	unsigned char tmp=0; 					//中间变量控制
	for(;BitCounter>0;BitCounter--)
	{
		
		SCL = 0;
		SDA = 1;//设置引脚为输入模式
		_nop_();				
		SCL = 1;
		_nop_();
		if (1==SDA)	//如果是１
			tmp |= 0x01<<(BitCounter-1);		
	}	
	SCL = 0;	
	return tmp;		
}
