#pragma once
#include<iostream>
#include<assert.h>
using namespace std;


class Date
{
public:
	bool CheckInvalid() const;

	Date(int year = 1, int month = 1, int day = 1);

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	// 日期加等天数
	Date& operator+=(int day);
	// 日期加天数
	Date operator+(int day) const;
	// 日期减等天数
	Date& operator-=(int day);
	// 日期减天数
	Date operator-(int day) const;

	// 前置++
	Date& operator++();
	// 后置++，特殊情况，给一个int形参,强行构成重载进行区分
	Date operator++(int);

	// 前置--
	Date& operator--();
	// 后置--，特殊情况，给一个int形参,强行构成重载进行区分
	Date operator--(int);

	// 日期减日期，整型函数重载
	int operator-(const Date& d);




	// 本质就是linline,获取当前月天数
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31 ,30, 31 , 30, 31 };

		// 闰年判断
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return monthDays[month];
	}

	void Print()const  // 不加const，会发生权限放大，类型为Date*，需要变为const Date*，在C++中写法为在函数后边加const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	// 如果写成成员函数，隐式传this，那么this占据了第一个参数，Date必须是左操作数，流方向就返了，且this还不可更改
	// 因此该运算符重载不能写成员函数，要写成全局函数，才能控制Date和流方向
	/*void operator<<(ostream& out)
	{
		out << _year << "年" << _month << "月" << _day << "日" << endl;
	}*/

	// 友元声明,它被允许访问类的私有成员
	// 友元声明的语法是使用 friend 关键字，后面跟着函数原型。
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

private:
	int _year;
	int _month;
	int _day;
};
// 输出流运算符重载
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d); // 不能加const