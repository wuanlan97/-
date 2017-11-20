// 操作系统课程设计.cpp : 定义控制台应用程序的入口点。
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
		cout << "0、退出\n1、创建进程\n2、杀死进程\n3、阻塞进程\n4、就绪进程\n5、设置调度算法\n6、运行进程\n7、打印进程" << endl;
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

