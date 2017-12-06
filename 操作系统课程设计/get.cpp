#include<iostream>

using namespace std;
int getint(const char* tips)
{
	int temp;
	bool good = false;
	while (!good)//失败无限重试
	{
		const char *txt = tips;
		while (*txt != '\0')cout << *txt++;//打印提示
		cout << '\n';

		cin >> temp;
		good = cin.good();
		cin.clear();//清空标志
		cin.ignore(1024, '\n');//清空缓冲区
		if (!good)cout << "输入错误" << endl;
	}
	return temp;
}