#pragma once
#include<list>
#include<vector>
#include<iostream>
#include"Process.h"
#define uint unsigned int
using namespace std;
static Process* Processor;//֢״���н���ָ��
static list<Process*> Ready;//��������
static vector<Process*> Block;//��������
static list<Process*> Close;//ֹͣ���ȶ���
class System//ϵͳ��
{
private:

	uint NextPID = 1;
	uint Time = 1;
public:
	void NewProcess();//��������
	void KillProcess(uint PID);//ɱ������
	void BlockProcess();//��������
	void ReadyProcess(uint PID);//��������
	void init();//��ʼ��
	void SetMonitor();//�����㷨
	void play();//ϵͳ��ת����
	void print();//��ӡ������Ϣ
	~System();
protected:
	void PrintProcess(Process *temp);//��ӡ������Ϣ
	void PrintList(list<Process*> *temp);//��ӡlist�б���Ϣ
};