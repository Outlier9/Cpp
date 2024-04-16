#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;


//struct ListNode
//{
//	ListNode* _next;
//	int _val;
//	ListNode(int val)
//		:_next(nullptr)
//		, _val(val)
//	{}
//};
//
//
//int main()
//{
//	// 1.用法上变简洁了
//	int* p0 = (int*)malloc(sizeof(int));
//	int* p1 = new int;
//	int* p2 = new int[10]; // new10个int对象
//	delete p1;
//	delete[] p2;
//
//	// 2.可以控制初始化
//	int* p3 = new int(10); // new一个int对象并初始化成10
//	/*int* p4 = new int[10]{ 1,2,3,4,5 };
//	int* p4 = new int[10]{ 1, 2, 3, 4, 5 };*/
//	/*int* p4 = new int[10]{ 1, 2, 3, 4, 5, 0, 0, 0, 0, 0 };*/
//	int* p4 = new int[10]{ 1, 2, 3, 4, 5 };
//
//	cout << *p4 << endl;
//
//
//
//	delete p3;
//	delete[] p4;
//
//	// 3.自定义类型，开空间+构造函数
//	// new失败了以后抛异常，不需要检查
//	ListNode* node1 = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	ListNode* node3 = new ListNode(3);
//
//	free(p0);
//	delete node1;
//	delete node2;
//	delete node3;
//
//	return 0;
//}


//template<typename T>
//// 函数模板
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp; 
//}
//
//
//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//	double d1 = 1.1, d2 = 2.2;
//	Swap(d1, d2);
//
//	swap(a, b);
//	std::swap(a, b);// std包含了swap函数，由于最开始已经展开了std，这里不写std::也可以
//
//	return 0;
//}




//template<class T>//模板参数列表typename<=>calss
//void Swap(T& a, T& b)
//{
//	T c = a;
//	a = b;
//	b = c;
//}
//
//int main()
//{
//	int x1, x2;
//	char c1, c2;
//	Swap(x1, x2);
//	Swap(c1, c2);
//
//	return 0;
//}



//template<class T>
//
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 1, a2 = 2;
//
//	double b1 = 1.1, b2 = 2.2;
//
//	cout << Add(a1, a2) << endl;
//	cout << Add(b1, b2) << endl;
//
//	// cout << Add(a1, b2) << endl; // 存在歧义
//	cout << Add(a1, (int)b2) << endl;
//	cout << Add((double)a1, b2) << endl;
//
//	// 显示实例化
//	cout << Add<int>(a1, b2) << endl;
//	cout << Add<double>(a1, b2) << endl;
//
//	return 0;
//}



//template<class T>
//
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int Add(const int& left, const int& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//
//	// 1.有现成用现成的（匹配）
//	cout << Add(a1, a2) << endl;
//	// 2.有现成但是不够匹配，有模板，就会选择自己实例化模板
//	cout << Add(d1, d2) << endl;
//	// 强制调用模板
//	cout << Add<int>(a1, a2) << endl;
//}



// 模板函数
template<typename T>
T TemplateAdd(const T& left, const T& right)
{
    return left + right;
}

// 普通函数
int NormalAdd(const int& left, const int& right)
{
    return left + right;
}



int main() 
{
    
    int a = 10;
    char b = 20;
    

    // cout << TemplateAdd(a, b) << endl; // 编译错误
    cout << NormalAdd(a, b) << endl;
    return 0;
}

