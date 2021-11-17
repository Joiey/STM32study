#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
/************************************************
 ALIENTEK 阿波罗STM32F429开发板实验0-1
 Template工程模板-新建工程章节使用-HAL库版本
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

int main(void)
{
    u8 key;
    HAL_Init();                      //初始化 HAL 库
    Stm32_Clock_Init(360, 25, 2, 8); //设置时钟,180Mhz
    delay_init(180);                 //初始化延时函数
    uart_init(115200);               //初始化 USART
    LED_Init();                      //初始化 LED
    KEY_Init();                      //初始化按键
    while(1)
	{
        key = KEY_Scan(0); //按键扫描
        switch (key)
        {
        case WKUP_PRES: //控制 LED0,LED1 互斥点亮
            LED1 = !LED1;
            LED0 = !LED1;
            break;
        case KEY2_PRES: //控制 LED0 翻转
            LED0 = !LED0;
            break;
        case KEY1_PRES: //控制 LED1 翻转
            LED1 = !LED1;
            break;
        case KEY0_PRES: //同时控制 LED0,LED1 翻转
            LED0 = !LED0;
            LED1 = !LED1;
            break;
        }
        delay_ms(10);
    }
}
