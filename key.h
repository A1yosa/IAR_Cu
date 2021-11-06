#ifndef _KEY_H_
#define _KEY_H_
#include"ioCC2530.h"
#define KEY_1 P0_5
#define KEY_2 P0_4
#define KEY_3 P0_6
#define KEY_4 P0_3
#define Delay_time 65000
v0id Delay(Uunsigned int t);
void INIT_KEY(void);
unsigned char key_expriment(void);