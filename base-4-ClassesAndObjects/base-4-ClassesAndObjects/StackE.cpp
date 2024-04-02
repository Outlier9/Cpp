#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"StackE.h"
#include<stdlib.h>

void Stack::Init(int n)
{
	a = (int*)malloc(sizeof(int) * n);
	if (nullptr == a)
	{
		perror("malloc…Í«Îø’º‰ ß∞‹");
		return;
	}
	capacity = n;
	top = 0;
}


void Stack::Push(int x)
{
	//..
	a[top++] = x;
}



