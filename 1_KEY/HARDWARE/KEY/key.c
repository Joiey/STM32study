#include "key.h"
#include "delay.h"

//������ʼ������
void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    __HAL_RCC_GPIOA_CLK_ENABLE(); //���� GPIOA ʱ��
    __HAL_RCC_GPIOC_CLK_ENABLE(); //���� GPIOC ʱ��
    __HAL_RCC_GPIOH_CLK_ENABLE(); //���� GPIOH ʱ��

    GPIO_InitStructure.Pin = GPIO_PIN_0; //PA0
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_PULLDOWN;
    GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = GPIO_PIN_13; //PC13
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = GPIO_PIN_2 | GPIO_PIN_3; //PH2,3
    HAL_GPIO_Init(GPIOH, &GPIO_InitStructure);
}

//����������
//mode:0,��֧��������;1,֧��������;
//���ذ���ֵ��0��û���κΰ������� 1��WKUP ���� WK_UP
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>WK_UP!!
u8 KEY_Scan(u8 mode)
{
    static u8 key_up = 1; //�����ɿ���־
    if (mode == 1)
        key_up = 1; //֧������
    if (key_up && (KEY0 == 0 || KEY1 == 0 || KEY2 == 0 || WK_UP == 1))
    {
        delay_ms(10);
        key_up = 0;
        if (KEY0 == 0)
            return KEY0_PRES;
        else if (KEY1 == 0)
            return KEY1_PRES;
        else if (KEY2 == 0)
            return KEY2_PRES;
        else if (WK_UP == 1)
            return WKUP_PRES;
    }
    else if (KEY0 == 1 && KEY1 == 1 && KEY2 == 1 && WK_UP == 0)
        key_up = 1;
    return 0; //�ް�������
}