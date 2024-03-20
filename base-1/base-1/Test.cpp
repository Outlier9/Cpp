#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

// 解决命名变量冲突的情况
//命名空间名称可以重复，会自动合并，但是内部的变量还是不能重复
//namespace bit1 // 还是全局
//{
//	int x = 0;
//	int rand = 0;
//	// 函数
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	// 结构体
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//
//
//}
//
//namespace bit2 // 还是全局
//{
//	int x = 2;
//}

//int rand = 0; //会和stdlib内的函数名称发生命名冲突

// 域
// :: 域作用限定符
// 
// 全局域      生命周期 访问
// 局部域      生命周期 访问
// 命名空间域           访问
// 类域

//编译器 搜索原则：
//不指定域 1.当前局部域  2.全局域 
//指定域   3.如果指定了，直接去指定域搜索

//int main()
//{
//	int x = 1;
//	printf("hello world\n");
//	printf("%d\n", x); // x=1，局部优先
//	printf("%d\n", bit1::x); // 如果是::x，就默认是全局域
//	printf("%d\n", bit2::x); // 如果想访问命名空间域内的变量，就是bit::x
//	printf("%d\n", bit1::rand); // 放到namespace中就不会冲突了
//	printf("%d\n", bit1::Add(1,2)); // 调用函数，指定作用域
//	struct bit1::Node phead; // 结构体命名规范
//	return 0;
//}

#include"List.h"
#include"Queue.h"

// 展开命名空间
//using namespace bit1;
//using namespace bit2;
//
//int main()
//{
//	//printf("hello world\n");
//
//	struct QNode node1;// using namespace bit1;
//	struct bit1::QNode node2;
//	struct LNode node3; // using namespace bit2;用到这个就可以直接访问到bit2中
//	struct bit2::LNode node4; 
//	
//	return 0;
//}


#include<iostream>

// 展开命名空间，但是在项目中不能经常用，会发生命名冲突
using namespace std;

int main()
{
	cout << "hello world" << endl;
	//std::cout << "hello world" << std::endl;// 如果不加using namespace std;

	return 0;
}












