#pragma once
#include"PCB.h"
class Process//������
{public:
	void init(uint PID,string Pname,uint Needtime,uint Priority, uint time);//��ʼ�����̣�����PID������������Ҫ����ʱ�䣬���ȼ�����ǰϵͳʱ��
	void Kill();//ɱ������
	int Processor(uint time);//ִ��һ��ʱ��Ƭ�����˵�ǰϵͳʱ�䣬����0Ϊ����δ��ɣ�����1Ϊ����Ϊ��ɣ�����-1Ϊ����Ϊ��������-2Ϊ����δ��ʼ����
	PCB get();	//���PCB������
	~Process();
private:
	PCB *Head=NULL;
	//����PCB��
};