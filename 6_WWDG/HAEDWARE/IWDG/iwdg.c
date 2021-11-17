#include "iwdg.h"

IWDG_HandleTypeDef iwdg_handle;
//
void IWDG_Init(u8 prer, u16 rlr)
{
    iwdg_handle.Instance = IWDG;
    iwdg_handle.Init.Prescaler = prer; //设置 IWDG 分频系数
    iwdg_handle.Init.Reload = rlr;     //重装载值,溢出时间Tout=((4×2^prer) ×rlr) /32
    HAL_IWDG_Init(&iwdg_handle);

    HAL_IWDG_Start(&iwdg_handle); //开启独立看门狗
}

//喂狗
void IWDG_Feed(void)
{
    HAL_IWDG_Refresh(&iwdg_handle);
}
