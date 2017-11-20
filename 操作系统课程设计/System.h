#pragma once
#include<list>
#include<vector>
#include<iostream>
#include"Process.h"
#include"algorithm.h"
#define uint unsigned int
using namespace std;

class System//ϵͳ��
{
private:
	static Process* Processor;//���������н���ָ��
	static list<Process*> Ready;//��������
	static vector<Process*> Block;//��������
	static list<Process*> Close;//ֹͣ���ȶ���
	uint NextPID = 1;
	uint Time = 1;
	int algorithm;//���ȷ���
	bool edit;
public:
	void NewProcess();//��������
	void KillProcess(uint PID);//ɱ������
	void BlockProcess();//�������������
	void ReadyProcess(uint PID);//��������
	void init();//��ʼ��
	bool SetMonitor();//�����㷨
	void PlayFirstProcess();//ϵͳ��ת����
	void print();//��ӡ������Ϣ
	~System();
protected:
	void PrintProcess(Process *temp);//��ӡ������Ϣ
	void PrintList(list<Process*> *temp);//��ӡlist�б���Ϣ
	void PrintVector(vector<Process*> *temp);//��ӡvector�б���Ϣ
	
	void RR();//ʱ��Ƭ��ת�����㷨
};
