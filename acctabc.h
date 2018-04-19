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
1.格式控制信息的枚举类型fmtflags ，影响到如何解释输入序列的格式、如何生成输出序列的格式，
例如整数是16进制还是10进制表示，
浮点数是科学计数法还是定点形式等；
2.流的状态的枚举类型iostate，如数据是否完整、是否到达流的末尾、是否读写失败等；
3.流的打开方式的枚举类型openmode，如读取、写入、追加、创建时删除原内容、二进制打开、
4.流的定位位置的枚举类型seekdir，如开始位置、当前位置、结尾位置等。
5.流的事件的枚举类型event，如“擦除”事件erase_event，改变locale设置事件imbue_event，
复制格式事件copyfmt_event。
6.流的私用的其它额外保存的数据，为一个long型数组与一个指针数组。
7.一个成员类failure，用于作为C++标准中的流输入输出类库抛出的各种异常的基类。
8.一个成员类Init，用于封装cout、cin、wcout等8个静态对象的初始化函数。
状态函数
ios_base::flags，读取/设置流的格式。
ios_base::setf，设置流的格式，与原有格式合并。
ios_base::unsetf，根据参数mask，清除流的格式的某些位（bit）。
ios_base::precision，读取/设置显示浮点数时的精度。
ios_base::width，读取/设定流的输出数据的显示宽度。
locale相关函数
ios_base::imbue，设置新的locale，并依次执行所有登记的回调函数处置imbue_event。
ios_base::getloc，读取当前locale设置
静态成员函数
ios_base::sync_with_stdio，设置流的内部标志位，确定是否与C运行时库的stdio在输入输出上同步。
私用数据存储函数
ios_base::xalloc，返回一个对于进程中的多线程来说是唯一的一个整形值，这个值对应于流的一个内存块的索引，该内存块可保存一个long或者指针值。
ios_base::iword，根据输入的索引值，返回流的一个内存块的引用，可保持一个long值。
ios_base::pword，根据输入的索引值，返回流的一个内存块的引用，可保持一个指针值。
回调函数
ios_base::register_callback，登记一个回调函数。一个流的所有回调函数的地址保存在一个单向链表中
。如果某个事件发生，则以登记的逆序依次调用每个回调函数。每个回调函数内部一般有个switch语句，进入相应的事件的处理分支。
构造/析构函数
ios_base::ios_base
ios_base::~ios_base：销毁前用erase_event为参数，调用登记的回调函数。
*/
