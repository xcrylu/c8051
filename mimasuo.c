// mimalocker.c

#include "24c02.h"
#include "i2c.h"
#include "key.h"
#include "lcd1602.h"
#include "serial.h"
#include "ds18b20.h"


char test[]="hello";
char buff[20]={0};


void main()
{
//	lcd1602Init();
	serialInit();
//	WP = 0;
//	C02WriteMutiBytes(0x00,5,test);

//	WP =1;
//	delay(10);
//	WP =1;
//	WP = 1;
//    delay(300);
//	C02ReadMutiBytes(0,5,buff);  //
//	lcd1602WriteString(0,1,5,buff);	
//   I2C_Start();
//   I2C_WriteByte(C02WADDR);
//   I2C_CheckACK();
//   I2C_WriteByte(0x11);
//   I2C_CheckACK();
//   I2C_WriteByte(0x55);
//   I2C_CheckACK();
//
//   I2C_Stop();
//   C02WriteByte(0x11,0x55);
//   delay(300);	//µÈ´ýÐ´Íê³É
//   C02ReadByte(0x00);
//   C02ReadByte(0x01);
//   C02ReadByte(0x02);
   
	
//	serialSendByte('0');
//	serialSendString(test);
//	lcd1602WriteChar(1,1,'a');


	while(1)
	{
//	uchar keyValue =0xFF;
////	serialSendString(test);
//	 keyValue =  getKey();
//	 	if(0xff != keyValue){	
////		    serialSendByte(keyValue);
//	   		lcd1602WriteChar(0,0,keyValue+'0');
//		}
//	unsigned value = ds18b20ReadTemperature(devId);
	unsigned value = ds18b20ReadTemperature();
	uchar temp1 = (uchar)(value/255);
	uchar temp2 = (uchar)(value%255);
	//serialSendByte(temp1);
	serialSendByte('a');
	 
	
	};

}