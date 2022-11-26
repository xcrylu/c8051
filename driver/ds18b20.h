//ds18b20.h	 
#include "com.h"

#ifndef _DS18B20_H
#define _DS8B20_H  

sbit DQ = P1^4;

//enum ds1b20Cmd{
// �¶�ת������
#define	DS1B20Cmd_CONVERT   0x44   	//��ȫ���ݴ���������crc�ֽ�
//�ݴ���������
#define	DS1B20Cmd_READ_SCHPAD 	 0xBE		//д�ڲ��ݴ����ֽ�2��3��4
#define	DS1B20Cmd_WRITE_SCHPAD 	 0x4E		//�����ݴ������ݵ�EEPROM
#define	DS1B20Cmd_COPY_SCHPAD 	 0xB8		//��EEPROM��TH����TL���Ƶ��ݴ���
#define	DS1B20Cmd_READ_PWR_SPY	 0xB4		//����Դ����ģʽ
// ROM ������
#define	DS1B20Cmd_SEARCH_ROM	 0xF0
#define	DS1B20Cmd_READ_ROM		 0x33
#define	DS1B20Cmd_MATH_ROM		 0x55
#define	DS1B20Cmd_SKIP_ROM		 0xCC
#define	DS1B20Cmd_ALARM_SEARCH	 0xEC	
//}

//DS18B20����ģʽ
#define DS1B20Cmd_MODE_9BIT    	0x1F	  //9bit ����¶�ת��ʱ�䣺93.75 ms
#define DS1B20Cmd_MODE_10BIT	0x3F	  //10bit ����¶�ת��ʱ�䣺187.5 ms
#define DS1B20Cmd_MODE_11BIT	0x5F	  //9bit ����¶�ת��ʱ�䣺275 ms
#define DS1B20Cmd_MODE_12BIT	0x7F	  //9bit ����¶�ת��ʱ�䣺7500 ms

//ds18b20  64bit�豸id �����ﶨ����3���豸id
//extern  uchar devId[3][8]; 
// uchar devId[3][8]={
//		{0},
//		{0},
//		{0}
//	};
//uchar devId[8]={0};	


 void 	wire1Reset(void);
 uchar  wire1Init(void);
 void 	wire1WriteBit1(void);
 void 	wire1WriteBit0(void);
 uchar 	wire1ReadBit(void);
 void 	wire1WriteByte(uchar);
 uchar 	wire1ReadByte(void);
 //unsigned short ds18b20ReadTemperature(uchar devId[8]);
  unsigned short ds18b20ReadTemperature(void);


#endif

																	 