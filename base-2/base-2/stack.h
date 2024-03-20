#pragma once
#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int* a;
    int size;
    int capacity;
};
//使用缺省参数，默认值必须在声明的时候给，缺省参数不能在函数声明和定义中同时出现
void StackInit(struct Stack* ps, int n = 4);
void StackPush(struct Stack* ps, int x);
