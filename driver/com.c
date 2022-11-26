//com.c
#include "com.h"
//************延时函数************
void  delay(uint  i)        				//延时函数
{
	uint  j;
	for  (j=0;j<i;j++){}
}

void delayus(uint i ) 
{ 	  		
	while(i--){	     
	    _nop_();	 
    }	              	
}

void delayms(uint i)
{
  	TMOD =((TMOD&0x0F)|0x01);//定时器0，16位定时
  	TH0 = (65536 - msCount)/256;
  	TL0 = (65536 - msCount)%256;
  	TR0 = 1;	    //启动定时器0
  	while(i--){
  		while(TF0==0){     //1ms定时	  	 
			TH0 = (65536 - msCount)/256;
  			TL0 = (65536 - msCount)%256;
			TF0=1;
  		}
  	}
 	TR0 = 0; //停止定时器0
}