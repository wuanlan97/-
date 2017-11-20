#include"System.h"
#include<list>
#include<vector>
#include<iostream>
#include <iomanip>
#include<algorithm>
using namespace std;

Process* System::Processor;//���������н���ָ��
list<Process*> System::Ready;//��������
vector<Process*> System::Block;//��������
list<Process*> System::Close;//ֹͣ���ȶ���

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
	//��鴦��������Ƿ�ΪҪɱ������
	if (Processor!=NULL && Processor->get().PID == PID)
	{
		Processor->Kill();
		Close.push_back(Processor);
		Processor = NULL;
		return;
	}
	//���Ҿ��������Ƿ���Ҫɱ���Ľ���
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
	//�������������Ƿ���Ҫɱ���Ľ���
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

	cout << "�޸ý���" << endl;
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
	if (Block.empty())return;//�п�
	for (vector<Process*>::iterator i = Block.begin();i != Block.end();)//����������
	{
		if ((*i)->get().PID == PID)//���Ҷ�ӦPID
		{
			Ready.push_back(*i);
			i = Block.erase(i);
			edit = true;
			return;
		}
		i++;
	}
	cout << "�޸ý���" << endl;
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
	cout << "������ѡ����㷨��\n1�������ȷ���\n2�����ȼ�\n3������ҵ����\n4��ʱ��Ƭ��ת" << endl;
	int temp;
	cin >> temp;
	if (temp > 0 && temp < 5) { algorithm = temp; return true; }
	else { cout << "��������" << endl; temp = 0; return false; }
	
}

void System::PlayFirstProcess()
{
	if(Processor != NULL )
	if (Processor->get().status == 1)Close.push_back(Processor);//����ý�������ɣ���ֹͣ����
	else Ready.push_back(Processor);//δ���������������β��
	Processor = NULL;

	switch (algorithm)
	{
	case 1:Ready.sort(FCFS);break;
	case 2:Ready.sort(PS);break;
	case 3:Ready.sort(SJF);break;
	case 4:RR();break;
	default:
		cout << "���ȴ���" << endl;
		return;
		break;
	}

	if (Ready.empty())return;//�п�
	//���������ж��׵Ľ������봦���
	Processor = *Ready.begin();
	Processor->Processor(Time++);
	Ready.pop_front();

}

void System::print()
{
	cout << "��������������Ϣ" << endl;
	cout << "PID  ����   ����ʱ��   ��ʼʱ��   ������ʱ��   ���ʱ��   ��Ҫ����ʱ��   ���ȼ�    ״̬" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	PrintProcess(Processor);
	cout << "\n\n\n\n";

	cout << "����������Ϣ   ��ǰ�ȴ����Ƚ���������" <<Ready.size()<< endl;
	cout << "PID  ����   ����ʱ��   ��ʼʱ��   ������ʱ��   ���ʱ��   ��Ҫ����ʱ��   ���ȼ�    ״̬" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	PrintList(&Ready);
	cout << "\n\n\n\n";

	cout << "����������Ϣ   ��ǰ��������������" << Block.size() << endl;
	cout << "PID  ����   ����ʱ��   ��ʼʱ��   ������ʱ��   ���ʱ��   ��Ҫ����ʱ��   ���ȼ�    ״̬" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	PrintVector(&Block);
	cout << "\n\n\n\n";

	cout << "ֹͣ���ȶ�����Ϣ  ��ǰֹͣ���Ƚ���������" << Close.size() << endl;
	cout << "PID  ����   ����ʱ��   ��ʼʱ��   ������ʱ��   ���ʱ��   ��Ҫ����ʱ��   ���ȼ�    ״̬" << endl;
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
	switch (p.status)
	{
	case 0:cout << setw(7) << "δ���";break;
	case 1:cout << setw(7) << "�����";break;
	case -1:cout << setw(7) << "��ɱ��";break;
	case -2:cout << setw(7) << "δ��ʼ��";break;
	default:cout << setw(7) << "δ֪";break;
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
	//�ͷž������н���
	for (list<Process*>::iterator i = Ready.begin();i != Ready.end(); i++)delete *i;
	Ready.clear();

	//�ͷ�ֹͣ���ȶ��н���
	for (list<Process*>::iterator i = Close.begin();i != Close.end(); i++)delete *i;
	Close.clear();

	//�ͷ��������н���
	for (vector<Process*>::iterator i = Block.begin();i != Block.end();i++)delete *i;
	Block.clear();

	//�ͷŴ��������
	if (Processor != NULL)delete Processor, Processor = NULL;
}
