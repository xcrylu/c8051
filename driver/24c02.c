//24c02.c

#include "24c02.h"
#include "com.h"



unsigned char C02ReadByte(unsigned char addr)
{
  unsigned char ret;
  I2C_Start();

  I2C_WriteByte(C02WADDR);
  I2C_CheckACK();

  I2C_WriteByte(addr);
  I2C_CheckACK();

  I2C_Start();

  I2C_WriteByte(C02RADDR);
  I2C_CheckACK();

  ret = I2C_ReadByte();
  I2C_NCK();

  I2C_Stop();
  return 0;
}

void  C02WriteByte(unsigned char addr,
                   unsigned char value)
{
  I2C_Start();

  I2C_WriteByte(C02WADDR);
  I2C_CheckACK();

  I2C_WriteByte(addr);
  I2C_CheckACK();

  I2C_WriteByte(value);
  I2C_CheckACK();

  I2C_Stop();
  
}
/* *******
*  ���ܣ� ���������
   ��������� addr ��ʼ��ַ
              size  �����ݸ���
   ��������� buff  ���������ݴ���
   ����ֵ��  ʵ�ʶ��������ݸ���
   */


unsigned char C02ReadMutiBytes(unsigned char addr,
                          int size,
						  unsigned char *buf)
{
  unsigned char i=0;

  I2C_Start();

  I2C_WriteByte(C02WADDR);
  I2C_CheckACK();

  I2C_WriteByte(addr);
  I2C_CheckACK();

  I2C_Start();
  I2C_WriteByte(C02RADDR);
  I2C_CheckACK();

  for(;i<size-1;i++){  	 //��size-1���ֽ�
  	buf[i] = I2C_ReadByte();
	I2C_ACK();
//	delay(2);
  }
  buf[i]=I2C_ReadByte();  //�����һ���ֽ�
  I2C_NCK();

  I2C_Stop();

  return i;
	  
}

/* *******
*  ���ܣ� д�������
   ��������� addr ��ʼ��ַ
              size  �����ݸ���
   ��������� buff  Ҫд�����ݴ���
   ����ֵ��  ʵ��д�����ݸ���
   */

unsigned char C02WriteMutiBytes(unsigned char addr,
                          int size,
						  unsigned char *buf)
{
	unsigned char i = 0;

	I2C_Start();

  	I2C_WriteByte(C02WADDR);
  	I2C_CheckACK();

  	I2C_WriteByte(addr);
  	I2C_CheckACK();
				 
	while(size --){	 //����дsize��byte
  		I2C_WriteByte(buf[i++]);
		if(I2C_CheckACK() ==0) break; //����ӻ���Աnck ��ǰ����д
	}
   I2C_Stop();
   return i;
}

