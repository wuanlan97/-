#pragma once
#include<string>
using namespace std;
typedef struct PCB
{
	int PID;
	string Pname;//��������
	unsigned int ArriveTime;//����ʱ��
	unsigned int StartTime;//��ʼʱ��
	unsigned int FinishTime;//���ʱ��
	unsigned int NeedTime;//��Ҫ����ʱ��
	unsigned int Priority;//���ȼ�����ֵԽ�����ȼ�Խ��

	PCB()//�ṹ���ʼ������
	{
		Pname.clear();
		ArriveTime = 0;
		StartTime = 0;
		FinishTime = 0;
		NeedTime = 0;
		Priority = 0;
	}
};