//ds18b20.h	 
#include "com.h"

#ifndef _DS18B20_H
#define _DS8B20_H  

sbit DQ = P3^4;

//enum ds1b20Cmd{
// 温度转换命令
#define	DS1B20Cmd_CONVERT   0x44   	//
//暂存器命令
#define	DS1B20Cmd_READ_SCHPAD 	 0xBE		//读暂存器
#define	DS1B20Cmd_WRITE_SCHPAD 	 0x4E		//写暂存器
#define	DS1B20Cmd_COPY_SCHPAD 	 0xB8		//将暂存器内容复制到ROM
#define	DS1B20Cmd_READ_PWR_SPY	 0xB4		//读供电状态
// ROM 命令
#define	DS1B20Cmd_SEARCH_ROM	 0xF0
#define	DS1B20Cmd_READ_ROM		 0x33
#define	DS1B20Cmd_MATH_ROM		 0x55
#define	DS1B20Cmd_SKIP_ROM		 0xCC
#define	DS1B20Cmd_ALARM_SEARCH	 0xEC	
//}

//DS18B20测温模式
#define DS1B20CONF_MODE_9BIT    	0x1F	  //9bit 转换时间：93.75 ms
#define DS1B20CONF_MODE_10BIT	0x3F	  //10bit 转换时间：187.5 ms
#define DS1B20CONF_MODE_11BIT	0x5F	  //9bit 转换时间：275 ms
#define DS1B20CONF_MODE_12BIT	0x7F	  //9bit 转换时间：7500 ms

//ds18b20  64bit设备ID
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
 void ds18b20ReadId(uchar buff[8]);
 //unsigned short ds18b20ReadTemperature(uchar devId[8]);
  unsigned short ds18B20ReadTemperture(void);
  float temperatureProcess(uint t,char buff[8]);


#endif

																	 