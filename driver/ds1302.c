//ds1302.c
#include "serial.h"

#include "ds1302.h"
// write address
//uchar code RTC_ADDR[7]={0x80,0x82,0x84,0x86,0x8A,0x8C};
#define CLOCK_BURST_ADDR 0xBE
#define RAM_BURST_ADDR 0xFE
// read address  = read address + 1

void DS1302WriteByte(uchar dat)
{
	uchar i;
	SCK = 0;
	_nop_();
	for(i = 0;i<8;i++){
		IO = dat&0x01;//先发最低位
		dat >>=1;
		SCK = 1;
		_nop_();
		SCK = 0;
		_nop_();
	}
}

uchar DS1302ReadByte(void)
{
	uchar dat,i;
	SCK = 0;
	_nop_();
	for(i = 0;i<8;i++){		
		//dat |=  IO<<(7-i);//先接收最低位
		dat>>=1;
		if(IO == 1) {dat |= 0x80;}		
		SCK = 1;
		_nop_();
		SCK = 0;
		_nop_();
	}
	return dat;	
}
void DS1302Write(uchar addr,uchar value)
{	
	CE = 1;	
	_nop_();	
	//写地址
	DS1302WriteByte(addr);
	//写数据
	DS1302WriteByte(value);	
	CE = 0;		
}
uchar DS1302Read(char addr)
{
	uchar dat = 0;
	uchar i = 0;	
	CE = 1;
	IO = 1;//设置引脚输入
	//写地址
	DS1302WriteByte(addr);
	//读数据
	dat = DS1302ReadByte();
	CE = 0;
	return dat;	
}

void DS1302WriteBurst(char mode,uchar size, uchar buff[])
{
	uchar i=0;
	CE = 1;
	if(mode ==0 )	{DS1302WriteByte(CLOCK_BURST_ADDR);}
	else {DS1302WriteByte(RAM_BURST_ADDR);}
	for(i = 0;i<size;i++){
		DS1302WriteByte(buff[i]);
	}
	CE = 0;	
}

void DS1302ReadBurst(char mode,uchar size, uchar buff[])
{
	uchar i=0;
	CE = 1;
	if(mode == 0 )	{DS1302WriteByte(CLOCK_BURST_ADDR+1);}
	else {DS1302WriteByte(RAM_BURST_ADDR+1);}
	for(i = 0;i<size;i++){
		buff[i] = DS1302ReadByte();
		//serialSendByte(buff[i]);
	}
	CE = 0;	
}



void DS1302Init(uchar timeBuff[7])
{	
	DS1302Write(0x8E,0x00);
	//DS1302WriteByte(0x8E,0x00);//关闭写保护
	//DS1302WriteByte(0x00);
	DS1302WriteBurst(0,8,timeBuff);
	DS1302Write(0x8E,0x80);//打开写保护
}

void DS1302ReadTime(uchar timeBuff[7])
{
	DS1302ReadBurst(0,8,timeBuff);
}

//uchar DS1202ReadReg(uchar addr);

//uchar timeBuff[8]={1,2,3,4,5,6,7,8};
//void main()
//{
//	serialInit();
////	DS1302Init(timeBuff);
//	//delay(100);
//	//注意事项，第一次读数据无效
//	serialSendByte(DS1302Read(0X81));
//	DS1302ReadTime(timeBuff);
//	timeBuff[7]=0;
//	serialSendString(timeBuff);
//	//serialSendByte(DS1302Read(0X81));
//	//serialSendByte(DS1302Read(0X81));
//	while(1)
//	{
//		//serialSendByte(DS1302Read(0X81));
//		//DS1302Init(timeBuff);
//		//serialSendByte(DS1302Read(0X81));
//			
//	};
//}