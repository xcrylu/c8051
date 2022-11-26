
#line 1 "mimasuo.c" /0
 
 
  
#line 1 ".\DRIVER\24C02.H" /0
 
 
 
 
 
  
#line 1 "\USERS\XIE_C\DESKTOP\ÃÜÂëËø\DRIVER\I2C.H" /0
 
 
 
 
 
  
#line 1 "C:\KEIL_V5-79\C51\INC\REG52.H" /0






 
 
 
 
 
 
 sfr P0    = 0x80;
 sfr P1    = 0x90;
 sfr P2    = 0xA0;
 sfr P3    = 0xB0;
 sfr PSW   = 0xD0;
 sfr ACC   = 0xE0;
 sfr B     = 0xF0;
 sfr SP    = 0x81;
 sfr DPL   = 0x82;
 sfr DPH   = 0x83;
 sfr PCON  = 0x87;
 sfr TCON  = 0x88;
 sfr TMOD  = 0x89;
 sfr TL0   = 0x8A;
 sfr TL1   = 0x8B;
 sfr TH0   = 0x8C;
 sfr TH1   = 0x8D;
 sfr IE    = 0xA8;
 sfr IP    = 0xB8;
 sfr SCON  = 0x98;
 sfr SBUF  = 0x99;
 
 
 sfr T2CON  = 0xC8;
 sfr RCAP2L = 0xCA;
 sfr RCAP2H = 0xCB;
 sfr TL2    = 0xCC;
 sfr TH2    = 0xCD;
 
 
 
 
 sbit CY    = PSW^7;
 sbit AC    = PSW^6;
 sbit F0    = PSW^5;
 sbit RS1   = PSW^4;
 sbit RS0   = PSW^3;
 sbit OV    = PSW^2;
 sbit P     = PSW^0;  
 
 
 sbit TF1   = TCON^7;
 sbit TR1   = TCON^6;
 sbit TF0   = TCON^5;
 sbit TR0   = TCON^4;
 sbit IE1   = TCON^3;
 sbit IT1   = TCON^2;
 sbit IE0   = TCON^1;
 sbit IT0   = TCON^0;
 
 
 sbit EA    = IE^7;
 sbit ET2   = IE^5;  
 sbit ES    = IE^4;
 sbit ET1   = IE^3;
 sbit EX1   = IE^2;
 sbit ET0   = IE^1;
 sbit EX0   = IE^0;
 
 
 sbit PT2   = IP^5;
 sbit PS    = IP^4;
 sbit PT1   = IP^3;
 sbit PX1   = IP^2;
 sbit PT0   = IP^1;
 sbit PX0   = IP^0;
 
 
 sbit RD    = P3^7;
 sbit WR    = P3^6;
 sbit T1    = P3^5;
 sbit T0    = P3^4;
 sbit INT1  = P3^3;
 sbit INT0  = P3^2;
 sbit TXD   = P3^1;
 sbit RXD   = P3^0;
 
 
 sbit SM0   = SCON^7;
 sbit SM1   = SCON^6;
 sbit SM2   = SCON^5;
 sbit REN   = SCON^4;
 sbit TB8   = SCON^3;
 sbit RB8   = SCON^2;
 sbit TI    = SCON^1;
 sbit RI    = SCON^0;
 
 
 sbit T2EX  = P1^1;  
 sbit T2    = P1^0;  
 
 
 sbit TF2    = T2CON^7;
 sbit EXF2   = T2CON^6;
 sbit RCLK   = T2CON^5;
 sbit TCLK   = T2CON^4;
 sbit EXEN2  = T2CON^3;
 sbit TR2    = T2CON^2;
 sbit C_T2   = T2CON^1;
 sbit CP_RL2 = T2CON^0;
 
 
#line 6 "\USERS\XIE_C\DESKTOP\ÃÜÂëËø\DRIVER\I2C.H" /0
 
 
 sbit SCL = P1^0;	 
 sbit SDA = P1^1;	 
 void I2C_Start(void) ; 				 
 void I2C_Stop(void);
 void I2C_ACK(void);	
 void I2C_NCK(void);
 unsigned char I2C_CheckACK(void);
 void I2C_WriteByte(unsigned char ch) ;
 unsigned char I2C_ReadByte(void);
 
#line 6 ".\DRIVER\24C02.H" /0
 
 
 
 
 
 sbit WP=P1^2;
 
 unsigned char C02ReadByte(unsigned char addr);
 
 
 void  C02WriteByte(unsigned char addr,
 unsigned char value)	;
 






 
 
 
 unsigned char C02ReadMutiBytes(unsigned char addr,
 int size,
 unsigned char *buf);	
 
 






 
 
 unsigned char C02WriteMutiBytes(unsigned char addr,
 int size,
 unsigned char *buf);
 
 
#line 3 "mimasuo.c" /0
 
  
#line 1 ".\DRIVER\I2C.H" /0
 
 
 
#line 4 ".\DRIVER\I2C.H" /1
  
 
  
 
 
 
 
 
 
 
 
 
 
 
#line 4 "mimasuo.c" /0
#line 4 "mimasuo.c" /0
 
  
#line 1 ".\DRIVER\KEY.H" /0
 
 
  
#line 1 "\USERS\XIE_C\DESKTOP\ÃÜÂëËø\DRIVER\COM.H" /0
 
 
 
 
  
#line 1 "C:\KEIL_V5-79\C51\INC\REG52.H" /0






 
 
 
#line 10 "C:\KEIL_V5-79\C51\INC\REG52.H" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 5 "\USERS\XIE_C\DESKTOP\ÃÜÂëËø\DRIVER\COM.H" /0
#line 5 "\USERS\XIE_C\DESKTOP\ÃÜÂëËø\DRIVER\COM.H" /0
 
  
#line 1 "C:\KEIL_V5-79\C51\INC\INTRINS.H" /0






 
 
 
 
 
 extern void          _nop_     (void);
 extern bit           _testbit_ (bit);
 extern unsigned char _cror_    (unsigned char, unsigned char);
 extern unsigned int  _iror_    (unsigned int,  unsigned char);
 extern unsigned long _lror_    (unsigned long, unsigned char);
 extern unsigned char _crol_    (unsigned char, unsigned char);
 extern unsigned int  _irol_    (unsigned int,  unsigned char);
 extern unsigned long _lrol_    (unsigned long, unsigned char);
 extern unsigned char _chkfloat_(float);
 extern void          _push_    (unsigned char _sfr);
 extern void          _pop_     (unsigned char _sfr);
 
 
 
#line 6 "\USERS\XIE_C\DESKTOP\ÃÜÂëËø\DRIVER\COM.H" /0
 
 
 
 
 
 
 
 
 
 
 
 void delay(unsigned int  i) ;	
 void delayus(unsigned int i );
 void delayms(unsigned int i); 
 
 
#line 3 ".\DRIVER\KEY.H" /0
 
 
 
 
  unsigned char getKey(void);
#line 5 "mimasuo.c" /0
 
  
#line 1 ".\DRIVER\LCD1602.H" /0
 
 
 
 
 
  
#line 1 "C:\KEIL_V5-79\C51\INC\REG52.H" /0






 
 
 
#line 10 "C:\KEIL_V5-79\C51\INC\REG52.H" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 6 ".\DRIVER\LCD1602.H" /0
#line 6 ".\DRIVER\LCD1602.H" /0
 
 
 
 sbit LCD_RS = P1^7;
 sbit LCD_RW = P1^6;
 sbit LCD_E  = P1^5;
 
 
 void lcd1602Init(void);
 
 void lcd1602WriteChar(unsigned char row,
 unsigned char col,
 char ch);
 



 
 void lcd1602WriteString(unsigned char   row,
 unsigned char   col,
 unsigned char   length,
 unsigned char   *str);
 
 
 
#line 6 "mimasuo.c" /0
 
  
#line 1 ".\DRIVER\SERIAL.H" /0
 
 
  
#line 1 "C:\KEIL_V5-79\C51\INC\REG52.H" /0






 
 
 
#line 10 "C:\KEIL_V5-79\C51\INC\REG52.H" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 3 ".\DRIVER\SERIAL.H" /0
#line 3 ".\DRIVER\SERIAL.H" /0
 
 
 
 
 
 void serialInit(void);   
 void serialSendByte(char c);
 void serialSendString(char* str);
 char serialReceive(void);
 
 
 
#line 7 "mimasuo.c" /0
 
  
#line 1 ".\DRIVER\DS18B20.H" /0
 
  
#line 1 "\USERS\XIE_C\DESKTOP\ÃÜÂëËø\DRIVER\COM.H" /0
 
 
 
#line 4 "\USERS\XIE_C\DESKTOP\ÃÜÂëËø\DRIVER\COM.H" /1
  
  
  
 
  
  
 
  
  
  
 
  
 
 
 
 
 
 
#line 2 ".\DRIVER\DS18B20.H" /0
#line 2 ".\DRIVER\DS18B20.H" /0
 
 
 
 
 
 sbit DQ = P1^4;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void 	wire1Reset(void);
  unsigned char  wire1Init(void);
 void 	wire1WriteBit1(void);
 void 	wire1WriteBit0(void);
  unsigned char 	wire1ReadBit(void);
 void 	wire1WriteByte(unsigned char);
  unsigned char 	wire1ReadByte(void);
 
 unsigned short ds18b20ReadTemperature(void);
 
 
 
 
 
#line 8 "mimasuo.c" /0
 
 
 
 char test[]="hello";
 char buff[20]={0};
 
 
 void main()
 {
 
 serialInit();
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 while(1)
 {
 
 
 
 
 
 
 
 
 unsigned value = ds18b20ReadTemperature();
  unsigned char temp1 = (unsigned char)(value/255);
  unsigned char temp2 = (unsigned char)(value%255);
 
 serialSendByte('a');
 
 
 };
 
 }
