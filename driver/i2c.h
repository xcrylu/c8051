//I2c.h

#ifndef _I2C_H
#define _I2C_H

#include <reg52.h>

	sbit SCL = P1^0;	//时钟线			
	sbit SDA = P1^1;	//数据线
	
	void I2C_Start(void) ; 				// 起始条件子程序
	void I2C_Stop(void);
	void I2C_ACK(void);	
	void I2C_NCK(void);
	unsigned char I2C_CheckACK(void);
	void I2C_WriteByte(unsigned char ch) ;
	unsigned char I2C_ReadByte(void);
#endif
