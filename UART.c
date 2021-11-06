#include "UART.h"
//串口0初始函数
void UART0_Init(BaudSel baud){
  CLKCONCMD &= ~0x40;//32MHZ晶振为主时钟频率
  while(!(SLEEPSTA & 0x40))//等待32MHZ晶振稳定
    ;
  CLKCONCMD &= ~0x47;//主频率不分频，定时器128分频
 SLEEPCMD |= 0x04;//关闭不用的RC振荡器
 PERCFG = 0x00;//将串口0位置置1，即P0端口
 P0SEL |= 0x0C;//p0_2,P0_3置1；
 switch(baud){
 case BAUD_2400: U0GCR |= 6; U0BAUD |=59;break;
 case BAUD_4800: U0GCR |= 7; U0BAUD |=59;break;
 case BAUD_9600: U0GCR |= 8; U0BAUD |=59;break;
 case BAUD_14400: U0GCR |= 8; U0BAUD |=59;break;
 case BAUD_19200: U0GCR |= 9; U0BAUD |=59;break;
 case BAUD_28800: U0GCR |= 9; U0BAUD |=216;break;
 case BAUD_38400: U0GCR |= 10; U0BAUD |=59;break;
 case BAUD_57600: U0GCR |= 10; U0BAUD |=216;break;
 case BAUD_78600: U0GCR |= 11; U0BAUD |=59;break;
 case BAUD_115200: U0GCR |= 11; U0BAUD |=216;break;
 case BAUD_230400: U0GCR |= 12; U0BAUD |=216;break;
 } 
 UTX0IF = 0;//传输完成标志位请0
 U0CSR |= 0x40;//允许接收
 IEN0 |= 0x84;//开启总中断，串口0接收中断使能
 
//串口0字符串发送函数
void UART0_Send(char *Data,int len){
  int i;
  for(i=0;i<len;i++{
    U0DBUF = *Data++;
    while(UTX0IF==0)
      ;
    UTX0IF=0;
  }
  
}
//十进制数转换字符函数
void UART0_uNum(unsigned int uValue){
  //0~99999的十进制数转换成字符输出
  unsigned char i;
  char cData[5]={'0','0','0','0','0'};
  cData[0]=uValue%100000/10000+'0';
  cData[0]=uValue%10000/1000+'0';
  cData[0]=uValue%1000/100+'0';
  cData[0]=uValue%100/10+'0';
  cData[0]=uValue%10/1+'0';
  if(0!==uValue){
    unsigned int count=o;
    for(i=0;i<5;i++){
      if('0'!=cData[i])
        break;
      if('0'==cData[i])
        count++;
    }
    for(unsigned int j=0;j<count;j++){
      cData[j]='';
    }
  }
  else if(0==uValue){
    for(i=0;i<4;i++){
      cData[i]='';
    }
  }
  UART0_Send("",1);
  UART0_Send(cData,5):
  UART0_Send("",1);
  
}
//浮点数据转换字符函数
void UART0_fNum(float fValue){
  unsigned int uValue=(unsigned int)(100*fValue);
  char cData[5]={'0','0','.','0','0'};
  cData[0]=uValue%10000/1000+'0';
  cData[1]=uValue%1000/100+'0';
  cData[2]=uValue%'.';
  cData[3]=uValue%100/10+'0';
  cData[4]=uValue%10/1+'0';
  UART0_Send("",1);
  UART0_Send(cData,5):
  UART0_Send("",1);
}
      
//接收完成中断函数
#pragma vector=URX0_XECTOR
      __interrupt void UART0_ISR(void){