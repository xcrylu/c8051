//com.c
#include "com.h"
//************��ʱ����************
void  delay(uint  i)        				//��ʱ����
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
  	TMOD =((TMOD&0x0F)|0x01);//��ʱ��0��16λ��ʱ
  	TH0 = (65536 - msCount)/256;
  	TL0 = (65536 - msCount)%256;
  	TR0 = 1;	    //������ʱ��0
  	while(i--){
  		while(TF0==0){     //1ms��ʱ	  	 
			TH0 = (65536 - msCount)/256;
  			TL0 = (65536 - msCount)%256;
			TF0=1;
  		}
  	}
 	TR0 = 0; //ֹͣ��ʱ��0
}