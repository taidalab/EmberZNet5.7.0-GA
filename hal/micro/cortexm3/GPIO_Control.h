/*******************************************************************************
* �ļ����ƣ�GPIO_Control.h
* �ļ����������ļ������к����ͺ궨�����ڶ�EM357��GPIO�ڽ��п���
* �����Ա��������
* ������ڣ�20140609
* �޸ļ�¼��
*******************************************************************************/
#ifndef _GPIO_CONTROL_H
#define _GPIO_CONTROL_H

#include "app/framework/include/af.h"
//����ʹ�õĹܽ�ģʽ�У�
/*
   GPIOCFG_OUT          //�������
   GPIOCFG_OUT_OD      //©����·���
   GPIOCFG_OUT_ALT     //������������
  GPIOCFG_OUT_ALT_OD   //����Ŀ�©���
  GPIOCFG_ANALOG    //ģ���źţ��������ź�Ϊ1
  GPIOCFG_IN       //��������
 GPIOCFG_IN_PUD     //���룺������������д1��������д0������
*/

//����ʹ�õĹܽŶ�������--------------------------------------------------------
#define GPIO_PIN_7 (0x00000080u)
#define GPIO_PIN_6 (0x00000040u)
#define GPIO_PIN_5 (0x00000020u)
#define GPIO_PIN_4 (0x00000010u)
#define GPIO_PIN_3 (0x00000008u)
#define GPIO_PIN_2 (0x00000004u)
#define GPIO_PIN_1 (0x00000002u)
#define GPIO_PIN_0 (0x00000001u)

#define GPIO_PINS_ALL 0x00ff

/*******************************************************************************
* �������ƣ�GPIO_A_SET
* �����������趨PAָ���ܽŵ����ֵΪ1
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						GPIO_PINS_ALL
* �����������
* ע���������ʹ��"|"����ͬʱ���ü����ܽ�
*******************************************************************************/
#define  GPIO_A_SET(GPIO_ID) 		 GPIO_PASET |= (int16u)GPIO_ID	
/*******************************************************************************
* �������ƣ�GPIO_B_SET
* �����������趨PBָ���ܽŵ����ֵΪ1
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						GPIO_PINS_ALL
* �����������
* ע���������ʹ��"|"����ͬʱ���ü����ܽ�
*******************************************************************************/
#define  GPIO_B_SET(GPIO_ID) 		 GPIO_PBSET |= (int16u)GPIO_ID	
/*******************************************************************************
* �������ƣ�GPIO_C_SET
* �����������趨PCָ���ܽŵ����ֵΪ1
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						GPIO_PINS_ALL
* �����������
* ע���������ʹ��"|"����ͬʱ���ü����ܽ�
*******************************************************************************/
#define  GPIO_C_SET(GPIO_ID) 		 GPIO_PCSET |= (int16u)GPIO_ID		

/*******************************************************************************
* �������ƣ�GPIO_A_CLR
* �����������趨PAָ���ܽŵ����ֵΪ0
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						GPIO_PINS_ALL
* �����������
* ע���������ʹ��"|"����ͬʱ���ü����ܽ�
*******************************************************************************/
#define GPIO_A_CLR(GPIO_ID)          GPIO_PACLR |= GPIO_ID
/*******************************************************************************
* �������ƣ�GPIO_B_CLR
* �����������趨PBָ���ܽŵ����ֵΪ0
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						GPIO_PINS_ALL
* ���������ָ���ܽŵ�״ֵ̬��1��0��
* ע���������ʹ��"|"����ͬʱ���ü����ܽ�
*******************************************************************************/
#define GPIO_B_CLR(GPIO_ID)          GPIO_PBCLR |= GPIO_ID
/*******************************************************************************
* �������ƣ�GPIO_C_CLR
* �����������趨PCָ���ܽŵ����ֵΪ0
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						GPIO_PINS_ALL
* �����������
* ע���������ʹ��"|"����ͬʱ���ü����ܽ�
*******************************************************************************/
#define GPIO_C_CLR(GPIO_ID)          GPIO_PCCLR |= GPIO_ID

/*******************************************************************************
* �������ƣ�GPIO_A_READ
* ������������ȡPA��ָ���ܽŵ�����ֵ
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						GPIO_PINS_ALL
* ���������ָ���ܽŵ�״ֵ̬��1��0��
* ע�����ÿ�ζ�ȡֻ�ܶ�ȡһ���ܽŵ���ֵ,���߶�ȡȫ���ܽŵ�ֵ
*******************************************************************************/
int8u GPIO_A_READ(int32u GPIO_ID);

/*******************************************************************************
* �������ƣ�GPIO_B_READ
* ������������ȡPB��ָ���ܽŵ�����ֵ
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						GPIO_PINS_ALL
* ���������ָ���ܽŵ�״ֵ̬��1��0��
* ע�����ÿ�ζ�ȡֻ�ܶ�ȡһ���ܽŵ���ֵ,���߶�ȡȫ���ܽŵ�ֵ
*******************************************************************************/
int8u GPIO_B_READ(int32u GPIO_ID);

/*******************************************************************************
* �������ƣ�GPIO_C_READ
* ������������ȡPC��ָ���ܽŵ�����ֵ
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						GPIO_PINS_ALL
* ���������ָ���ܽŵ�״ֵ̬��1��0��
* ע�����ÿ�ζ�ȡֻ�ܶ�ȡһ���ܽŵ���ֵ,���߶�ȡȫ���ܽŵ�ֵ
*******************************************************************************/
int8u GPIO_C_READ(int32u GPIO_ID);

/*******************************************************************************
* �������ƣ�GPIO_A_MODE_SET
* ������������������PA�����ܽŵ�����/���ģʽ
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						ʹ��ʱ����ʹ�÷��š�|������һ�������ö���ܽ�  
			2.GPIO_MODE��GPIOCFG_OUT          //�������
   						 GPIOCFG_OUT_OD      //©����·���
   						 GPIOCFG_OUT_ALT     //������������
  						 GPIOCFG_OUT_ALT_OD   //����Ŀ�©���
  						 GPIOCFG_ANALOG    //ģ���źţ��������ź�Ϊ1
  						 GPIOCFG_IN       //��������
 						 GPIOCFG_IN_PUD     //���룺������������д1��������д0������
* �����������
* ע�������
*******************************************************************************/
void GPIO_A_MODE_SET(int32u GPIO_ID,int32u GPIO_MODE);
/*******************************************************************************
* �������ƣ�GPIO_B_MODE_SET
* ������������������PA�����ܽŵ�����/���ģʽ
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						ʹ��ʱ����ʹ�÷��š�|������һ�������ö���ܽ�  
			2.GPIO_MODE��GPIOCFG_OUT          //�������
   						 GPIOCFG_OUT_OD      //©����·���
   						 GPIOCFG_OUT_ALT     //������������
  						 GPIOCFG_OUT_ALT_OD   //����Ŀ�©���
  						 GPIOCFG_ANALOG    //ģ���źţ��������ź�Ϊ1
  						 GPIOCFG_IN       //��������
 						 GPIOCFG_IN_PUD     //���룺������������д1��������д0������
* �����������
* ע�������
*******************************************************************************/
void GPIO_B_MODE_SET(int32u GPIO_ID,int32u GPIO_MODE);
/*******************************************************************************
* �������ƣ�GPIO_C_MODE_SET
* ������������������PA�����ܽŵ�����/���ģʽ
* ���������1.GPIO_ID ��GPIO_PIN_7 
						GPIO_PIN_6 
						GPIO_PIN_5 
						GPIO_PIN_4 
						GPIO_PIN_3 
						GPIO_PIN_2 
						GPIO_PIN_1 
						GPIO_PIN_0 
						ʹ��ʱ����ʹ�÷��š�|������һ�������ö���ܽ�  
			2.GPIO_MODE��GPIOCFG_OUT          //�������
   						 GPIOCFG_OUT_OD      //©����·���
   						 GPIOCFG_OUT_ALT     //������������
  						 GPIOCFG_OUT_ALT_OD   //����Ŀ�©���
  						 GPIOCFG_ANALOG    //ģ���źţ��������ź�Ϊ1
  						 GPIOCFG_IN       //��������
 						 GPIOCFG_IN_PUD     //���룺������������д1��������д0������
* �����������
* ע�������
*******************************************************************************/
void GPIO_C_MODE_SET(int32u GPIO_ID,int32u GPIO_MODE);

#endif