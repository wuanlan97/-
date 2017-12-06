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
	bool edit;//���������޸ı�־
public:
	void NewProcess();//��������
	void KillProcess(uint PID);//ɱ������
	void BlockProcess();//�������������
	void ReadyProcess(uint PID);//��������
	void init();//��ʼ��
	bool SetMonitor();//�����㷨
	void PlayFirstProcess();//ϵͳ��ת����
	void print();//��ӡ������Ϣ
	void Evaluation();//�㷨����ģ�飨����ƽ����תʱ���ƽ���ȴ�ʱ�䣩
	~System();
protected:
	void PrintProcess(Process *temp);//��ӡ������Ϣ
	void PrintList(list<Process*> *temp);//��ӡlist�б���Ϣ
	void PrintVector(vector<Process*> *temp);//��ӡvector�б���Ϣ
	
	void RR();//ʱ��Ƭ��ת�����㷨
};
