// ����ϵͳ�γ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include"System.h"
#include"get.h"
using namespace std;

System s;
int main()
{
	
	s.init();
	while (1)
	{
		int in;
		in=getint("0���˳�\n1����������\n2��ɱ������\n3����������\n4����������\n5�����õ����㷨\n6������һ��ʱ��Ƭ\n7����ӡ����");
		switch (in)
		{
		case 0:return 0;
		case 1:s.NewProcess();break;
		case 2:s.KillProcess(getint("������ɱ�����̵�PID"));break;
		case 3:s.BlockProcess();break;
		case 4:s.ReadyProcess(getint("������������������Ҫ�������̵�PID"));break;
		case 5:s.SetMonitor();break;
		case 6:s.PlayFirstProcess();
		case 7:s.print();
		}
	}
    return 0;
}

