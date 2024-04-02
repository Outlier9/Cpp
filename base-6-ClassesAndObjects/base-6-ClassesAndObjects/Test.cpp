#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;

//class Time
//{
//public:
//    ~Time()
//    {
//        cout << "~Time()" << endl;
//    }
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//class Date
//{
//private:
//    // 基本类型(内置类型)
//    int _year = 1970;
//    int _month = 1;
//    int _day = 1;
//    // 自定义类型
//    Time _t;
//};
//int main()
//{
//    Date d;
//    return 0;
//}



//class Date
//{
//public:
//    Date(int year = 1)
//    {
//        _year = year;
//    }
//
//
//    ~Date()
//    {
//        cout << "~Data()->" << _year << endl;
//    }
//private:
//    // 基本类型(内置类型)
//    int _year;
//    int _month;
//    int _day;
//};
//
//void func()
//{
//    Date d3(3);
//    static Date d4(4);
//}
//
//// 销毁顺序：局部对象（后定义先析构）--> 局部的静态 --> 全局对象（后定义先析构）
//int main()
//{
//    Date d1(1);
//    Date d2(2);
//    func();
//
//    return 0;
//}

///////////////////////////////////
// 拷贝构造函数
//class Date
//{
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    Date(const Date& d)
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//private:
//    // 基本类型(内置类型)
//    int _year;
//    int _month;
//    int _day;
//
//    
//};
//int main()
//{
//    Date d1(2024,3,30);
//    Date d2(d1);
//
//
//    d1.Print();
//    d2.Print();
//    return 0;
//}


//int main()
//{
//	int a = 0;
//	int& b = a;
//
//	const int x = 10;
//
//	// int& m = a + x; // a+x只是临时的变量，不能赋值给引用的变量
//
//	double d = 1.1;
//	int i = d;
//
//	int r = d;
//	const int& ri = d; // 临时变量具有常性，d是把临时拷贝给ri，所以必须有const
//
//	return 0;
//}


class Date
{
public:
    Date(int year = 1, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    Date(const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

    // 基本类型(内置类型)
    int _year;
    int _month;
    int _day;

    
};

bool operator==(const Date& x, const Date& y)
{
    return x._year == y._year
        && x._month == y._month
        && x._day == y._day;
}

bool operator<(const Date& x, const Date& y)
{
    if (x._year < y._year)
    {
        return true;
    }
    else if(x._year == y._year)
    {
        if (x._month < y._month)
        {
            return true;
        }
        else if (x._month == y._month)
        {
            return x._day < y._day;
        }
    }
    return false;
    
}



int main()
{
    Date d1(2024,1,30);
    Date d2(2024, 3, 29);
    
    cout << operator==(d1, d2) << endl;
    cout << operator<(d1, d2) << endl;
    return 0;
}






