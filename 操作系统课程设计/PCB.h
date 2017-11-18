#pragma once
#include<string>
using namespace std;
typedef struct PCB
{
	int PID;
	string Pname;//进程名称
	unsigned int ArriveTime;//到达时间
	unsigned int StartTime;//开始时间
	unsigned int FinishTime;//完成时间
	unsigned int NeedTime;//需要服务时间
	unsigned int Priority;//优先级，数值越高优先级越高

	PCB()//结构体初始化函数
	{
		Pname.clear();
		ArriveTime = 0;
		StartTime = 0;
		FinishTime = 0;
		NeedTime = 0;
		Priority = 0;
	}
};