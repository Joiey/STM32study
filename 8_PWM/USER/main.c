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
	u8 dir = 1;
	u16 led0pwmval = 0;
	HAL_Init();						 //初始化HAL库
	Stm32_Clock_Init(360, 25, 2, 8); //设置时钟,180Mhz
	delay_init(180);				 //初始化延时函数
	uart_init(115200);				 //初始化 USART
	LED_Init();						 //初始化 LED
	TIM3_PWM_Init(500 - 1, 90 - 1);	 //90M/90=1M 的计数频率，自动重装载为 500
									 //那么 PWM 频率为 1M/500=2kHZ
	while (1)
	{
		delay_ms(10);
		if (dir)
			led0pwmval++; //
		else
			led0pwmval--; //
		if (led0pwmval > 300) //led0pwmval 到达 300 后，方向为递减
			dir = 0;
		if (led0pwmval == 0) //led0pwmval 递减到 0 后，方向改为递增
			dir = 1;
		TIM_SetTIM3Compare4(led0pwmval); //修改比较值，修改占空比
	}
}
