//key.c
#include <reg52.h>
#include "com.h"
#include "key.h"
	 
uchar getRow()
{
  uchar ret = 0;
  KEY_PORT=0xf0;

  switch(KEY_PORT){
  	case  0x70: ret = 1;break;
	case  0xB0: ret = 2;break;
	case  0xD0: ret = 3;break;
	case  0xE0: ret = 4;break; 
  }	  
  
  return ret;

}

uchar getCol()
{
  uchar ret = 0;  
  KEY_PORT= 0x0F;
  //tmp = P1;
  switch(KEY_PORT){
  	case  0x07: ret = 1;break;
	case  0x0B: ret = 2;break;
	case  0x0D: ret = 3;break;
	case  0x0E: ret = 4;break;
  }
//  if(P3^3 == 0)  ret= 1;//1
//  if(P3^2 == 0)  ret= 2;//2
//  if(P3^1 == 0)  ret= 3;//3
//  if(P3^0 == 0)  ret= 4;//4
  
  return ret;

}

uchar getKey()
{	uchar key =0xFF;
	uchar row,col;
	row = getRow();	 //��ȡ�к�
	if(row != 0) {   //�м�����
		delay(200);	 //ysanshi 
	  	col = getCol();// ��ȡ�к�
		if(col!=0){
		   key =(row-1)*4+(col-1);	//��������	   
		   //while(getCol()){;} // �ȴ�����
		}
		while(getCol()){;}
	}
	return key;
}

