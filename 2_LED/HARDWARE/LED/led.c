#include "led.h"
//初始化 PB1 为输出.并使能时钟
//LED IO 初始化
void LED_Init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	 __HAL_RCC_GPIOB_CLK_ENABLE(); //开启 GPIOB 时钟
	 GPIO_InitStruct.Pin=GPIO_PIN_0|GPIO_PIN_1; //PB1,0
	 GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_PP; //推挽输出
	 GPIO_InitStruct.Pull=GPIO_PULLUP; //上拉
	 GPIO_InitStruct.Speed=GPIO_SPEED_HIGH; //高速
   HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);
	 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET); //PB0 置 1 ，默认灯灭
	 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET); //PB1 置 1 ，默认灯灭
}
