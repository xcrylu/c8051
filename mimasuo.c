// mimalocker.c
#include <stdio.h>


#include "cat24c02.h"
#include "key.h"
#include "lcd1602.h"
#include "serial.h"
//#include "ds18b20.h"

void open(void);
uchar checkPasswd(uchar passwd[],uchar input[],uchar size);
void alert(void);
void guard(void);
void setpasswd(void);
uchar* getPasswd(uchar buff[],uchar size);
uchar savePasswd(uchar passwd[],uchar size);

#define PASSWDSIZE  (6)
uchar g_passwd[PASSWDSIZE]={'0','1','2','3','4','5'};
//uchar spaceString[16]="              ";
uchar inputBuf1[PASSWDSIZE]={0};
uchar inputBuf[PASSWDSIZE]={0};
uchar key = 0;
uchar i = 0;
uchar retryCount = 0;

#define MODE_NOMARL 0
#define MODE_SETPASSWD 1

//uchar mode = MODE_SETPASSWD;
uchar mode = MODE_NOMARL;


void main()
{
	uchar key;
	lcd1602Init();
	CAT02ReadMutiBytes(0x00,PASSWDSIZE,g_passwd);
	
	while(1){
		
//		key=getKey();
//		if(key=='F')
//			mode = MODE_SETPASSWD;
		switch(mode){
			case MODE_NOMARL:
				guard();
				break;
			case MODE_SETPASSWD:
				setpasswd(); 
				//mode = MODE_NOMARL;	
				break;
		}
	}
}

void setpasswd(void)
{
	lcd1602WriteString(0,0,16,"input old passwd");
	getPasswd(inputBuf,PASSWDSIZE);
	if(checkPasswd(g_passwd,inputBuf,PASSWDSIZE))
	{
		lcd1602Clean();
		lcd1602WriteString(0,0,16,"input new passwd");
		//lcd1602WriteString(1,0,16,spaceString);
		getPasswd(inputBuf,PASSWDSIZE);
		lcd1602Clean();
		lcd1602WriteString(0,0,16,"repeat new:      ");		
		getPasswd(inputBuf1,PASSWDSIZE);		
		if(checkPasswd(inputBuf1,inputBuf,PASSWDSIZE))	{
			if(savePasswd(inputBuf,PASSWDSIZE)){
				lcd1602WriteString(0,0,16,"sucessed!");
				delayms(2000);	
				lcd1602Clean();	
			}
		    else{
				lcd1602WriteString(0,0,16,"rom Error   ");
				while(1);
			}
		}else{
			lcd1602Clean();
			lcd1602WriteString(1,0,16,"passwd not equel");
		}
			
	}else{
		lcd1602Clean();
		lcd1602WriteString(0,0,16,"passwd error");	
		delayms(1000);
	}
	
}

uchar* getPasswd(uchar buff[],uchar size)
{
	uchar i = 0;
	while(i<size){
		uchar key = getKey();
		if(key!= 0xff){
			buff[i++] = key;
			lcd1602WriteChar(1,6+i,'*');
		}
	}
	return buff;
}
void guard()
{	
	lcd1602Clean();
	lcd1602WriteString(0,0,6,"input:");
	getPasswd(inputBuf,PASSWDSIZE);
	if(checkPasswd(g_passwd,inputBuf,PASSWDSIZE)){
			open();
	}else{
		retryCount++;
		//lcd1602Clean();	
		lcd1602WriteString(1,0,10,"    error  ");
		delayms(1000);
		if(retryCount==3){
			alert();
			delayms(10000);
		}
	}
}

void open(void)
{
	lcd1602Clean();
	lcd1602WriteString(1,3,4,"open");
	delayms(2000);
}

uchar checkPasswd(uchar passwd[],uchar input[],uchar size)
{
	uchar i = OK;	
	for(i = 0;i < size;i++){
		if(passwd[i]!=input[i])	return FAILURE;
	}
	return OK;
}

void alert(void)
{
	lcd1602Clean();
	lcd1602WriteString(1,5,5,"alert");
}

uchar savePasswd(uchar passwd[],uchar size)
{
	uchar i,tmp[PASSWDSIZE];
	
	CAT02WriteMutiBytes(0x00,size,passwd);//写rom
	delay(300);
	CAT02ReadMutiBytes(0x00,size,tmp);//读回
	if(checkPasswd(tmp,passwd,size)){   //比较
		for(i=0;i<size;i++){
			g_passwd[i]=tmp[i];
		}
		return OK;
	}
	return FAILURE;	
}