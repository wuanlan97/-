#pragma once
#include"PCB.h"
class Process//������
{protected:
	
	void init();//��ʼ������
	void Kill();//ɱ������
	void Processor();//ִ��һ��ʱ��Ƭ
	PCB get();//���PCB������
private:
	PCB* Head = NULL;//����PCB��
};