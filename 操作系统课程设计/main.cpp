// ����ϵͳ�γ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include"System.h"
using namespace std;


int main()
{
	System s;
	s.init();
	while (1)
	{
		cout << "0���˳�\n1����������\n2��ɱ������\n3����������\n4����������\n5�����õ����㷨\n6�����н���\n7����ӡ����" << endl;
		int in, temp;
		cin >> in;
		switch (in)
		{
		case 0:exit(0);
		case 1:s.NewProcess();break;
		case 2:cin >> temp;s.KillProcess(temp);break;
		case 3:s.BlockProcess();break;
		case 4:cin >> temp;s.ReadyProcess(temp);break;
		case 5:s.SetMonitor();break;
		case 6:s.PlayFirstProcess();
		case 7:s.print();
		}
	}
    return 0;
}

