#include"ioCC2530.h"
#include"UART.h"
//ÑÓÊ±º¯Êý
void Delay(unsigned int i){
  unsigned int j,k,f;
  for(j=0;j<i;j++)
    for(k=0;k<i;k++)
      for(f=0;f<i;f++)
        ;
}
void main(){
#define SENDSTRING"hello world"
  SENDSTRING,sizeof(SENDSTRING)-1);