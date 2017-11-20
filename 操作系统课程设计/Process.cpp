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
	Head->status = 0;
}
PCB Process::get()
{
	return *Head;
}
Process::~Process()
{
	if (Head == NULL)return;
	delete Head;
	Head = NULL;
}
void Process::Kill()
{
	if (Head == NULL)return;
	Head->status = -1;
}
int Process::Processor(uint time)
{
	//�ж��Ƿ���̴����쳣״̬
	if (Head == NULL)return -2;//�ж��Ƿ�δ��ʼ��
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



