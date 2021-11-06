#ifndef _UART_H_
#define _UART_H_
#include "ioCC2503.h"
#include "String.h"
//����ö��������
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
//����0��ʼ����
void UART0_Init(BaudSel baud);
//����0�ַ������ͺ���
void UART0_Send(char *Data,int len);
//ʮ������ת���ַ�����
void UART0_uNum(unsigned int uValue);
//��������ת���ַ�����
void UART0_fNum(float fValue);