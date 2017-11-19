#pragma once
#include<string>
#define uint unsigned int
using namespace std;
typedef struct PCB
{
	int PID;
	string Pname;//进程名称
	uint ArriveTime;//到达时间
	uint StartTime;//开始时间
	uint PlayTime;//已运行时间
	uint FinishTime;//完成时间
	uint NeedTime;//需要服务时间
	uint Priority;//优先级，数值越高优先级越高
	int status;//进程状态，0为未完成，1为已完成，-1为被杀死
	PCB()//结构体初始化函数
	{
		Pname.clear();
		ArriveTime = 0;
		StartTime = 0;
		PlayTime = 0;
		FinishTime = 0;
		NeedTime = 0;
		Priority = 0;
	}

	PCB(PCB *temp)//结构体复制函数
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