#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"

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
	HAL_Init();						 //初始化HAL库
	Stm32_Clock_Init(360, 25, 2, 8); //设置时钟,180Mhz
	delay_init(180);				 //初始化延时函数
	uart_init(115200);				 //初始化 USART
	LED_Init();						 //初始化 LED
	TIM3_Init(5000 - 1, 9000 - 1);	 //定时器 3 初始化，定时器时钟为 90M，分频系数为 8999，
	//所以定时器 3 的频率为 90M/9000=10K，自动重装载为 4999，定时器周期=500ms

	while (1)
	{
		LED0 = !LED0;
		delay_ms(200);
	}
}
