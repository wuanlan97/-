#pragma once
#include<list>
#include<vector>
#include<iostream>
#include"Process.h"
#define uint unsigned int
using namespace std;
static Process* Processor;//症状运行进程指针
static list<Process*> Ready;//就绪队列
static vector<Process*> Block;//阻塞队列
static list<Process*> Close;//停止调度队列
class System//系统类
{
private:

	uint NextPID = 1;
	uint Time = 1;
public:
	void NewProcess();//创建进程
	void KillProcess(uint PID);//杀死进程
	void BlockProcess();//阻塞进程
	void ReadyProcess(uint PID);//就绪进程
	void init();//初始化
	void SetMonitor();//设置算法
	void play();//系统轮转函数
	void print();//打印所有信息
	~System();
protected:
	void PrintProcess(Process *temp);//打印进程信息
	void PrintList(list<Process*> *temp);//打印list列表信息
};