//CAT24c02.c

#include "cat24c02.h"
#include "com.h"



unsigned char CAT02ReadByte(unsigned char addr)
{
  unsigned char ret;
  I2C_Start();

  I2C_WriteByte(CAT02WADDR);
  I2C_CheckACK();

  I2C_WriteByte(addr);
  I2C_CheckACK();

  I2C_Start();

  I2C_WriteByte(CAT02RADDR);
  I2C_CheckACK();

  ret = I2C_ReadByte();
  I2C_NCK();

  I2C_Stop();
  return ret;
}

void  CAT02WriteByte(unsigned char addr,
                   unsigned char value)
{
  WP = 0;
  I2C_Start();

  I2C_WriteByte(CAT02WADDR);
  I2C_CheckACK();

  I2C_WriteByte(addr);
  I2C_CheckACK();

  I2C_WriteByte(value);
  I2C_CheckACK();

  I2C_Stop();
	
  WP  = 1;
  
}
/* *******
*  功能： 读多个数据
   输入参数： addr 起始地址
              size  读数据个数
   输出参数： buff  读到的数据存区
   返回值：  实际读到的数据个数
   */


unsigned char CAT02ReadMutiBytes(unsigned char addr,
                          int size,
						  unsigned char *buf)
{
  unsigned char i=0;

  I2C_Start();

  I2C_WriteByte(CAT02WADDR);
  I2C_CheckACK();

  I2C_WriteByte(addr);
  I2C_CheckACK();

  I2C_Start();
  I2C_WriteByte(CAT02RADDR);
  I2C_CheckACK();

  for(;i<size-1;i++){  	 //读size-1个字节
  	buf[i] = I2C_ReadByte();
	I2C_ACK();
//	delay(2);
  }
  buf[i]=I2C_ReadByte();  //读最后一个字节
  I2C_NCK();

  I2C_Stop();

  return i;
	  
}

/* *******
*  功能： 写多个数据
   输入参数： addr 起始地址
              size  读数据个数
   输出参数： buff  要写的数据存区
   返回值：  实际写的数据个数
   */

unsigned char CAT02WriteMutiBytes(unsigned char addr,
                          int size,
						  unsigned char *buf)
{
	unsigned char i = 0;
    
	WP = 0;
	I2C_Start();

  	I2C_WriteByte(CAT02WADDR);
  	I2C_CheckACK();

  	I2C_WriteByte(addr);
  	I2C_CheckACK();
				 
	while(size --){	 //连续写size个byte
  		I2C_WriteByte(buf[i++]);
		if(I2C_CheckACK() ==0) break; //如果从机会员nck 提前结束写
	}
   I2C_Stop();
   WP = 1;
   return i;
}


//uchar buff[6]="abcdef";
//#include "serial.h"
//#include "lcd1602.h"
//void main()
//{
//	serialInit();
//	lcd1602Init();
//	
//	CAT02WriteMutiBytes(0x00,5,buff);
//	
//	delay(100);
//	CAT02ReadMutiBytes(0,5,buff);  
//	serialSendString(buff);
//	lcd1602WriteString(0,0,5,buff);
//	
//	while(1);
//}
