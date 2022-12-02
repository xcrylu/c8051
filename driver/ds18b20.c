
//DS18b20.h

#include "ds18b20.h"
#include "serial.h"


//uchar  devId[3][8]={
//		{0},
//		{0},
//		{0}
//	};

//1-wire复位
void wire1Reset(void)
{  
	DQ = 1;_nop_();_nop_();
  	DQ = 0;
	//delayus(480);
	delay(55); //约500us
	DQ = 1;
}
//1-wire初始化
// 返回值： 0 初始化成功
//          1 无设备应答
uchar wire1Init(void)
{
	uchar ret = 0;
	wire1Reset();
	delay(2);_nop_();_nop_();
	//DQ = 1;
	ret = DQ;
	delay(25);
	return ret;
}
//1-wire 写bit
void wire1WriteBit(bit b)
{
	DQ = 0;
    _nop_(); _nop_();  //拉低2us 时钟频率12M	

	DQ = b;		
	delay(4); //延时约30
	DQ = 1;
	//delay(1);
	_nop_();_nop_();
}
//1-wire 读bit
//返回值： 0
//         1
uchar wire1ReadBit(void)
{
	uchar ret = 0;
	DQ = 0;//发起读时隙
	_nop_(); _nop_();  //拉低2us 时钟频率12M
	DQ = 1; //释放总线
	//_nop_(); _nop_();_nop_(); _nop_();//6us
	delay(1);
	ret = DQ;
	delay(4);//延时 约 40us
	return ret;
}

void wire1WriteByte(uchar value)
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
		ret |=  (wire1ReadBit()<<i); 
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
	
	while(wire1Init());
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

void ds18b20ReadId(uchar buff[8])
{
	uchar i = 0;
	while(wire1Init());	
	// wire1WriteBit(DS1B20Cmd_SKIP_ROM);
	wire1WriteByte(DS1B20Cmd_READ_ROM);
	for(i=0;i<8;i++){
		buff[i] = wire1ReadByte();
	}
}


uchar code  dot_tab[] ="0112334456678899";//定义小数位的对应字符编码
float temperatureProcess(uint t,char buff[8])
{   
	float ret = (int)t/16.0;	
	uchar dot;
		if(t&0x8000) {
			*buff++ = '-';
			//9wei
			t = t|0x07;
			t =-t;
			//9wei
			
		}		
	dot = t&0x0f;     //小数
	
	t = t>>4;   //整数
		
	*buff++ = t/100+'0'; //百位
	t= t%100 ; 
	*buff++ =t/10+'0';   //十位
	*buff++ = t%10+'0';  //个位
	*buff++ = '.' ;       //点
	*buff++ = dot_tab[dot]; //小数位，只显示1位小数
	*buff = '\0';	
	
    return  ret;
}

//test

// void main(){
// 	//test wire1Rest 仿真ok 0 ：514us，间隔 4us
// 	// wire1Reset();
// 	// wire1Reset();
// 	// wire1Reset();

// 	// test wireInit ok 间隔 530us
// 	// wire1Init();
// 	// wire1Init();
// 	// wire1Init();

// 	// test wire1Writebit  ok 间隔64us 1低电平4us 0低电平30us
// 	// wire1WriteBit(0);
// 	// wire1WriteBit(1);
// 	// wire1WriteBit(0);
// 	// wire1WriteBit(1);

// 	// test wire1ReadBit  ok 间隔76us,拉低2us
// 	// wire1ReadBit();
// 	// wire1ReadBit();
// 	// wire1ReadBit();
// 	// wire1ReadBit();
   
//     // test wire1WritBit
// 	// wire1WriteByte(0x55);  //高电平时间长，一位时间为96us
// 	// wire1WriteByte(~0x55);

// 	// test wire1ReadByte(); 周期117um，主机拉低3us
// 	// wire1ReadByte();
// 	// wire1ReadByte();
// 	// wire1ReadByte();

  
//   	while(1);

// }


//18b20复位
// void ds18b20_init(void)
// {
// 	while(1)
// 	{
// 		DQ=1; _nop_();_nop_();
// 		DQ=0; 	delay(50);
// 		DQ=1;	delay(3);
// 		if (!DQ){delay(25);	break;}
// 		//DQ=0;	   //否则再发复位信号
// 	}
// }
// //从单总线上读取一个字节                                      
// uchar read_byte(void)         			
// {
//   uchar i;
//   uchar value = 0;
//   DQ = 1; _nop_();_nop_();
//   for (i=8;i>0;i--)
//   {
//     value>>=1;
//     DQ = 0;_nop_();_nop_();_nop_();
//     DQ = 1;
//     delay(1);
//     if(DQ)value|=0x80;
//     delay(6);
//   }
//   return(value);
// }
// //向单总线上写一个字节
// void write_byte(uchar val)     	
// {
//   uchar i;
//   DQ = 1; _nop_();_nop_();
//    for (i=8; i>0; i--)         	// 一次写一字节
//   {
//     DQ = 0;
//     DQ = val&0x01;
//     delay(5);
//     DQ = 1;
//     val=val/2;
//   }
//   delay(5);
// }
// uchar rom[8]={0,1,2,3,4,5,6,7};
// //读出总线上的DS18B20模块的ROM地址，存入指定的ROM单元。
// void read_rom()
// {
// 	uchar i;
// 						//计数当前DS18B20模块ROM的偏移地址
// 	ds18b20_init();
// 	write_byte(0x33); 			//发读ROM命令
// 	//wire1WriteByte(0x33);
// 	for(i=0;i<8;i++)
// 	{
// 		rom[i]=read_byte();
		
// 	}
// }

// void main()
// {
// 	uchar i=0;
// 	serialInit();
// 	//read_rom();
// 	ds18b20ReadId(rom);
// 	for(i=0;i<8;i++){
// 		serialSendByte(rom[i]);
// 	}
//unsigned value = ds18b20ReadTemperature(devId);
////		uint t = ds18B20ReadTemperture();
//        float tf=temperatureProcess(0xff5e,buff);
// 	while(1);


// }

		
	







