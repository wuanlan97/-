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
	s.NewProcess();
	//s.NewProcess();
	//s.NewProcess();
	s.print();

	system("pause");
    return 0;
}

