#include<iostream>
#include<string>
#include"acctabc.h"
using namespace std;
int main()
{
	AcctABC *p_clients[4];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;
	for (int i = 0; i < 2; i++)
	{
		cout << "输入账号名字：";
		getline(cin,temp);
		cout << "输入账号：";
		cin >> tempnum;
		cout << "输入余额：$";
		cin >> tempbal;
		cout << "1-Barss账号；2-BrassPlus账号";
		while (cin >> kind && (kind != '1'&& kind != '2'))
			cout << "输入1或者2\n";
		if (kind == '1')
		{
			BarssPlus *p = new  BarssPlus(temp, tempnum, tempbal);
			p_clients[i] = (Barss *)p;
			
		  
		}
		else
		{
			double tmax, trate;
			cout << "输入透支限制：$";
			cin >> tmax;
			cout << "输入利率：";
			cin >> trate;
			p_clients[i] = new BarssPlus(temp,tempnum,tempbal,tmax,trate);
		}
		while (cin.get() != '\n')
			continue;

	}
	cout << endl;
	for (int i = 0; i < 2; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		delete p_clients[i];
	}
	cout << "-------------------\n";
	system("pause");
	return 0;
}