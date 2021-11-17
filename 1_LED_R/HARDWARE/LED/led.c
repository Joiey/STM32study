#include "led.h"

//初始化 PB0 和 PB1 为输出口.并使能这两个口的时钟
//LED IO 初始化
void LED_Init(void){
    RCC->AHB1ENR |= 1 << 1; //使能 PORTB 时钟
    GPIO_Set(GPIOB, PIN0 | PIN1, GPIO_MODE_OUT, GPIO_OTYPE_PP,
             GPIO_SPEED_100M, GPIO_PUPD_PU); //PB0,PB1 设置
    LED0 = 1;                                //LED0 关闭
    LED1 = 1;                                //LED1 关闭
}