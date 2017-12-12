#include"System.h"
#include"get.h"
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
	cout << "请输入进程名";
	cin >> Pname;
	NeedTime = getint("请输入需服务时间");
	Priority = getint("请输入优先级");

	//创建进程并进入就绪队列
	temp = new Process;
	temp->init(NextPID++, Pname, NeedTime, Priority, Time++);
	Ready.push_back(temp);
	WaitTimePlus();
}

void System::KillProcess(uint PID)
{
	//检查处理机进程是否为要杀死进程
	if (Processor!=NULL && Processor->get().PID == PID)
	{
		Processor->Kill(Time++);
		WaitTimePlus();
		Close.push_back(Processor);
		Processor = NULL;
		return;
	}
	//查找就绪队列是否有要杀死的进程
	for (list<Process*>::iterator i = Ready.begin();i != Ready.end();)
	{
		if ((*i)->get().PID == PID)
		{
			(*i)->Kill(Time++);
			WaitTimePlus();
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
			(*i)->Kill(Time++);
			WaitTimePlus();
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
	int temp;
	temp = getint("请输入选择的算法：\n1、先来先服务\n2、优先级\n3、短作业优先\n4、时间片轮转");
	if (temp > 0 && temp < 5) { algorithm = temp; return true; }
	else { cout << "输入有误！" << endl; temp = 0; return false; }
	
}

void System::PlayFirstProcess()
{
	
	play:;
	if(Processor != NULL )
	{
		if (Processor->get().status == 1)Close.push_back(Processor);//如果该进程已完成，则停止调度
		else Ready.push_back(Processor);//未完成则插入就绪队列尾部
	}
	
	Processor = NULL;

	switch (algorithm)
	{
	case 1:Ready.sort(FCFS);break;
	case 2:Ready.sort(PS);break;
	case 3:Ready.sort(SJF);break;
	case 4:RR();break;
	default:
		cout << "未设置调度算法，调度失败" << endl;
		return;
		break;
	}

	if (Ready.empty())return;//判空
	Processor = *Ready.begin();//将就绪队列队首的进程送入处理机
	Ready.pop_front();//将就绪队列队首删除
	if(Processor->Processor(Time)==1)goto play;
	
	Time++;
	WaitTimePlus();
}

void System::print()
{
	cout << "当前系统时间：" << Time << endl;
	cout << "当前调度算法：";
	switch (algorithm)
	{
	case 1:cout << "先来先服务" << endl;break;
	case 2:cout << "优先级" << endl;break;
	case 3:cout << "短作业优先" << endl;break;
	case 4:cout << "时间片轮转" << endl;break;
	default:cout << "未设置" << endl;

	}
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
void System::Evaluation()
{
	if (Close.empty()) { cout << "没有完成的进程，无法评价" << endl;return; }
	if (!Ready.empty() || !Block.empty() || Processor != NULL)cout << "未完成进程调度，数据可能不准确" << endl;

	//计算平均周转时间
	uint WaitTime = 0,RunTime=0;
	for (list<Process*>::iterator i = Close.begin();i != Close.end() && !Close.empty(); i++)//遍历停止调度列表获取数据
	{
		WaitTime += (*i)->Wait(false);//获取进程等待时间总和
		RunTime += (*i)->get().PlayTime;//获取进程运行时间总和
	}
	cout << "平均等待时间：" << (float)WaitTime /(float) Close.size()<<endl;
	cout << "平均周转时间：" <<((float)WaitTime + (float)RunTime )/ (float)Close.size()<<endl;

}
void System::WaitTimePlus()
{
	for (list<Process*>::iterator i = Ready.begin();i != Ready.end() && !Ready.empty(); i++)//遍历就绪队列
		(*i)->Wait();//进程等待时间+1
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
	for (list<Process*>::iterator i = Ready.begin();i != Ready.end()&&!Ready.empty(); i++)delete *i;
	if(!Ready.empty())Ready.clear();

	//释放停止调度队列进程
	for (list<Process*>::iterator i = Close.begin();i != Close.end()&&!Close.empty(); i++)delete *i;
	if(!Close.empty())Close.clear();

	//释放阻塞队列进程
	for (vector<Process*>::iterator i = Block.begin();i != Block.end();i++)delete *i;
	Block.clear();

	//释放处理机进程
	if (Processor != NULL)delete Processor, Processor = NULL;
}
