# C++
C++学习阶段代码

## 一、C++入门

### 1.C++关键字

C++总计63个关键字，C语言32个关键字

![img](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709974784222-ab36e3d6-4b64-46c0-8d91-55a5651297ef.png)

### 2.命名空间

在C/C++中，变量、函数和后面要学到的类都是大量存在的，这些变量、函数和类的名称将都存在于全局作用域中，可能会导致很多冲突。使用命名空间的目的是**对标识符的名称进行本地化，以避免命名冲突或名字污染**，namespace:关键字的出现就是针对这种问题的。

```cpp
#include<stdio.h>
#include<stdlib.h>

int rand = 0; //会和stdlib内的函数名称发生命名冲突

int main()
{
    printf("%d\n", rand);
    return 0;
}
// 编译后后报错：error C2365: “rand”: 重定义；以前的定义是“函数”
```

（1）命名空间定义

关键字：namespace，后面跟命名空间的名字，然后加 {} ，{} 内即为命名空间的成员

```cpp
// bit是命名空间的名字，一般开发中是用项目名字做命名空间名
namespace bit1 // 还是全局
{
    int x = 0;
    int rand = 0;
    
    // 函数
    int Add(int left, int right)
    {
        return left + right;
    }
    
    // 结构体
    struct Node
    {
        struct Node* next;
        int val;
    };
}

namespace bit2 // 还是全局
{
    int x = 2;
}
//2. 命名空间可以嵌套
namespace N1
{
    int a;
    int b;
    int Add(int left, int right)
    {
        return left + right;
    }
    
    namespace N2
    {
        int c;
        int d;
        
        int Sub(int left, int right)
        {
           return left - right;
        }
    }
}
//3. 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
// ps：一个工程中的test.h和上面test.cpp中两个N1会被合并成一个

namespace N1
{
    int Mul(int left, int right)
    {
        return left * right;
    }
}
```

（2）命名空间使用

- 加命名空间名称及作用域限定符（比较麻烦）

```cpp
int main()
{
    printf("%d\n", N::a);
    return 0;    
}
```

- 使用using将命名空间中某个成员引入

```cpp
using N::b;
int main()
{
    printf("%d\n", N::a);
    printf("%d\n", b); // 上边已经引入，直接写b就会知道是N作用域内的
    return 0;    
}
```

- 使用using namespace 命名空间名称引入

```cpp
using namespce N; // 引入了整个作用域，展开命名空间
int main()
{
    printf("%d\n", N::a);
    printf("%d\n", b);
    Add(10, 20);
    return 0;    
}
```

> 关于域：
>
> 域
>
>  :: 域作用限定符
>
>  四种域：
>
>  全局域   -->   生命周期 访问
>
>  局部域   -->   生命周期 访问
>
>  命名空间域  -->         访问
>
>  类域
>
> 
>
> 编译器 搜索原则：
>
> 不指定域 1.当前局部域  2.全局域 
>
> 指定域   3.如果指定了，直接去指定域搜索

```cpp
int main()
{
	int x = 1;
	printf("hello world\n");
	printf("%d\n", x); // x=1，局部优先
	printf("%d\n", bit1::x); // 如果是::x，就默认是全局域
	printf("%d\n", bit2::x); // 如果想访问命名空间域内的变量，就是bit::x
	printf("%d\n", bit1::rand); // 放到namespace中就不会冲突了
	printf("%d\n", bit1::Add(1,2)); // 调用函数，指定作用域
	struct bit1::Node phead; // 结构体命名规范
	return 0;
}
```

> **std命名空间的使用惯例**：
>
> **std是C++标准库的命名空间，如何展开std使用更合理呢？**
>
> 1. 在日常练习中，建议直接using namespace std即可，这样就很方便。 
>
> 2. using namespace std展开，标准库就全部暴露出来了，如果我们定义跟库重名的类型/对象/函数，就存在冲突问题。该问题在日常练习中很少出现，但是项目开发中代码较多、规模大，就很容易出现。所以建议**在项目开发中使用，像std::cout这样使用时指定命名空间 + using std::cout展开常用的库对象/类型等方式。**

### 3.C++输入输出

```cpp
#include<iostream>
// std是C++标准库的命名空间名，C++将标准库的定义实现都放到这个命名空间中
using namespace std;
int main()
{
    cout<<"Hello world!!!"<<endl;
    int a;
    double b;
    char c;
     
    // 可以自动识别变量的类型
    cin>>a;
    cin>>b>>c;
     
    cout<<a<<endl;
    cout<<b<<" "<<c<<endl;
    
    return 0;
}
```

说明：

1.使用`cout`标准输出对象（控制台）和`cin`标准输入对象（键盘）时，**必须包含**`**<iostream>**`**头文件以及按命名空间使用方法使用**`**std**`。

2.cout和cin是全局的流对象，`**endl**`**是特殊的C++符号，表示换行输出**，他们都包含在包含`<iostream>`头文件中。

3.`<<`是流插入运算符，`>>`是流提取运算符。

4.使用C++输入输出更方便，不需要像`printf/scanf`输入输出时那样，需要手动控制格式。**C++的输入输出可以自动识别变量类型**。

5.实际上`**cout和cin**`**分别是ostream和istream类型的对象**，`>>和<<也`涉及运算符重载等知识，这些知识我们我们后续才会学习，所以我们这里只是简单学习他们的使用。后面我们还有一个章节更深入的学习`IO流`用法及原理。

注意：早期标准库将所有功能在全局域中实现，声明在后缀的头文件中，使用时只需包含对应头文件即可，后来将其实现在std命名空间下，为了和`C头文件`区分，也为了正确使用命名空间，规定C++头文件不带`.h`; 旧编译器（vc6.0）中还支持`<iostream.h>`格式，后续编译器已不支持，因此推荐使用`<iostream>+std`的方式。



### ⭐4.缺省参数

（1）缺省参数概念

缺省参数是声明或定义函数时为函数的参数指定一个缺省值。在调用该函数时，如果没有指定实参则采用该形参的缺省值，否则使用指定的实参。

```cpp
void Func(int a = 0)
{
    cout<<a<<endl;
}
int main()
{
    Func();     // 没有传参时，使用参数的默认值
    Func(10);   // 传参时，使用指定的实参

    return 0;
}
```

（2）缺省参数分类

①全缺省参数

```cpp
void Func(int a = 10, int b = 20, int c = 30)
{
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
}
```

②半缺省参数

```cpp
void Func(int a, int b = 10, int c = 20)
{
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
}
```

1. 半缺省参数必须从右往左依次来给出，不能间隔着给 

2. **缺省参数不能在函数声明和定义中同时出现****，**如果生命与定义位置同时出现，恰巧两个位置提供的值不同，那编译器就无法确定到底该 用那个缺省值。

3. 缺省值必须是常量或者全局变量 

4. C语言不支持（编译器不支持）

### ⭐5.函数重载

（1）函数重载概念

函数重载：是函数的一种特殊情况，C++允许在同一作用域中声明几个功能类似的同名函数，这些同名函数的形参列表(参数个数或类型或类型顺序)不同，常用来处理实现功能类似数据类型不同的问题。

三种形式：

- 参数类型不同
- 参数个数不同
- 参数类型顺序不同

```cpp
#include<iostream>
using namespace std;
// 1、参数类型不同
int Add(int left, int right)
{
    cout << "int Add(int left, int right)" << endl;
    return left + right;
}
double Add(double left, double right)
{
    cout << "double Add(double left, double right)" << endl;
    return left + right;
}

// 2、参数个数不同
void f()
{
    cout << "f()" << endl;
}
void f(int a)
{
    cout << "f(int a)" << endl;
}

// 3、参数类型顺序不同
void f(int a, char b)
{
    cout << "f(int a,char b)" << endl;
}
void f(char b, int a)
{
    cout << "f(char b, int a)" << endl;
}



int main()
{
    Add(10, 20);
    Add(10.1, 20.2);
    f();
    f(10);
    f(10, 'a');
    f('a', 10);
    return 0;
}
```

（2）**为什么C++支持函数重载，而C语言不支持呢？**

在C/C++中，一个程序要运行起来，要经历以下几个阶段：**预处理、编译、汇编、链接**

![img](https://cdn.nlark.com/yuque/0/2024/png/29309193/1710250789344-ede4ee74-9794-4a8e-bcff-5f9c897b9656.png)

> 项目通常是由多个头文件和多个源文件构成，【当前a.cpp中调用了b.cpp中定义的Add函数时】，编译后链接前，a.o的目标 文件中没有Add的函数地址，因为Add是在b.cpp中定义的，所以Add的地址在b.o中。
>
> 所以链接阶段就是专门处理这种问题，链接器看到a.o调用Add，但是没有Add的地址，就 会到b.o的符号表中找Add的地址，然后链接到一起。
>
> 那么链接时，面对Add函数，链接接器会使用哪个名字去找呢？这里每个编译器都有自己的函数名修饰规则。
>
> 在linux下，采用g++编译完成后，函数名字的修饰发生改变，编译器将函数参数类型信息添加到修改后的名字中。 
>
> **通过这里就理解了C语言没办法支持重载，因为同名函数没办法区分。而C++是通过函数修饰规则来区分，只要参数不同，修饰出来的名字就不一样，就支持了重载。**
>
> 如果两个函数函数名和参数是一样的，返回值不同是不构成重载的，因为调用时编译器没办法区分。

