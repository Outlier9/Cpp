#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

//using std::cout;
//using std::cin;
//using std::endl;
using namespace std;
//
////2. 命名空间可以嵌套
//namespace N1
//{
//    int a;
//    int b;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//
//    namespace N2
//    {
//        int c = 10;
//        int d;
//
//        int Sub(int left, int right)
//        {
//            return left - right;
//        }
//    }
//}
//
//int main()
//{
    //// “<<”运算符
    //int i = 100;
    //i = i << 1;
    //const char* str = "hello world!";
    //char ch = '\n';

    ////cout << N1::N2::c << endl; // 嵌套
    //

    //// 流插入，自动识别类型
    //cout << i << endl; // endl相当于'\n'
    ////printf("%s%d%c",str,i,ch);

    //// 流提取
    //cin >> i >> ch;
    //cout << i << ch << endl;
    ////scanf("%d%c", &i, &ch);
//
//
//    double d = 1.1111;
//    printf("%.2lf\n", d);
//    cout << d << endl;
//
//    return 0;
//}

// 缺省参数
// 全缺省
//void Func(int a = 10, int b = 20, int c = 30)
//{
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//    //四种调用方法
//    Func(1,2,3);
//    Func(1,2);
//    Func(1);
//    Func();
//
//    return 0;
//}

// 半缺省 从右往左连续给，部分缺省（a可以不给默认值，但是其余的不能跳着给）
//void Func(int a, int b = 20, int c = 30)
//{
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//    //四种调用方法
//    Func(1, 2, 3);
//    Func(1, 2);
//    Func(1);
//
//    return 0;
//}

#include"stack.h"

//int main()
//{
//    //灵活节省空间
//    //1.确定要插入100个数据
//    struct Stack st1;
//    StackInit(&st1, 100);
//
//    //2.只插入10个数据
//    struct Stack st2;
//    StackInit(&st2, 100);
//
//    //3.不确定要插入多少个
//    struct Stack st3;
//    StackInit(&st3);
//
//    return 0;
//}

//C语言不允许同名函数
//CPP允许同名函数，要求：函数名相同，参数不同，构成函数重载
//1.参数类型不同
//2.参数个数不同
//3.参数顺序不同


int Add(int left, int right)
{
    cout << "int Add(int left, int right)" << endl;
    return left + right;
}

int Add(double left, double right)
{
    cout << "double Add(int left, double right)" << endl;
    return left + right;
}

int main()
{
    Add(1, 2);
    Add(1.1, 2.2);

    return 0;
}


// C语言不支持重载 连接时，直接用函数名去找地址，有同名函数区分不开
// CPP如何支持？函数名修饰规则，名字中引入参数类型，各个编译器自己实现了一套


