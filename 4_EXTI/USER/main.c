#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "exti.h"

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
	EXTI_Init();					 //外部中断初始化

	//在 while 死循环中不停的打印字符串到串口。
	//当有某个外部按键按下之后，会触发中断服务函数做出相应的反应。
	while (1)
	{
		printf("OK,每隔1s打印一次OK提示程序运行\r\n"); //打印 OK 提示程序运行
		delay_ms(1000);									   //每隔 1s 打印一次
	}
}
