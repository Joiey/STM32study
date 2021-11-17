#include "timer.h"
#include "delay.h"
#include "led.h"
#include "key.h"

TIM_HandleTypeDef TIM3_Handler;
//ͨ�ö�ʱ�� 3 �жϳ�ʼ��
//arr���Զ���װֵ�� psc��ʱ��Ԥ��Ƶ��
//��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=��ʱ������Ƶ��,��λ:Mhz
//����ʹ�õ��Ƕ�ʱ�� 3!(��ʱ�� 3 ���� APB1 �ϣ�ʱ��Ϊ HCLK/2)
void TIM3_Init(u16 arr, u16 psc)
{
    TIM3_Handler.Instance = TIM3;
    TIM3_Handler.Init.Prescaler = psc;                        //��Ƶϵ��
    TIM3_Handler.Init.CounterMode = TIM_COUNTERMODE_UP;       //���ϼ�����
    TIM3_Handler.Init.Period = arr;                           //�Զ�װ��ֵ
    TIM3_Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1; //ʱ�ӷ�Ƶ����

    HAL_TIM_Base_Init(&TIM3_Handler);

    HAL_TIM_Base_Start_IT(&TIM3_Handler); //ʹ�ܶ�ʱ�� 3 �Ͷ�ʱ�� 3 �����ж�
}

//��ʱ���ײ�����������ʱ�ӣ������ж����ȼ�
//�˺����ᱻ HAL_TIM_Base_Init()��������
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    __HAL_RCC_TIM3_CLK_ENABLE(); //ʹ�� TIM3 ʱ��

    HAL_NVIC_SetPriority(TIM3_IRQn, 1, 3); //��ռ���ȼ�Ϊ 2�������ȼ�Ϊ 0
    HAL_NVIC_EnableIRQ(TIM3_IRQn);         //���� ITM3 �ж�
}

//�жϷ�����
void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TIM3_Handler); //�����жϴ����ú���
}

//��ʱ�� 3 �жϷ���������
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == (&TIM3_Handler))
    {
        LED1 = !LED1; //LED1 ��ת
    }
}
