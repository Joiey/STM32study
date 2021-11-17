#include "sys.h" 
#include "usart.h" 
#include "delay.h" 
#include "led.h"
//ALIENTEK ������STM32F429������ ʵ��0
//�½�����ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾

int main(void)
{ 
	Stm32_Clock_Init(360,25,2,8);	//����ʱ��,180Mhz
	delay_init(180);				//��ʼ����ʱ����
	uart_init(90,115200);			//���ڳ�ʼ��Ϊ115200
	LED_Init();						//��ʼ�� LED ʱ��

	while(1)
	{
		LED0 = 0;
		LED1 = 1;
		delay_ms(500);
		LED0 = !LED0;
		LED1 = !LED1;
		delay_ms(500);
	}
}
