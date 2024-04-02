#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;

//class A
//{
//private:
//	int _a;
//	char _i;
//};
//
//class B
//{
//private:
//	char _i;
//	int _a;
//	
//};
//
//
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	return 0;
//}


//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
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
//	}
//
//	//const Date* const this
//	// const在指针之前，修饰指向的内容（也就是指针指向的内容，而不是指针），在*之后，修饰指针本身
//
//	/*void Print(Date* const this) // this无法被改变
//	{
//		cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
//		// 这里可以写"this->",但是一般不写
//	}*/
//
//	// 特点：
//	// 1.形参和实参的位置，不能显示写
//	// 2.函数内部可以使用
//};

//int main()
//{
//	Date d1;
//	Date d2;
//
//	d1.Init(2024, 3, 26);
//	d2.Init(2024, 3, 27);
//
//	d1.Print();
//	d2.Print();
//
//	//d1.Print(&d1);
//	//d2.Print(&d2);
//	// 与C语言中该语法对应，但是不能显示写，对应特点 1
//}

// 关于this指针
// this存在在哪里 -> b
// a堆 b栈 c静态区 d常量区 e对象里面
// a.malloc出来的在堆中（需要手动释放）
// b.因为他是一个形参，局部变量，存在栈区（有些编译器比如VS可能用寄存器传递存储，因为需要频繁访问）
// c.全局和static存在静态区
// d.C++中const变量不在常量区


//class A
//{
//public:
//	void PrintA()
//	{
//		// cout << _a << endl; // 试图访问一个不存在的对象的成员
//		cout << this << endl; // this 指向的是调用该函数的 A 类对象的地址，this 指针是有效的，因为它指向了一个合法的对象
//	}
//private:
//	int _a;
//};
//
//
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//	// A.编译错误 B.√运行崩溃(对应上边_a) C.正常运行(对应上边this)
//	(*p).PrintA();
//	// A.编译错误 B.运行崩溃 C.√正常运行
//	//（对应上边this，这里依然是正常运行
//	//因为p指向了空指针，PrintA函数并没有存到对象里边
//	//所以并没有发生解引用，只是传递了this指针）
//	//编译器如果解引用没有实际意义
//
//	return 0;
//}


// 特殊的成员函数
//class Date
//{
//
//public:
//	//Date() // 构造函数，作用是初始化，与类名相同，无返回值，可以设默认值，对象实例化时必须有构造函数，必须得有
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	//Date(int year, int month, int day) // 函数重载
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	Date(int year = 1, int month = 1, int day = 1) // 缺省参数方法，但是虽然可以重载，却会和构造函数会发生冲突
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//
//	//Date func();
//	//Date d1(); // 这种写法会与函数声明发生冲突
//
//	Date d1;
//	d1.Print(); // 直接调用成员函数，会自动初始化
//
//	Date d2(2024, 3, 26); // 创建对象实例化时并初始化
//	d2.Print();
//
//	Date d3(2024); // 缺省参数方法
//	d3.Print();
//
//}

// 构造函数：默认成员函数，我们不写编译器会生成一个，但是还需要自己实现一个构造函数
//class Date
//{
//public:
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//// 声明，可以给缺省值去初始化，但不是定义，仍然是声明
//private:
//	int _year = 1;
//	int _month = 1;
//	int _day;
//};


// 内置类型、基本类型     int/char/double/指针 语言自己自身定义的类型
// 自定义类型             struct/class
// 默认生成的构造函数，对于内置函数不做处理，自定义类型会去调用它的默认构造
// 如果我们没有写任何构造函数，才会生成

//分析一个类型成员和初始化需求
//需要写构造函数我们就自己写，不需要时就用编译器自己生成的
//绝大多数场景下都需要自己实现构造函数

//int main()
//{
//	Date d1;
//	d1.Print();
//	
//	return 0;
//}


//class Time
//{
//public:
//    Time()
//    {
//        cout << "Time()" << endl;
//        _hour = 0;
//        _minute = 0;
//        _second = 0;
//    }
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//class Date
//{
//private:
//    // 基本类型(内置类型)
//    int _year;
//    int _month;
//    int _day;
//    // 自定义类型
//    Time _t;
//};
//
//int main()
//{
//    Date d;
//    return 0;
//}


//class Date
//{
//
//public:
//	Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	~Date() // 析构函数，在前边加一个~符号，不支持重载，没有参数，无返回值类型，程序结束时自动调用
//	{
//		cout << "~Date" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//}

typedef int DataType;

class Stack
{
public:
    Stack(size_t capacity = 3)
        : _capacity(capacity), _size(0)
    {
        _array = new DataType[capacity];
        if (!_array)
        {
            throw std::bad_alloc();
        }
    }
    
    ~Stack()
    {
        delete[] _array;
        _array = nullptr;
    }
    
    void Push(DataType data)
    {
        if (IsFull())
        {
            throw std::overflow_error("Stack is full");
        }
        _array[_size++] = data;
    }
    
    DataType Pop()
    {
        if (IsEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }
        return _array[--_size];
    }
    
    DataType Top() const
    {
        if (IsEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }
        return _array[_size - 1];
    }
    
    bool IsEmpty() const
    {
        return _size == 0;
    }
    
    bool IsFull() const
    {
        return _size == _capacity;
    }

private:
    DataType* _array;
    int _capacity;
    int _size;
};

void TestStack()
{
    Stack s(5); // 指定栈的容量
    for (int i = 1; i <= 5; ++i)
    {
        try
        {
            s.Push(i);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }
    
    while (!s.IsEmpty())
    {
        std::cout << s.Pop() << '\n';
    }
}

int main()
{
    try
    {
        TestStack();
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred: " << e.what() << '\n';
    }

    return 0;
}
