#include "timer.h"
#include "delay.h"
#include "led.h"

TIM_HandleTypeDef TIM3_Handler;
TIM_OC_InitTypeDef TIM3_CH4Handler;

//PWM 输出初始化
//arr：自动重装值 psc：时钟预分频数

//通用定时器 3 中断初始化
//arr：自动重装值。 psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
//这里使用的是定时器 3!(定时器 3 挂在 APB1 上，时钟为 HCLK/2)
void TIM3_PWM_Init(u16 arr, u16 psc)
{
    TIM3_Handler.Instance = TIM3;
    TIM3_Handler.Init.Prescaler = psc;                        //分频系数
    TIM3_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;       //向上计数器
    TIM3_Handler.Init.Period = arr;                           //自动装载值
    TIM3_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1; //时钟分频因子
    HAL_TIM_PWM_Init(&TIM3_Handler);

    TIM3_CH4Handler.OCMode = TIM_OCMODE_PWM1;                                  //模式选择 PWM1
    TIM3_CH4Handler.Pulse = arr / 2;                                           //设置比较值,此值用来确定占空比
    TIM3_CH4Handler.OCPolarity = TIM_OCPOLARITY_LOW;                           //输出比较极性为低
    HAL_TIM_PWM_ConfigChannel(&TIM3_Handler, &TIM3_CH4Handler, TIM_CHANNEL_4); //配置 TIM3 通道 4
    HAL_TIM_PWM_Start(&TIM3_Handler, TIM_CHANNEL_4);                           //开启 PWM 通道 4
}

//定时器底层驱动，开启时钟，设置中断优先级
//此函数会被 HAL_TIM_PWM_MspInit()函数调用
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
    GPIO_InitTypeDef GPIO_Initstruct;
    __HAL_RCC_TIM3_CLK_ENABLE();               //使能 TIM3 时钟
    __HAL_RCC_GPIOB_CLK_ENABLE();              //开启 GPIOB 时钟
    GPIO_Initstruct.Pin = GPIO_PIN_1;          //PB1
    GPIO_Initstruct.Mode = GPIO_MODE_AF_PP;    //复用推挽输出
    GPIO_Initstruct.Pull = GPIO_PULLUP;        //上拉
    GPIO_Initstruct.Speed = GPIO_SPEED_HIGH;   //高速
    GPIO_Initstruct.Alternate = GPIO_AF2_TIM3; //PB1 复用为 TIM3_CH4
    HAL_GPIO_Init(GPIOB, &GPIO_Initstruct);
}

//设置 TIM 通道 4 的占空比
//compare:比较值
void TIM_SetTIM3Compare4(u32 compare)
{
    TIM3->CCR4 = compare;
}
