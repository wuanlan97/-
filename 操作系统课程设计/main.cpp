// ����ϵͳ�γ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
#include"System.h"
#include"get.h"
using namespace std;

System s;//ϵͳ��
HANDLE hMutex;//�����ź���
int delay;//�ӳ�ʱ��
bool end;//�߳̽������

DWORD WINAPI AutoPlay(LPVOID lpParamter)
{
	while (1)
	{
		if (::end)return 0;
		WaitForSingleObject(hMutex, INFINITE);//�ȴ��ź���
		system("cls");
		s.PlayFirstProcess();
		s.print();
		cout << "\n���������ͣ" << endl;
		ReleaseMutex(hMutex);//�ͷ��ź���
		Sleep(delay);//��������	
	}
}
void SetAutoPlay(int time)
{
	if (time <= 0) { cout << "��ʱ����С��0";return; }
	::end = false;//����AutoPlay���˳�
	delay = time;//������ʱ
	HANDLE hThread = CreateThread(NULL, 0, AutoPlay, NULL, 0, NULL);//�����߳�
	system("pause");//�ȴ���ͣ

	WaitForSingleObject(hMutex, INFINITE);//�ȴ��ź���
	::end = true;//����AutoPlay�˳�
	CloseHandle(hThread);//ֹͣ�߳�
	ReleaseMutex(hMutex);//�ͷ��ź���
}
int main()
{
	
	s.init();
	while (1)
	{
		int in;
		in=getint("0���˳�\n1����������\n2��ɱ������\n3����������\n4����������\n5�����õ����㷨\n6����ӡ����ָ��\n7�������Զ�����\n8������һ��ʱ��Ƭ\n9����ӡ����");
		switch (in)
		{
		case 0:return 0;
		case 1:s.NewProcess();break;
		case 2:s.KillProcess(getint("������ɱ�����̵�PID"));break;
		case 3:s.BlockProcess();break;
		case 4:s.ReadyProcess(getint("������������������Ҫ�������̵�PID"));break;
		case 5:s.SetMonitor();break;
		case 6:s.Evaluation();break;
		case 7:SetAutoPlay(getint("��������ʱ�����룩"));
		case 8:s.PlayFirstProcess();
		case 9:s.print();break;
		default:cout << "��������" << endl;break;
		}
		system("pause");
		system("cls");
	}
    return 0;
}

