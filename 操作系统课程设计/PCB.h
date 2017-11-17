#pragma once
typedef struct PCB
{
	char Pname[20];//进程名称
	int ArriveTime;//到达时间
	int StartTime;//开始时间
	int FinishTime;//完成时间
	int NeedTime;//需要服务时间
	int Priority;//优先级
};