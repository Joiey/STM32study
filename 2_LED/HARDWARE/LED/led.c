#include "led.h"
//��ʼ�� PB1 Ϊ���.��ʹ��ʱ��
//LED IO ��ʼ��
void LED_Init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	 __HAL_RCC_GPIOB_CLK_ENABLE(); //���� GPIOB ʱ��
	 GPIO_InitStruct.Pin=GPIO_PIN_0|GPIO_PIN_1; //PB1,0
	 GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_PP; //�������
	 GPIO_InitStruct.Pull=GPIO_PULLUP; //����
	 GPIO_InitStruct.Speed=GPIO_SPEED_HIGH; //����
   HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);
	 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET); //PB0 �� 1 ��Ĭ�ϵ���
	 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET); //PB1 �� 1 ��Ĭ�ϵ���
}
