#pragma once
#define uint unsigned int;

class System//ϵͳ��
{
public:
	void NewProcess();
	void KillProcess();
	void BlockProcess();
	void ReadyProcess();
	void init();
	void SetMonitor();
};