#include "exti.h"
#include "delay.h"
#include "led.h"
#include "key.h"

//�ⲿ�жϳ�ʼ��
void EXTI_Init(void)
{
    GPIO_InitTypeDef GPIO_Init;
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();

    GPIO_Init.Pin = GPIO_PIN_0;           //PA0
    GPIO_Init.Mode = GPIO_MODE_IT_RISING; //�����ش���
    GPIO_Init.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOA, &GPIO_Init);

    GPIO_Init.Pin = GPIO_PIN_13;           //PC13
    GPIO_Init.Mode = GPIO_MODE_IT_FALLING; //�½��ش���
    GPIO_Init.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC, &GPIO_Init);

    GPIO_Init.Pin = GPIO_PIN_2 | GPIO_PIN_3; //PH2,3
    HAL_GPIO_Init(GPIOH, &GPIO_Init);

    //�ж��� 0
    HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0); //��ռ���ȼ�Ϊ 2�������ȼ�Ϊ 0
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);         //ʹ���ж��� 0
    //�ж��� 2
    HAL_NVIC_SetPriority(EXTI2_IRQn, 2, 1); //��ռ���ȼ�Ϊ 2�������ȼ�Ϊ 0
    HAL_NVIC_EnableIRQ(EXTI2_IRQn);         //ʹ���ж��� 0
    //�ж��� 3
    HAL_NVIC_SetPriority(EXTI3_IRQn, 2, 2); //��ռ���ȼ�Ϊ 2�������ȼ�Ϊ 0
    HAL_NVIC_EnableIRQ(EXTI3_IRQn);         //ʹ���ж��� 0
    //�ж��� 13
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 3); //��ռ���ȼ�Ϊ 2�������ȼ�Ϊ 0
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);         //ʹ���ж��� 0
}

    //�жϷ�����
    void EXTI0_IRQHandler(void)
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0); //�����жϴ����ú���
    }
    
    //�жϷ�����
    void EXTI2_IRQHandler(void)
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2); //�����жϴ����ú���
    }

    //�жϷ�����
    void EXTI3_IRQHandler(void)
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3); //�����жϴ����ú���
    }

    //�жϷ�����
    void EXTI15_10_IRQHandler(void)
    {
        HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13); //�����жϴ����ú���
    }

    //�жϷ����������Ҫ��������
    //�� HAL �������е��ⲿ�жϷ�����������ô˺���
    //GPIO_Pin:�ж��������
    void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
    {
        delay_ms(100); //����
        switch (GPIO_Pin)
        {
        case GPIO_PIN_0:
            if (WK_UP == 1)
            {
                LED1 = !LED1;
                LED0 = !LED1; //���� LED0,LED1 �������
            }
            break;
        case GPIO_PIN_2:
            if (KEY1 == 0)
            {
                LED1 = !LED1; //LED1 ��ת
            };
            break;
        case GPIO_PIN_3:
            if (KEY0 == 0)
            {
                LED0 = !LED0;
                LED1 = !LED1; //ͬʱ���� LED0,LED1 ��ת
            }
            break;
        case GPIO_PIN_13:
            if (KEY2 == 0)
            {
                LED0 = !LED0; //���� LED0 ��ת
            }
            break;
        }
    }
