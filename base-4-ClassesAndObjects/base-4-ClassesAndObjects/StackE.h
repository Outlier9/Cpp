#pragma once
#include<stdio.h>
#include<stdlib.h>
// 声明
struct Stack // struct默认访问限定符为public公有
{

	// 成员变量
	int* a;
	int top;
	int capacity;

public:
	// 成员函数
	void Init(int n = 4);
	void Push(int x);
};

class Queue // class默认访问限定符为private私有
{
public:
	//成员函数
	void Init(int n);
	void Push(int n);
};