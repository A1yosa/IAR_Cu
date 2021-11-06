#ifndef _UART_H_
#define _UART_H_
#include "ioCC2503.h"
#include "String.h"
//定义枚举型数据
typedef enum{
  BAUD_2400,
  BAUD_4800,
  BAUD_9600,
  BAUD_14400,
  BAUD_19200,
  BAUD_28800,
  BAUD_38400,
  BAUD_57600,
  BAUD_76800,
  BAUD_115200,
  BAUD_230400
  }BuadSel;
//串口0初始函数
void UART0_Init(BaudSel baud);
//串口0字符串发送函数
void UART0_Send(char *Data,int len);
//十进制数转换字符函数
void UART0_uNum(unsigned int uValue);
//浮点数据转换字符函数
void UART0_fNum(float fValue);