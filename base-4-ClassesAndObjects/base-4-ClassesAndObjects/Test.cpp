#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

//struct Stack
//{
//	// 成员变量
//	int* a;
//	int top;
//	int capacity;
//
//	// 成员函数
//	void Init(int n = 4)
//	{
//		a = (int*)malloc(sizeof(int) * n);
//		if (nullptr == a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		capacity = n;
//		top = 0;
//	}
//};



//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//
//	}
//
////private:
//	int _year;// 命名规范（非强制性），为了区分变量和参数
//	int _month; // 声明，不开辟空间
//	int _day;
//};

//int main()
//{
//	/*Date s;
//	s.Init(2024,3,24);
//	s.Print();*/
//
//	Date d1; // 定义，对象实例化,开辟空间
//	d1.Init(2024, 3, 24);
//	//d1._year++; 
//	// 
//	//Date::_year++; 
//	//不能因为他只是声明,类的成员变量是与类的实例相关联的
//	//因此不能通过类名来直接访问它们，而应该通过类的实例来访问
//
//
//}


//class A2
//{
//public:
//	void f2()
//	{
//		cout << "void f2()" << endl;
//	}
//};
//
//class A3
//{};
//
//int main()
//{
//	//Date d1;
//	//Date d2;
//	//d1._year;
//	//d2._year;
//	//d1.Print();
//	//d2.Print();
//
//	//// 没有成员变量的类对象大小为1byte，占位，标识对象实例化，定义出来存在过
//	//cout << sizeof(A2) << endl; // 1
//	//cout << sizeof(A3) << endl; // 1
//
//	//A2 aa1;
//	//A2 aa2;
//
//	A2 a2;
//	A2* p1 = &a2;
//	p1->f2();
//	a2.f2();
//
//	A2* p3 = nullptr;
//	p3->f2();
//
//	return 0;
//}

class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1, d2;
	d1.Init(2024, 3, 25);
	d2.Init(2024, 3, 26);
	d1.Print();
	d2.Print();

	return 0;

}









