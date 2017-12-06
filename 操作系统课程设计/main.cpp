// 操作系统课程设计.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
#include"System.h"
#include"get.h"
using namespace std;

System s;//系统类
HANDLE hMutex;//互斥信号量
int delay;//延迟时间
bool end;//线程结束标记

DWORD WINAPI AutoPlay(LPVOID lpParamter)
{
	while (1)
	{
		if (::end)return 0;
		WaitForSingleObject(hMutex, INFINITE);//等待信号量
		system("cls");
		s.PlayFirstProcess();
		s.print();
		cout << "\n按任意键暂停" << endl;
		ReleaseMutex(hMutex);//释放信号量
		Sleep(delay);//进程休眠	
	}
}
void SetAutoPlay(int time)
{
	if (time <= 0) { cout << "延时不能小于0";return; }
	::end = false;//设置AutoPlay不退出
	delay = time;//设置延时
	HANDLE hThread = CreateThread(NULL, 0, AutoPlay, NULL, 0, NULL);//创建线程
	system("pause");//等待暂停

	WaitForSingleObject(hMutex, INFINITE);//等待信号量
	::end = true;//设置AutoPlay退出
	CloseHandle(hThread);//停止线程
	ReleaseMutex(hMutex);//释放信号量
}
int main()
{
	
	s.init();
	while (1)
	{
		int in;
		in=getint("0、退出\n1、创建进程\n2、杀死进程\n3、阻塞进程\n4、就绪进程\n5、设置调度算法\n6、打印评价指标\n7、设置自动运行\n8、运行一个时间片\n9、打印进程");
		switch (in)
		{
		case 0:return 0;
		case 1:s.NewProcess();break;
		case 2:s.KillProcess(getint("请输入杀死进程的PID"));break;
		case 3:s.BlockProcess();break;
		case 4:s.ReadyProcess(getint("请输入在阻塞队列需要就绪进程的PID"));break;
		case 5:s.SetMonitor();break;
		case 6:s.Evaluation();break;
		case 7:SetAutoPlay(getint("请设置延时（毫秒）"));
		case 8:s.PlayFirstProcess();
		case 9:s.print();break;
		default:cout << "输入有误" << endl;break;
		}
		system("pause");
		system("cls");
	}
    return 0;
}

