#include"Process.h"

void Process::init(uint PID, string Pname, uint Needtime, uint Priority ,uint time)
{
	if (Head != NULL)return;
	else Head = new PCB;

	Head->PID = PID;
	Head->Pname = Pname;
	Head->NeedTime = Needtime;
	Head->Priority = Priority;
	Head->ArriveTime = time;
}
PCB Process::get()
{
	return *Head;
}
Process::~Process()
{
	delete Head;
	Head = NULL;
}
void Process::Kill()
{
	Head->status = -1;
}
int Process::Processor(uint time)
{
	//判断是否进程处于异常状态
	if (Head->PID==0)return -2; //判断是否未初始化
	else if (Head->status!=0) return Head->status;

	//进程开始运行
	if (Head->StartTime == 0)Head->StartTime = time;
	
	if (++Head->PlayTime == Head->NeedTime)//判断进程是否已完成
	{
		Head->status = 1;
		Head->FinishTime = time;
		return 1;
	}
	return 0;
}

