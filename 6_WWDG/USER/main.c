#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "wwdg.h"
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
	
	LED0 = 0; //红灯亮
	delay_ms(300);					   //延时 100ms 再初始化看门狗,LED0 的变化"可见"
	WWDG_Init(0X7F, 0X5F, WWDG_PRESCALER_8); //计数器值为 7F，窗口 5F，8 分频

	while (1)
	{
		LED0 = 1;//LED0灭,红灯灭
	}
}
