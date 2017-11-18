#pragma once
#include"PCB.h"
class Process//进程类
{protected:
	
	void init();//初始化进程
	void Kill();//杀死进程
	void Processor();//执行一个时间片
	PCB get();//获得PCB表数据
private:
	PCB* Head = NULL;//进程PCB表
};