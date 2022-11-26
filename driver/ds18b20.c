
//DS18b20.h

#include "DS18B20.h"


//uchar  devId[3][8]={
//		{0},
//		{0},
//		{0}
//	};

//1-wire复位
void wire1Reset(void)
{
  	DQ = 0;
	delayus(480);
	DQ = 1;
}
//1-wire初始化
// 返回值： 1 初始化成功
//          0 无设备应答
uchar wire1Init(void)
{
	uchar ret = 0;
	wire1Reset();
	delayus(20);
	if(DQ == 0 ) ret = 1;
	else  ret = 0;
	delayus(460);
	return ret;
}
// 1-wire写位
void wire1WriteBit(bit b)
{
	DQ = 0;
	if(b==0){  //写0
		delayus(60);
		DQ = 1;
	}else{	   //写1;
		delayus(10);
		DQ = 1;
		delayus(50);
	}
}
//1-wire 读bit
//返回值： 0
//         1
uchar wire1ReadBit(void)
{
	uchar ret = 0;
	DQ = 0;//发起读时隙
	delayus(2);
	DQ = 1; //释放总线
	delayus(5);
	if( DQ == 0) ret  = 0;
	else  ret = 1;
	delayus(53);
	return ret;
}

void wire1Byte(uchar value)
{
	bit b ;
	uchar i=0;
	for(i = 0;i <8;i++)
	{
		b = (value&0x01);
		wire1WriteBit(b);
		value >>= 1;
	} 
}

uchar wire1ReadByte(void)
{
	uchar ret=0;
	uchar i = 0;
	for(i = 0;i	<8 ;i++){
		ret &=  (wire1ReadBit()<<i); 
	}
	return ret;			   
}

void ds18b20Config(uchar mode)
{
	wire1Init();
	wire1WriteByte(DS1B20Cmd_SKIP_ROM);
	wire1WriteByte(DS1B20Cmd_WRITE_SCHPAD);
	wire1WriteByte(0x00);
	wire1WriteByte(0xFF);
	wire1WriteByte(mode);
}

//unsigned short ds18B20ReadTemperture(uchar devId[8])
unsigned short ds18B20ReadTemperture(void)
{
	uint ret = 0;
	uchar tmp1,tmp2;
//	uchar i;
	
	wire1Init();
	wire1WriteByte(DS1B20Cmd_SKIP_ROM);
	wire1WriteByte(DS1B20Cmd_CONVERT);
	delayms(800);	  //等待完成测量（转换）

	//输入读暂存命令DS1B20Cmd_READ_SCHPAD 
	//后ds18b20会连续输出全暂存9位数据
	//通过发送复位命令后终止数据传输
	wire1Init();
//	wireWriteByte(DS1B20Cmd_SKIP_ROM);
	//指定设备ID
//	for(i=0;i<8;i++) {
//	   wire1WriteByte(devId[i]);
//	}
	// 如果只有一个设备在线，使用跳过rom命令，不用指定设备id	
	wire1WriteByte(DS1B20Cmd_SKIP_ROM);
	wire1WriteByte(DS1B20Cmd_READ_SCHPAD);	  //读暂存器
	tmp1 = wire1ReadByte();
	tmp2 = wire1ReadByte();
	wire1Reset();
	ret = tmp1+tmp2*255;
	return ret;
}

		
	







