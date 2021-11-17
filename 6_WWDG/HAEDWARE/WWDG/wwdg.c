#include "wwdg.h"
#include "led.h"

WWDG_HandleTypeDef WWDG_Handler;
u8 WWDG_CNT = 0X7F; //保存 WWDG 计数器的设置值，默认为最大

//初始化窗口看门狗
//tr :T[6:0],计数器值 wr :W[6:0],窗口值 fprer:分频系数（WDGTB）,仅最低 2 位有效
//Fwwdg=PCLK1/(4096*2^fprer). 一般 PCLK1=45Mhz
void WWDG_Init(u8 tr, u8 wr, u32 fprer)
{
    WWDG_Handler.Instance = WWDG;
    WWDG_Handler.Init.Prescaler = fprer; //设置分频系数
    WWDG_Handler.Init.Window = wr;       //设置窗口值
    WWDG_Handler.Init.Counter = tr;      //设置计数器值
    HAL_WWDG_Init(&WWDG_Handler);        //初始化 WWDG
    HAL_WWDG_Start_IT(&WWDG_Handler);    //开启窗口看门狗
}

//WWDG 底层驱动，时钟配置，中断配置
//此函数会被 HAL_WWDG_Init()调用
void HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg)
{
    __HAL_RCC_WWDG_CLK_ENABLE();           //使能窗口看门狗时钟
    
    HAL_NVIC_SetPriority(WWDG_IRQn, 2, 3); //抢占优先级 2，子优先级为 3
    HAL_NVIC_EnableIRQ(WWDG_IRQn);         //使能窗口看门狗中断
}

//窗口看门狗中断服务函数
void WWDG_IRQHandler(void)
{
    HAL_WWDG_IRQHandler(&WWDG_Handler);
}

//中断服务函数处理过程,此函数会被 HAL_WWDG_IRQHandler()调用
void HAL_WWDG_WakeupCallback(WWDG_HandleTypeDef *hwwdg)
{
    HAL_WWDG_Refresh(&WWDG_Handler, WWDG_CNT); //更新窗口看门狗值
    LED1 = !LED1;                              //LED1翻转
}