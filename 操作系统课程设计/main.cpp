// 操作系统课程设计.cpp : 定义控制台应用程序的入口点。
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
		in=getint("0、退出\n1、创建进程\n2、杀死进程\n3、阻塞进程\n4、就绪进程\n5、设置调度算法\n6、运行一个时间片\n7、打印进程");
		switch (in)
		{
		case 0:return 0;
		case 1:s.NewProcess();break;
		case 2:s.KillProcess(getint("请输入杀死进程的PID"));break;
		case 3:s.BlockProcess();break;
		case 4:s.ReadyProcess(getint("请输入在阻塞队列需要就绪进程的PID"));break;
		case 5:s.SetMonitor();break;
		case 6:s.PlayFirstProcess();
		case 7:s.print();
		}
	}
    return 0;
}

