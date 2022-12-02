//ds1302.h

#include "com.h"

#ifndef _DS1302_H
#define _DS1203_H

sbit SCK = P3^6;
sbit IO = P3^7;
sbit CE = P3^5;

void DS1302Init(uchar timeBuff[7]);
void DS1302WriteByte(uchar dat);
void DS1302Write(uchar addr,uchar value);
uchar DS1302ReadByte(void);
uchar DS1302Read(uchar addr);
void DS1302ReadTime(uchar buff[7]);
//突发读/写， 
// 读写时钟时需要一次读写全部8个字节
// 读写ram无要求
// mode ：1 时钟
// mode : 0 ram

void DS1302WriteBurst(char mode,uchar size, uchar buff[]);
void DS1302ReadBurst(char mode,uchar size,uchar buff[]);

#endif