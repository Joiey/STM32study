#ifndef __IWDG_H
#define __IWDG_H
#include "sys.h"
//初始化IWDG，并使能IWDG
void IWDG_Init(u8 prer, u16 rlr);
//喂狗
void IWDG_Feed(void);

#endif
