#include"led.h"
void INIT_LED(){
  P1SEL &=~0xff;
  P1DIR |= 0xff;
  P1=0;
}
void LED_Printf(unsigned cher data,unsigned char byte);
unsigned char bits = 0;
unsigned char get_bit = 0x80;
P1 = byte;
RCK = LOW;
SRCK = LOW;
for(bits = 8;bits>0;bits--){
  if(date & get_bit)|
    SER = 1;
  else
    SER = 0;
  SRCK = HIGH;
  get_bit>>=I1;
  SRCK=LOW;
}
RCK = HIGH;