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
		cout << "�����˺����֣�";
		getline(cin,temp);
		cout << "�����˺ţ�";
		cin >> tempnum;
		cout << "������$";
		cin >> tempbal;
		cout << "1-Barss�˺ţ�2-BrassPlus�˺�";
		while (cin >> kind && (kind != '1'&& kind != '2'))
			cout << "����1����2\n";
		if (kind == '1')
		{
			BarssPlus *p = new  BarssPlus(temp, tempnum, tempbal);
			p_clients[i] = (Barss *)p;
			
		  
		}
		else
		{
			double tmax, trate;
			cout << "����͸֧���ƣ�$";
			cin >> tmax;
			cout << "�������ʣ�";
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