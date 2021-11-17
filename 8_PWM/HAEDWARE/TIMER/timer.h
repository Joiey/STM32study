#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"

//外部中断初始化
void TIM3_PWM_Init(u16 arr, u16 psc);
void TIM_SetTIM3Compare4(u32 compare);
#endif
