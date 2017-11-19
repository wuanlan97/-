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
	//�ж��Ƿ���̴����쳣״̬
	if (Head->PID==0)return -2; //�ж��Ƿ�δ��ʼ��
	else if (Head->status!=0) return Head->status;

	//���̿�ʼ����
	if (Head->StartTime == 0)Head->StartTime = time;
	
	if (++Head->PlayTime == Head->NeedTime)//�жϽ����Ƿ������
	{
		Head->status = 1;
		Head->FinishTime = time;
		return 1;
	}
	return 0;
}

