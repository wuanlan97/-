#include"System.h"
#include<list>
#include<vector>
#include<iostream>
#include <iomanip>
using namespace std;
void System::NewProcess()
{
	string Pname;
	uint NeedTime, Priority;
	Process *temp;

	//���������Ϣ
	cout << "Pname=";
	cin >> Pname;
	cout << "Needtime=";
	cin >> NeedTime;
	cout << "Priority=";
	cin >> Priority;

	//�������̲������������
	temp = new Process;
	temp->init(NextPID++, Pname, NeedTime, Priority, Time++);
	Ready.push_back(temp);
}

void System::KillProcess(uint PID)
{

}

void System::BlockProcess()
{

}

void System::ReadyProcess(uint PID)
{

}

void System::init()
{

}

void System::SetMonitor()
{

}

void System::play()
{

}

void System::print()
{
	cout << "��������������Ϣ" << endl;
	cout << "PID  ����   ����ʱ��   ��ʼʱ��   ������ʱ��   ���ʱ��   ��Ҫ����ʱ��   ���ȼ�" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	PrintProcess(Processor);
	cout << "\n\n\n\n";

	cout << "����������Ϣ" << endl;
	cout << "PID  ����   ����ʱ��   ��ʼʱ��   ������ʱ��   ���ʱ��   ��Ҫ����ʱ��   ���ȼ�" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	PrintList(&Ready);
	cout << "\n\n\n\n";

	cout << "ֹͣ���ȶ�����Ϣ" << endl;
	cout << "PID  ����   ����ʱ��   ��ʼʱ��   ������ʱ��   ���ʱ��   ��Ҫ����ʱ��   ���ȼ�" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	PrintList(&Close);
	cout << "\n\n\n\n";
}
void System::PrintProcess(Process *temp=NULL)
{
	if (temp == NULL)return;
	PCB p = temp->get();
	cout.setf(ios::internal);//�м����
	cout <<setw(2)<< p.PID ;
	cout << setw(5) << p.Pname ;
	cout << setw(7) << p.ArriveTime;
	cout << setw(13) << p.StartTime;
	cout << setw(13) << p.PlayTime;
	cout << setw(13) << p.FinishTime;
	cout << setw(13) << p.NeedTime;
	cout << setw(13) << p.Priority ;
}

void System::PrintList(list<Process*> *temp)
{
	for (list<Process*>::iterator i = temp->begin();i!=temp->end(); i++)
	{
		PrintProcess(*i);
		cout << endl;
	}
}

System::~System()
{
	for (list<Process*>::iterator i = Ready.begin();i != Ready.end(); i++)
	{
		delete *i;
	}
	Ready.clear();

	for (list<Process*>::iterator i = Close.begin();i != Close.end(); i++)
	{
		delete *i;
	}
	Close.clear();
}