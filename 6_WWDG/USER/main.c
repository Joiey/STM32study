#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "wwdg.h"
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
	HAL_Init();						   //��ʼ��HAL��
	Stm32_Clock_Init(360, 25, 2, 8);   //����ʱ��,180Mhz
	delay_init(180);				   //��ʼ����ʱ����
	uart_init(115200);				   //��ʼ�� USART
	LED_Init();						   //��ʼ�� LED
	KEY_Init();						   //��ʼ��KEY
	
	LED0 = 0; //�����
	delay_ms(300);					   //��ʱ 100ms �ٳ�ʼ�����Ź�,LED0 �ı仯"�ɼ�"
	WWDG_Init(0X7F, 0X5F, WWDG_PRESCALER_8); //������ֵΪ 7F������ 5F��8 ��Ƶ

	while (1)
	{
		LED0 = 1;//LED0��,�����
	}
}
