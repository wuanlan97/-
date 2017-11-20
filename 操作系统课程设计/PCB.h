#pragma once
#include<string>
#define uint unsigned int
using namespace std;
typedef struct PCB
{
	int PID;
	string Pname;//��������
	uint ArriveTime;//����ʱ��
	uint StartTime;//��ʼʱ��
	uint PlayTime;//������ʱ��
	uint FinishTime;//���ʱ��
	uint NeedTime;//��Ҫ����ʱ��
	uint Priority;//���ȼ�����ֵԽ�����ȼ�Խ��
	int status;//����״̬��0Ϊδ��ɣ�1Ϊ����ɣ�-1Ϊ��ɱ��,-2Ϊδ��ʼ��
	PCB()//�ṹ���ʼ������
	{
		Pname.clear();
		ArriveTime = 0;
		StartTime = 0;
		PlayTime = 0;
		FinishTime = 0;
		NeedTime = 0;
		Priority = 0;
		status = -2;
	}

	PCB(PCB *temp)//�ṹ�帴�ƺ���
	{
		Pname=temp->Pname;
		ArriveTime = temp->ArriveTime;
		StartTime = temp->StartTime;
		PlayTime = temp->PlayTime;
		FinishTime = temp->FinishTime;
		NeedTime = temp->NeedTime;
		Priority = temp->Priority;
		status = temp->status;
	}
};