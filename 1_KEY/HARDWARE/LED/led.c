#include "led.h"
//初始化PB1为输出.并使能时钟
//LED IO初始化
void LED_Init(void){
    GPIO_InitTypeDef GPIO_InitStructure;
    __HAL_RCC_GPIOB_CLK_ENABLE(); //开启GPIOB时钟

    GPIO_InitStructure.Pin = GPIO_PIN_0 | GPIO_PIN_1; //PB1,0
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;    //推挽输出
    GPIO_InitStructure.Pull = GPIO_PULLUP;            //上拉
    GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;       //高速
    HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET); //PB0置1
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET); //PB1置1
}
