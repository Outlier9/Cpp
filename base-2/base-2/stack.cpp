#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
//使用缺省参数，默认值必须在声明的时候给
void StackInit(struct Stack* ps, int n)
{
    //ps->a = NULL;
    ps->a = (int*)malloc(sizeof(int) * 100);
}

void StackPush(struct Stack* ps, int x)
{

}