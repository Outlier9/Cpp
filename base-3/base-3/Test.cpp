#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;


//int main()
//{
//	int a = 0;
//	//// 引用，b就是a的别名
//	//int& b = a;
//
//	//cout << &b << endl;
//	//cout << &a << endl;
//
//	//1. 引用必须初始化
//	// int& b;
//	//b = c
//
//	//2. 引用定义后，不能改变指向
//	int& b = a;
//	int c = 2;
//	b = c; // 不是改变指向，而是赋值
//
//	//3. 一个变量可以有多个引用，多个别名
//	int& d = b;
//
//
//	return 0;
//}


// 指针和引用的功能是类似的，重叠的
// C++的引用，对指针使用比较复杂的场景进行一些替换，让代码更简单易懂，但是不能完全替代指针
// 应用不能完全代替指针原因：引用定义后，不能改变指向
//
//struct Node {
//	struct Node* next;
//	struct Node* prev;
//	int val;
//	// 不能用引用替代指针，引用不能改变指向（链表等）
//	
//};

//void PushBack(struct Node** pphead, int x)
//{
//	*pphead = newnode;
//}

//void PushBack(struct Node& phead, int x)
//{
//	//phead = newnode;
//}
//int main()
//{
//	struct Node* plist = NULL;
//}


//int& func()
//{
//	int a = 0;
//	return a;
//}
//int& fx()
//{
//	int b = 1;
//	return b;
//}
//
//
//void TestRef()
//{
//	int a = 10;
//	int& ra = a;//<====定义引用类型
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//}
//
//
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//
//int main()
//{
//	/*int& ret = func();
//	cout << ret << endl;
//
//	fx();
//	cout << ret << endl;*/
//
//	/*TestRef();*/
//
//	int& ret = Add(1, 2);
//	cout << "ret is :" << ret << endl;
//	Add(3, 4);
//	cout << "ret is :" << ret << endl;
//
//	return 0;
//}
// 
// 
// 
// ########################################
//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void main()
//{
//	A a; // 创建一个结构体A的实例a
//
//	// 1.以值作为函数参数的情况
//	size_t begin1 = clock(); // 获取执行函数调用前的时间
//	for (size_t i = 0; i < 10000; ++i) // 传值调用10000次，这种情况每调用一次就会产生一次拷贝
//		TestFunc1(a);
//	size_t end1 = clock();// 获取执行函数调用结束的时间
//
//	// 2.以引用作为函数参数
//	size_t begin2 = clock();// 获取执行函数调用前的时间
//	for (size_t i = 0; i < 10000; ++i) // 传引用调用10000次，这种情况每次调用都直接用的引用
//		TestFunc2(a);
//	size_t end2 = clock();// 获取执行函数调用结束的时间
//
//
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//	
//	// 结果
//	// TestFuncl(A) - time:9
//	// TestFunc2(A&) - time : 0
//}


// #########################################

// 如果要运行100w次，就要建立并销毁100w次栈帧
// C语言处理方法：
// 容易犯错注意点：
// 1、不是函数
// 2、分号
// 3、括号控制优先级
// 核心点：宏是预处理阶段进行替换
// #define ADD(int a, int b) return a+b;  ×
// #define ADD(a, b) a+b;  ×
// #define ADD(a, b) （a+b）;  ×
// #define ADD(a, b) ((a)+(b)) √
// 没有分号，每个变量也要加括号，因为运算符优先级，所以不加有可能会变成表达式

//#define ADD(a, b) ((a)+(b))
//
//
//int main()
//{
//	if (ADD(1, 2))
//	{
//
//	}
//	ADD(1, 2) * 3;
//
//	int x = 1, y = 2;
//	ADD(x | y, x & y); 
//
//	return 0;
//
//}

// 宏的缺点：
// 1、坑很多，语法复杂，不容易控制
// 2、不能调试，在预处理阶段就处理了
// 3、没有类型安全的检查


// C++处理方法
//inline int Add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int ret1 = Add(1, 2) * 3;
//
//	int x = 1, y = 2;
//	int ret2 = Add(x | y, x & y);
//
//	return 0;
//}


void TestFor1()
{
    int array[] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
        array[i] *= 2;

    for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
        cout << *p << endl;
}


void TestFor2()
{
    int array[] = { 1, 2, 3, 4, 5 };
    for (auto& e : array)
        e *= 2;

    for (auto e : array)
        cout << e << " ";

}


//int TestAuto()
//{
//    return 10;
//}
//int main()
//{
//    //int a = 10;
//    //auto b = a;
//    //auto c = 'a';
//    //auto d = TestAuto();
//
//    //cout << typeid(b).name() << endl; //int
//    //cout << typeid(c).name() << endl; //char
//    //cout << typeid(d).name() << endl; //int
//
//    //auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
//    
//    // ******************************
//    int x = 10;
//    auto a = &x;
//    auto* b = &x;
//    auto& c = x;
//    cout << typeid(a).name() << endl; //int*
//    cout << typeid(b).name() << endl; //int*
//    cout << typeid(c).name() << endl; //int
//    *a = 20;
//    *b = 30;
//    c = 40;
//    
//    return 0;
//}

void TestPtr()
{
    int* p1 = NULL;
    int* p2 = 0;
    int* p3 = nullptr;
}

void f(int)
{
    cout << "f(int)" << endl;
}
void f(int*)
{
    cout << "f(int*)" << endl;
}
int main()
{
    f(0); //f(int)
    f(NULL); //f(int)
    f((int*)NULL); //f(int*)
    f(nullptr);//f(int*)

    return 0;
}

