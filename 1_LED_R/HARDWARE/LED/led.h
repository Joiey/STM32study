#ifndef __LED_H
#define __LED_H
#include "sys.h"

//LED端口定义
#define LED0 PBout(1) // DS0
#define LED1 PBout(0) // DS1

void LED_Init(void);

#endif
