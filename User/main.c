/*
*********************************************************************************************************
*
*	ģ������ : ������ģ�顣
*	�ļ����� : main.c
*	��    �� : V1.2
*	˵    �� : ���ڽ̳���Ҫ��Ϊ����ϵ����ڣ�GPIO�̶̳�����������ʵ��
*              ���ڳ�ѧ�ߣ��������ֻ���˽�LED��������ʹ�ü��ɣ����ڴ���
*              ����શ�ʱ�����ں���Ľ̳��кʹ�ҽ���,ʵ�����幦�ܣ�
*              1.����һ������Ϊ100ms��������ʱ����SysTickʵ���н��⣩��
*			   2.�������м��������ʱ��ʱ���Ƿ񵽣�ʱ�䵽�˷�ת�ĸ�LED��
*	�޸ļ�¼ :
*		�汾��  ����       ����    ˵��
*		v1.0    2013-11-20 armfly  �׷�
*		v1.2    2014-02-23 armfly  �����̼���
*
*	Copyright (C), 2013-2014, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#include "bsp.h"			/* �ײ�Ӳ������ */
#include "solarOS.h"

/* ���������������̷������� */
#define EXAMPLE_NAME	"V5-001a_GPIOʵ��_������"
#define EXAMPLE_DATE	"2014-02-23"
#define DEMO_VER		"1.2"

///* ���������ļ��ڵ��õĺ������� */
//static void PrintfLogo(void);
//static __IO uint32_t TimingDelay;

void SysTick_Handler(void)
{
	tDelayTickHandler();
}

/*
*********************************************************************************************************
*	�� �� ��  :   main
*	����˵��  :   ��������ڣ���OS�ĸ�������ģ����г�ʼ��
*	��    ��  :   ��
*	�� �� ֵ  :   ��
*********************************************************************************************************
*/
int main(void)
{
  /*Ӳ����ʼ��*/
	bsp_Init();		

	/*��ʼ��λͼ���ݽṹ*/
	tBitmapInit(&tbitmap);
	
	/*������ʱ���г�ʼ��*/
	tTaskDelayedListInit();
	
	/*�������ȼ����г�ʼ��*/
	tTaskPrioListInit();
	
	/*��ʼ��������*/
	tSchedLockInit();
	
	/*APP��ʼ��*/
	tInitApp();
	
	/*ѡȡ��һ����Ҫ���е�����������ȼ�������*/
	nextTask = tTaskHighestReady();

	/*���е�һ������*/
	tTaskRunFirst();
	
	/*ϵͳ�ɹ�����֮�󣬱㲻�����е��˴�*/
	return 0;
}

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/