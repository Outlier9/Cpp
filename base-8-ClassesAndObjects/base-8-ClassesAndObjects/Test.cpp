#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	A _aobj; // 没有默认构造函数
//	int& _ref; // 引用
//	const int _n; // const 
//};
//
//
//class Date
//{
//public:
//	// 初始化列表
//	// 
//	// 第一种写法
//	// 初始化列表是每个成员变量定义初始化的位置
//	// _n 属于const类型，也就是说只能定义一次
//	// 但是在构造函数中，可以多次初始化，这样就会破坏const，就需要用到初始化列表
//	Date(int year, int month, int day, int& x)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//		, _n(1)
//		, _ref(x)
//		, _aa(1)
//	{}
//
//	// 第二种写法
//	/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	// 必须走初始化列表
//	const int _n;
//	int& _ref;
//	A _aa;
//};
//
//int main()
//{
//	A _aa;
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{}
//
//	A(const A& aa)
//	{}
//};
//
//A Func()
//{
//	A aa;
//	cout << "Func" << endl;
//	return aa;
//}
//
//
//int main()
//{
//	A aa1;
//	A aa2;
//
//	return 0;
//
//}


//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//}

// A.输出1 1
// B.程序崩溃
// C.编译不通过
// D.输出1 随机值


class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};

class Date
{
public:
	Date(int day)
	{}
private:
	int _day;
	Time _t;
};


int main()
{
	Date d(1);
}
