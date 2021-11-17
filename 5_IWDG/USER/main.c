#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "iwdg.h"
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
	HAL_Init();						   //初始化HAL库
	Stm32_Clock_Init(360, 25, 2, 8);   //设置时钟,180Mhz
	delay_init(180);				   //初始化延时函数
	uart_init(115200);				   //初始化 USART
	LED_Init();						   //初始化 LED
	KEY_Init();						   //初始化KEY
	delay_ms(100);					   //延时 100ms 再初始化看门狗,LED0 的变化"可见"
	IWDG_Init(IWDG_PRESCALER_64, 500); //分频数为 64,重载值为 500,溢出时间为 1s

	//不是准确的32Khz
	LED0 = 0; //红灯亮
	LED1 = 0; //红灯亮
	while (1)
	{
		if (KEY_Scan(0) == WKUP_PRES) //如果 WK_UP 按下，喂狗							   //每隔 1s 打印一次
		{
			IWDG_Feed(); //喂狗
		}
		delay_ms(10);
	}
}
