#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"

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
     
    HAL_Init();                     //��ʼ��HAL��    
    Stm32_Clock_Init(360,25,2,8);   //����ʱ��,180Mhz
	delay_init(180);				//��ʼ����ʱ����
	LED_Init();						//��ʼ�� LED

	while(1)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);	//PB0��0��DS1�̵���
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);	//PB1��1��DS0���Ϩ 			
		delay_ms(1000);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);	//PB0��1��DS1�̵�Ϩ
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);	//PB1��0��DS0�����
		delay_ms(1000);
	}
	}

