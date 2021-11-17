#include "exti.h"
#include "delay.h"
#include "led.h"
#include "key.h"

//外部中断初始化
void EXTI_Init(void)
{
    GPIO_InitTypeDef GPIO_Init;
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();

    GPIO_Init.Pin = GPIO_PIN_0;           //PA0
    GPIO_Init.Mode = GPIO_MODE_IT_RISING; //上升沿触发
    GPIO_Init.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOA, &GPIO_Init);

    GPIO_Init.Pin = GPIO_PIN_13;           //PC13
    GPIO_Init.Mode = GPIO_MODE_IT_FALLING; //下降沿触发
    GPIO_Init.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC, &GPIO_Init);

    GPIO_Init.Pin = GPIO_PIN_2 | GPIO_PIN_3; //PH2,3
    HAL_GPIO_Init(GPIOH, &GPIO_Init);

    //中断线 0
    HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0); //抢占优先级为 2，子优先级为 0
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);         //使能中断线 0
    //中断线 2
    HAL_NVIC_SetPriority(EXTI2_IRQn, 2, 1); //抢占优先级为 2，子优先级为 0
    HAL_NVIC_EnableIRQ(EXTI2_IRQn);         //使能中断线 0
    //中断线 3
    HAL_NVIC_SetPriority(EXTI3_IRQn, 2, 2); //抢占优先级为 2，子优先级为 0
    HAL_NVIC_EnableIRQ(EXTI3_IRQn);         //使能中断线 0
    //中断线 13
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 3); //抢占优先级为 2，子优先级为 0
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);         //使能中断线 0
}

    //中断服务函数
    void EXTI0_IRQHandler(void)
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0); //调用中断处理公用函数
    }
    
    //中断服务函数
    void EXTI2_IRQHandler(void)
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2); //调用中断处理公用函数
    }

    //中断服务函数
    void EXTI3_IRQHandler(void)
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3); //调用中断处理公用函数
    }

    //中断服务函数
    void EXTI15_10_IRQHandler(void)
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13); //调用中断处理公用函数
    }

    //中断服务程序中需要做的事情
    //在 HAL 库中所有的外部中断服务函数都会调用此函数
    //GPIO_Pin:中断引脚序号
    void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
    {
        delay_ms(100); //消抖
        switch (GPIO_Pin)
        {
        case GPIO_PIN_0:
            if (WK_UP == 1)
            {
                LED1 = !LED1;
                LED0 = !LED1; //控制 LED0,LED1 互斥点亮
            }
            break;
        case GPIO_PIN_2:
            if (KEY1 == 0)
            {
                LED1 = !LED1; //LED1 翻转
            };
            break;
        case GPIO_PIN_3:
            if (KEY0 == 0)
            {
                LED0 = !LED0;
                LED1 = !LED1; //同时控制 LED0,LED1 翻转
            }
            break;
        case GPIO_PIN_13:
            if (KEY2 == 0)
            {
                LED0 = !LED0; //控制 LED0 翻转
            }
            break;
        }
    }
