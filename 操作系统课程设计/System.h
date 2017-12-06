#pragma once
#include<list>
#include<vector>
#include<iostream>
#include"Process.h"
#include"algorithm.h"
#define uint unsigned int
using namespace std;

class System//系统类
{
private:
	static Process* Processor;//处理器运行进程指针
	static list<Process*> Ready;//就绪队列
	static vector<Process*> Block;//阻塞队列
	static list<Process*> Close;//停止调度队列
	uint NextPID = 1;
	uint Time = 1;
	int algorithm;//调度方法
	bool edit;//就绪队列修改标志
public:
	void NewProcess();//创建进程
	void KillProcess(uint PID);//杀死进程
	void BlockProcess();//阻塞处理机进程
	void ReadyProcess(uint PID);//就绪进程
	void init();//初始化
	bool SetMonitor();//设置算法
	void PlayFirstProcess();//系统轮转函数
	void print();//打印所有信息
	void Evaluation();//算法评价模块（计算平均周转时间和平均等待时间）
	~System();
protected:
	void PrintProcess(Process *temp);//打印进程信息
	void PrintList(list<Process*> *temp);//打印list列表信息
	void PrintVector(vector<Process*> *temp);//打印vector列表信息
	
	void RR();//时间片轮转调度算法
};
