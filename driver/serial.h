////serial.h

#include <reg52.h>

#ifndef _SERIAL_H
#define _SERIAL_H

  void serialInit(void);  //波特率9600
  void serialSendByte(char c);
  void serialSendString(char* str);
  char serialReceive(void);


#endif 