#include "key.h"
v0id Delay(Uunsigned int t){
  while(t--)
    ;
  
}
void INIT_KEY(void){
  P0SEL &= ~0x78;
  P0DIR &= ~0x78;
  P0INP &= ~0x78;
  P2NP &= ~0x20;
}
unsigned char key_expriment(void){
  unsigned char key = 0;
  key = P0;
  Delay(Delay_time);
  Delay(Delay_time);
  key = P0;
  key &= 0x78;
  switch(key){
  case 0x58:
    Delay(Delay_time);
    Delay(Delay_time);
    key = P0;
    if(key & 0x20)
      return(KEY_1);
    break;
  case 0x68:
    Delay(Delay_time);
    Delay(Delay_time);
    key = P0;
    if(key & 0x10)
      return(KEY_2);
    break;
  case 0x38:
    Delay(Delay_time);
    Delay(Delay_time);
    key = P0;
    if(key & 0x40)
      return(KEY_3);
    break;
  case 0x70:
    Delay(Delay_time);
    Delay(Delay_time);
    key = P0;
    if(key & 0x08)
      return(KEY_4);
    break;
  default:break;
  
  }
   return 0;