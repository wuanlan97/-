#pragma once
#include"PCB.h"
class Process//进程类
{public:
	void init(uint PID,string Pname,uint Needtime,uint Priority, uint time);//初始化进程，传入PID，进程名，需要服务时间，优先级，当前系统时间
	void Kill(uint time);//杀死进程
	int Processor(uint time);//执行一个时间片，传人当前系统时间，返回0为进程未完成，返回1为进程为完成，返回-1为进程为出错，返回-2为进程未初始化，
	PCB get();	//获得PCB表数据
	uint Wait(bool w=true);//进程等待时间返回函数（传入真等待时间+1并返回，传入假只返回等待时间）
	~Process();
private:
	PCB *Head=NULL;//进程PCB表
	uint WaitTime=0;
};