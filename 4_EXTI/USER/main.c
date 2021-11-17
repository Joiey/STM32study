#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "exti.h"

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
	EXTI_Init();					 //�ⲿ�жϳ�ʼ��

	//�� while ��ѭ���в�ͣ�Ĵ�ӡ�ַ��������ڡ�
	//����ĳ���ⲿ��������֮�󣬻ᴥ���жϷ�����������Ӧ�ķ�Ӧ��
	while (1)
	{
		printf("OK,ÿ��1s��ӡһ��OK��ʾ��������\r\n"); //��ӡ OK ��ʾ��������
		delay_ms(1000);									   //ÿ�� 1s ��ӡһ��
	}
}
