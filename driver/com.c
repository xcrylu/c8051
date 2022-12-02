//com.c
#include "com.h"
//************延时函数************
void  delay(uint  i)        				//延时函数
{
	while(i--){;}
}

void delayus(uchar i ) 
{ 	  		
	while(i--){	     
	    _nop_();	 
    }	              	
}

void delayms(uint i)
{
  	TMOD =((TMOD&0xF0)|0x01);//定时器0，16位定时
  	TH0 = (65536 - msCount)/256;
  	TL0 = (65536 - msCount)%256;
//	TF0 = 0;
  	TR0 = 1;	    //启动定时器0
  	while(i--){
  		while(TF0==0);//等待1ms时间到时
		TL0 = (65536 - msCount)%256;					
		TH0 = (65536 - msCount)/256;  			
		TF0=0;
		
  	}
 	TR0 = 0; //停止定时器0
}
////test
//sbit b = P3^0;
//void main()
//{	
//	b =0;
//	delayms(1);
//	b =1;
//	delayms(2);
//	b=0;
//	delayms(5);
//	b=1;
//	delayms(10);
//	b=0;
//	delayms(20);
//	b=1;
//}