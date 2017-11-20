#include"System.h"
#include<list>
#include<vector>
#include<iostream>
#include <iomanip>
#include<algorithm>
using namespace std;

Process* System::Processor;//处理器运行进程指针
list<Process*> System::Ready;//就绪队列
vector<Process*> System::Block;//阻塞队列
list<Process*> System::Close;//停止调度队列

void System::NewProcess()
{
	string Pname;
	uint NeedTime, Priority;
	Process *temp;

	//输入进程信息
	cout << "Pname=";
	cin >> Pname;
	cout << "Needtime=";
	cin >> NeedTime;
	cout << "Priority=";
	cin >> Priority;

	//创建进程并进入就绪队列
	temp = new Process;
	temp->init(NextPID++, Pname, NeedTime, Priority, Time++);
	Ready.push_back(temp);
}

void System::KillProcess(uint PID)
{
	//检查处理机进程是否为要杀死进程
	if (Processor!=NULL && Processor->get().PID == PID)
	{
		Processor->Kill();
		Close.push_back(Processor);
		Processor = NULL;
		return;
	}
	//查找就绪队列是否有要杀死的进程
	for (list<Process*>::iterator i = Ready.begin();i != Ready.end();)
	{
		if ((*i)->get().PID == PID)
		{
			(*i)->Kill();
			Close.push_back(*i);
			i=Ready.erase(i);
			return;
		}
		i++;
	}
	//查找阻塞队列是否有要杀死的进程
	for (vector<Process*>::iterator i = Block.begin();i != Block.end();)
	{
		if ((*i)->get().PID == PID)
		{
			(*i)->Kill();
			Close.push_back(*i);
			i = Block.erase(i);
			return;
		}
		i++;
	}

	cout << "无该进程" << endl;
}

void System::BlockProcess()
{
	if (Processor == NULL)return;
	Block.push_back(Processor);
	Processor = NULL;
	edit = true;
}

void System::ReadyProcess(uint PID)
{
	if (Block.empty())return;//判空
	for (vector<Process*>::iterator i = Block.begin();i != Block.end();)//遍历阻塞表
	{
		if ((*i)->get().PID == PID)//查找对应PID
		{
			Ready.push_back(*i);
			i = Block.erase(i);
			edit = true;
			return;
		}
		i++;
	}
	cout << "无该进程" << endl;
}

void System::init()
{
	Processor = NULL;
	algorithm = 0;
	edit = true;
	Ready.clear();
	Block.clear();
	Close.clear();
}

bool System::SetMonitor()
{
	cout << "请输入选择的算法：\n1、先来先服务\n2、优先级\n3、短作业优先\n4、时间片轮转" << endl;
	int temp;
	cin >> temp;
	if (temp > 0 && temp < 5) { algorithm = temp; return true; }
	else { cout << "输入有误！" << endl; temp = 0; return false; }
	
}

void System::PlayFirstProcess()
{
	if(Processor != NULL )
	if (Processor->get().status == 1)Close.push_back(Processor);//如果该进程已完成，则停止调度
	else Ready.push_back(Processor);//未完成则插入就绪队列尾部
	Processor = NULL;

	switch (algorithm)
	{
	case 1:Ready.sort(FCFS);break;
	case 2:Ready.sort(PS);break;
	case 3:Ready.sort(SJF);break;
	case 4:RR();break;
	default:
		cout << "调度错误" << endl;
		return;
		break;
	}

	if (Ready.empty())return;//判空
	//将就绪队列队首的进程送入处理机
	Processor = *Ready.begin();
	Processor->Processor(Time++);
	Ready.pop_front();

}

void System::print()
{
	cout << "处理机处理进程信息" << endl;
	cout << "PID  名称   到达时间   开始时间   已运行时间   完成时间   需要服务时间   优先级    状态" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	PrintProcess(Processor);
	cout << "\n\n\n\n";

	cout << "就绪队列信息   当前等待调度进程数量：" <<Ready.size()<< endl;
	cout << "PID  名称   到达时间   开始时间   已运行时间   完成时间   需要服务时间   优先级    状态" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	PrintList(&Ready);
	cout << "\n\n\n\n";

	cout << "阻塞队列信息   当前阻塞进程数量：" << Block.size() << endl;
	cout << "PID  名称   到达时间   开始时间   已运行时间   完成时间   需要服务时间   优先级    状态" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	PrintVector(&Block);
	cout << "\n\n\n\n";

	cout << "停止调度队列信息  当前停止调度进程数量：" << Close.size() << endl;
	cout << "PID  名称   到达时间   开始时间   已运行时间   完成时间   需要服务时间   优先级    状态" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	PrintList(&Close);
	cout << "\n\n\n\n";
}
void System::PrintProcess(Process *temp=NULL)
{
	if (temp == NULL)return;
	PCB p = temp->get();
	cout.setf(ios::internal);//中间对齐
	cout <<setw(2)<< p.PID ;
	cout << setw(5) << p.Pname ;
	cout << setw(7) << p.ArriveTime;
	cout << setw(13) << p.StartTime;
	cout << setw(13) << p.PlayTime;
	cout << setw(13) << p.FinishTime;
	cout << setw(13) << p.NeedTime;
	cout << setw(13) << p.Priority ;
	switch (p.status)
	{
	case 0:cout << setw(7) << "未完成";break;
	case 1:cout << setw(7) << "已完成";break;
	case -1:cout << setw(7) << "被杀死";break;
	case -2:cout << setw(7) << "未初始化";break;
	default:cout << setw(7) << "未知";break;
	}
	
}

void System::PrintList(list<Process*> *temp)
{
	for (list<Process*>::iterator i = temp->begin();i!=temp->end(); i++)
	{
		PrintProcess(*i);
		cout << endl;
	}
}

void System::PrintVector(vector<Process*> *temp)
{
	for (vector<Process*>::iterator i = temp->begin();i != temp->end();i++)
	{
		PrintProcess(*i);
		cout << endl;
	}
}

void System::RR()
{
	if (edit)
	{
		Ready.sort(FCFS);
		edit = false;
	}
}

System::~System()
{
	//释放就绪队列进程
	for (list<Process*>::iterator i = Ready.begin();i != Ready.end(); i++)delete *i;
	Ready.clear();

	//释放停止调度队列进程
	for (list<Process*>::iterator i = Close.begin();i != Close.end(); i++)delete *i;
	Close.clear();

	//释放阻塞队列进程
	for (vector<Process*>::iterator i = Block.begin();i != Block.end();i++)delete *i;
	Block.clear();

	//释放处理机进程
	if (Processor != NULL)delete Processor, Processor = NULL;
}
