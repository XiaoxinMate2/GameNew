#pragma once
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include<iostream>
#include<string>
using namespace std;
class AcctABC
{
private:
	std::string fullname;
	long acctnum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
   const  std::string  & FullName()const { return fullname; }
	long AcctNum()const { return acctnum; }
	Formatting SetFormat()const;
	void Restore(Formatting &f)const;
public:
	AcctABC(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	double Balance()const { return balance; }
	virtual void Withdraw(double amt) =0;
	virtual void ViewAcct()const  = 0;
	virtual ~AcctABC() {}
};
class Barss :public AcctABC
{
public:
	Barss(const std::string &s = "Nullbody", long an = -1, double bal = 0.0) :AcctABC(s, an, bal) {}

	virtual void ViewAcct() const;
	virtual void Wihtdraw(double amt) ;

	virtual ~Barss() {}
};
class BarssPlus:public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BarssPlus(const std::string &s="Nullbody",long an=-1,double bal=0.0,double ml=500,double r=0.10);
	BarssPlus(const Barss &ba,double ml=500,double r=0.1);
	virtual void ViewAcct()const;
	virtual void Withdraw(double amt) ;
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};
#endif // !ACCTABC_H_

/*
1.��ʽ������Ϣ��ö������fmtflags ��Ӱ�쵽��ν����������еĸ�ʽ���������������еĸ�ʽ��
����������16���ƻ���10���Ʊ�ʾ��
�������ǿ�ѧ���������Ƕ�����ʽ�ȣ�
2.����״̬��ö������iostate���������Ƿ��������Ƿ񵽴�����ĩβ���Ƿ��дʧ�ܵȣ�
3.���Ĵ򿪷�ʽ��ö������openmode�����ȡ��д�롢׷�ӡ�����ʱɾ��ԭ���ݡ������ƴ򿪡�
4.���Ķ�λλ�õ�ö������seekdir���翪ʼλ�á���ǰλ�á���βλ�õȡ�
5.�����¼���ö������event���硰�������¼�erase_event���ı�locale�����¼�imbue_event��
���Ƹ�ʽ�¼�copyfmt_event��
6.����˽�õ��������Ᵽ������ݣ�Ϊһ��long��������һ��ָ�����顣
7.һ����Ա��failure��������ΪC++��׼�е��������������׳��ĸ����쳣�Ļ��ࡣ
8.һ����Ա��Init�����ڷ�װcout��cin��wcout��8����̬����ĳ�ʼ��������
״̬����
ios_base::flags����ȡ/�������ĸ�ʽ��
ios_base::setf���������ĸ�ʽ����ԭ�и�ʽ�ϲ���
ios_base::unsetf�����ݲ���mask��������ĸ�ʽ��ĳЩλ��bit����
ios_base::precision����ȡ/������ʾ������ʱ�ľ��ȡ�
ios_base::width����ȡ/�趨����������ݵ���ʾ��ȡ�
locale��غ���
ios_base::imbue�������µ�locale��������ִ�����еǼǵĻص���������imbue_event��
ios_base::getloc����ȡ��ǰlocale����
��̬��Ա����
ios_base::sync_with_stdio�����������ڲ���־λ��ȷ���Ƿ���C����ʱ���stdio�����������ͬ����
˽�����ݴ洢����
ios_base::xalloc������һ�����ڽ����еĶ��߳���˵��Ψһ��һ������ֵ�����ֵ��Ӧ������һ���ڴ������������ڴ��ɱ���һ��long����ָ��ֵ��
ios_base::iword���������������ֵ����������һ���ڴ������ã��ɱ���һ��longֵ��
ios_base::pword���������������ֵ����������һ���ڴ������ã��ɱ���һ��ָ��ֵ��
�ص�����
ios_base::register_callback���Ǽ�һ���ص�������һ���������лص������ĵ�ַ������һ������������
�����ĳ���¼����������ԵǼǵ��������ε���ÿ���ص�������ÿ���ص������ڲ�һ���и�switch��䣬������Ӧ���¼��Ĵ����֧��
����/��������
ios_base::ios_base
ios_base::~ios_base������ǰ��erase_eventΪ���������õǼǵĻص�������
*/
