//24c02.h

#ifndef _24C02_H
#define _24C02_H

#include "i2c.h"

#define CAT02RADDR 0xA1 
#define CAT02WADDR 0xA0 

sbit WP=P1^2;

unsigned char CAT02ReadByte(unsigned char addr);


void  CAT02WriteByte(unsigned char addr,
                   unsigned char value)	;

/* *******
*  功能： 读多个数据
   输入参数： addr 起始地址
              size  读数据个数
   输出参数： buff  读到的数据存区
   返回值：  实际读到的数据个数
   */


unsigned char CAT02ReadMutiBytes(unsigned char addr,
                          int size,
						  unsigned char *buf);	


/* *******
*  功能： 写多个数据
   输入参数： addr 起始地址
              size  读数据个数
   输出参数： buff  要写的数据存区
   返回值：  实际写的数据个数
   */

unsigned char CAT02WriteMutiBytes(unsigned char addr,
                          int size,
						  unsigned char *buf);

#endif