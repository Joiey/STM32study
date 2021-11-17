#include "timer.h"
#include "delay.h"
#include "led.h"

TIM_HandleTypeDef TIM3_Handler;
TIM_OC_InitTypeDef TIM3_CH4Handler;

//PWM �����ʼ��
//arr���Զ���װֵ psc��ʱ��Ԥ��Ƶ��

//ͨ�ö�ʱ�� 3 �жϳ�ʼ��
//arr���Զ���װֵ�� psc��ʱ��Ԥ��Ƶ��
//��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=��ʱ������Ƶ��,��λ:Mhz
//����ʹ�õ��Ƕ�ʱ�� 3!(��ʱ�� 3 ���� APB1 �ϣ�ʱ��Ϊ HCLK/2)
void TIM3_PWM_Init(u16 arr, u16 psc)
{
    TIM3_Handler.Instance = TIM3;
    TIM3_Handler.Init.Prescaler = psc;                        //��Ƶϵ��
    TIM3_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;       //���ϼ�����
    TIM3_Handler.Init.Period = arr;                           //�Զ�װ��ֵ
    TIM3_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1; //ʱ�ӷ�Ƶ����
    HAL_TIM_PWM_Init(&TIM3_Handler);

    TIM3_CH4Handler.OCMode = TIM_OCMODE_PWM1;                                  //ģʽѡ�� PWM1
    TIM3_CH4Handler.Pulse = arr / 2;                                           //���ñȽ�ֵ,��ֵ����ȷ��ռ�ձ�
    TIM3_CH4Handler.OCPolarity = TIM_OCPOLARITY_LOW;                           //����Ƚϼ���Ϊ��
    HAL_TIM_PWM_ConfigChannel(&TIM3_Handler, &TIM3_CH4Handler, TIM_CHANNEL_4); //���� TIM3 ͨ�� 4
    HAL_TIM_PWM_Start(&TIM3_Handler, TIM_CHANNEL_4);                           //���� PWM ͨ�� 4
}

//��ʱ���ײ�����������ʱ�ӣ������ж����ȼ�
//�˺����ᱻ HAL_TIM_PWM_MspInit()��������
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
    GPIO_InitTypeDef GPIO_Initstruct;
    __HAL_RCC_TIM3_CLK_ENABLE();               //ʹ�� TIM3 ʱ��
    __HAL_RCC_GPIOB_CLK_ENABLE();              //���� GPIOB ʱ��
    GPIO_Initstruct.Pin = GPIO_PIN_1;          //PB1
    GPIO_Initstruct.Mode = GPIO_MODE_AF_PP;    //�����������
    GPIO_Initstruct.Pull = GPIO_PULLUP;        //����
    GPIO_Initstruct.Speed = GPIO_SPEED_HIGH;   //����
    GPIO_Initstruct.Alternate = GPIO_AF2_TIM3; //PB1 ����Ϊ TIM3_CH4
    HAL_GPIO_Init(GPIOB, &GPIO_Initstruct);
}

//���� TIM ͨ�� 4 ��ռ�ձ�
//compare:�Ƚ�ֵ
void TIM_SetTIM3Compare4(u32 compare)
{
    TIM3->CCR4 = compare;
}
