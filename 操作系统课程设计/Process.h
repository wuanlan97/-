#pragma once
#include"PCB.h"
class Process//������
{public:
	void init(uint PID,string Pname,uint Needtime,uint Priority, uint time);//��ʼ�����̣�����PID������������Ҫ����ʱ�䣬���ȼ�����ǰϵͳʱ��
	void Kill(uint time);//ɱ������
	int Processor(uint time);//ִ��һ��ʱ��Ƭ�����˵�ǰϵͳʱ�䣬����0Ϊ����δ��ɣ�����1Ϊ����Ϊ��ɣ�����-1Ϊ����Ϊ��������-2Ϊ����δ��ʼ����
	PCB get();	//���PCB������
	uint Wait(bool w=true);//���̵ȴ�ʱ�䷵�غ�����������ȴ�ʱ��+1�����أ������ֻ���صȴ�ʱ�䣩
	~Process();
private:
	PCB *Head=NULL;//����PCB��
	uint WaitTime=0;
};