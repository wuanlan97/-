#include<iostream>

using namespace std;
int getint(const char* tips)
{
	int temp;
	bool good = false;
	while (!good)//ʧ����������
	{
		const char *txt = tips;
		while (*txt != '\0')cout << *txt++;//��ӡ��ʾ
		cout << '\n';

		cin >> temp;
		good = cin.good();
		cin.clear();//��ձ�־
		cin.ignore(1024, '\n');//��ջ�����
		if (!good)cout << "�������" << endl;
	}
	return temp;
}