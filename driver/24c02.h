//24c02.h

#ifndef _24C02_H
#define _24C02_H

#include "i2c.h"

#define C02RADDR 0xA1 
#define C02WADDR 0xA0 

sbit WP=P1^2;

unsigned char C02ReadByte(unsigned char addr);


void  C02WriteByte(unsigned char addr,
                   unsigned char value)	;

/* *******
*  ���ܣ� ���������
   ��������� addr ��ʼ��ַ
              size  �����ݸ���
   ��������� buff  ���������ݴ���
   ����ֵ��  ʵ�ʶ��������ݸ���
   */


unsigned char C02ReadMutiBytes(unsigned char addr,
                          int size,
						  unsigned char *buf);	


/* *******
*  ���ܣ� д�������
   ��������� addr ��ʼ��ַ
              size  �����ݸ���
   ��������� buff  Ҫд�����ݴ���
   ����ֵ��  ʵ��д�����ݸ���
   */

unsigned char C02WriteMutiBytes(unsigned char addr,
                          int size,
						  unsigned char *buf);

#endif