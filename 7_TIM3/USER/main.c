#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"

/************************************************
 ALIENTEK ������STM32F429������ʵ��0-1
 Template����ģ��-�½������½�ʹ��-HAL��汾
 ����֧�֣�www.openedv.com
 �Ա����̣� http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

int main(void)
{
	HAL_Init();						 //��ʼ��HAL��
	Stm32_Clock_Init(360, 25, 2, 8); //����ʱ��,180Mhz
	delay_init(180);				 //��ʼ����ʱ����
	uart_init(115200);				 //��ʼ�� USART
	LED_Init();						 //��ʼ�� LED
	TIM3_Init(5000 - 1, 9000 - 1);	 //��ʱ�� 3 ��ʼ������ʱ��ʱ��Ϊ 90M����Ƶϵ��Ϊ 8999��
	//���Զ�ʱ�� 3 ��Ƶ��Ϊ 90M/9000=10K���Զ���װ��Ϊ 4999����ʱ������=500ms

	while (1)
	{
		LED0 = !LED0;
		delay_ms(200);
	}
}
