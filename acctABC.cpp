#include<iostream>
#include"acctabc.h"
using std::cout;
using std::ios_base;
using std::endl;
using std::string;
 
//AcctABC
//const std::string &FullName()const { return fullname; }
//long AcctNum()const { return acctnum; }
AcctABC::Formatting AcctABC::SetFormat()const//
{
	Formatting f;
	f.flag = cout.setf(ios_base::fixed,ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}
void AcctABC::Restore(Formatting &f)const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}
AcctABC::AcctABC(const std::string &s , long an , double bal  )//
{
	fullname = s;
	acctnum = an;
	balance = bal;

}
void AcctABC::Deposit(double amt)//
{
	if (amt < 0)
		cout << "大于0\n";
	else
		balance += amt;
}
void AcctABC::Withdraw(double amt) //
{
	balance -= amt;
}
//double AcctABC::Balance()const { return balance; }

/*
void AcctABC::ViewAcct()const
{
cout << "账号名字：" << &FullName() << endl;
cout << "AcctNum:" << AcctNum() << endl;
cout << "Balance:$" << Balance() << endl;
}

*/
//virtual ~AcctABC() {}
//Barss
//Barss(const std::string &s = "Nullbody", long an = -1, double bal = 0.0:AcctABC(s, an, bal)) {}
void Barss::ViewAcct() const//
{
	Formatting f = SetFormat();
	cout << "Barss Clien Name:" << &FullName() << endl;
	cout << "AcctNum:" << AcctNum() << endl;
	cout << "Balance:$" << Balance() << endl;
	Restore(f);
}
void Barss::Wihtdraw(double amt)
//
{
	 double bal = Balance();
	if (amt < 0)
	{
		cout << "大于0.\n";
	}

	else if (amt <= bal )
	{
		AcctABC::Withdraw(amt);
	}
	else

		cout << "超出余额\n";

}


//virtual ~Barss() {}
//BarssPlus
BarssPlus::BarssPlus(const string &s, long an, double bal, double ml, double r)
	:AcctABC(s,an,bal)
{//
	maxLoan = ml;
	owesBank =0.0;
	rate = r;
}
BarssPlus::BarssPlus(const Barss &ba, double ml , double r ):AcctABC(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
void BarssPlus::ViewAcct()const
{
	//
	Formatting f = SetFormat();
	//cout << "BrassPlus Client:" << FullName() << endl;
	cout << "AcctNum:" << AcctNum() << endl;
	cout << "Balance:$" << Balance() << endl;
	cout << "maxLoan:$" << maxLoan << endl;
	cout << "Owed to Bank:" << owesBank << endl;
	cout.precision(3);
	cout << "Loan rate:" << 100 * rate << endl;
	Restore(f);

}
void BarssPlus::Withdraw(double amt)
{
	Formatting f = SetFormat();
	double bal =Balance();
	if (amt <= bal)
		cout << "错误\n";
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank advance:$" << advance << endl;
		cout << "Finance charge:$" << advance * rate << endl;

		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
		cout << "Creat limit exceeded.\n";
	Restore(f);
}
//void BarssPlus::ResetMax(double m) { maxLoan = m; }
//void BarssPlus::ResetRate(double r) { rate = r; }
//void ResetOwes() { owesBank = 0; }