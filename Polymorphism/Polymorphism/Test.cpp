#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//
//	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
//   为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
//   这样使用*/
//   /*void BuyTicket() { cout << "买票-半价" << endl; }*/
//};
//void Func(Person& p)
//{
//	// 不同的对象做同一种事情，有不同的结果
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//	return 0;
//}

//
//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}
// B->1
// 指针p是B*类型，指向B类型的空间，调用test的时候，test函数本身的this是A*类型，p拷贝给test一份，
// 所以传入的属于A*类型，使用了父类的指针作为参数，同时func函数构成重写，但是p原本指向的就是B类型的空间，
// 所以去调用B类型的func函数，所以输出B->，但是val=1，因为重写中，重写的是函数的实现，函数的声明还是用的父类，
// 所以即使在子类中重写设置了缺省值，还是用的父类的，这也是为什么子类可以不加virtual的原因，因为是重写的父类，
// 父类已经有这个关键词了，test函数的virtual属于迷惑

// final关键字
// 函数不能被重写
//class Car
//{
//public:
//	virtual void Drive() final {} // 用final关键词，表示函数不能被重写
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};

// 实现一个类不能被继承
//class Car
//{
//public:
//
//private:
//	// C++98的方法，父类的构造函数私有
//	// 子类的构造无法生成和实现，导致子类对象无法实例化
//	// 但是不实例化的话编译可以通过
//	Car(){}
//};
//class Benz :public Car
//{
//public:
//	
//};
//
//int main()
//{
//	Benz c; // 实例化会报错
//	return 0;
//}

// C++11的方法
// final修饰的类叫最终类，不能继承
//class Car final
//{
//public:
//
//private:
//	
//	Car() {}
//};
//class Benz :public Car
//{
//public:
//
//};
//
//int main()
//{
//	
//	return 0;
//}


// override关键字
//class Car {
//public:
//	virtual void Drive() {}
//};
//class Benz :public Car {
//public:
//	// 加到子类的重写虚函数，检查是否完成重写
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};


// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//	char _ch = 'x';
//};
//
//int main()
//{
//	Base b;
//	cout << sizeof(Base) << endl;
//	return 0;
//}



// 针对上面的代码我们做出以下改造
// 1.我们增加一个派生类Derive去继承Base
// 2.Derive中重写Func1
// 3.Base再增加一个虚函数Func2和一个普通函数Func3
//class Base
//{
//public:
//    virtual void Func1()
//    {
//        cout << "Base::Func1()" << endl;
//    }
//    virtual void Func2()
//    {
//        cout << "Base::Func2()" << endl;
//    }
//    void Func3()
//    {
//        cout << "Base::Func3()" << endl;
//    }
//private:
//    int _b = 1;
//};
//class Derive : public Base
//{
//public:
//    virtual void Func1()
//    {
//        cout << "Derive::Func1()" << endl;
//    }
//private:
//    int _d = 2;
//};
//int main()
//{
//    Base b;
//    Derive d;
//    return 0;
//}


//class Person {
//public:
//    virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//    virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//void Func(Person* p)
//{
//    p->BuyTicket();
//}
//
//int main()
//{
//    Person Mike;
//    Func(&Mike);
//
//    Student Johnson;
//    Func(&Johnson);
//
//    return 0;
//}



//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	b.func1();
//	b.func2();
//
//	d.func1();
//	d.func2();
//	d.func3();
//	d.func4();
//
//    return 0;
//}


//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%p,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}

//int main()
//{
//	Base b;
//	Derive d;
//	// 思路：取出b、d对象的头4bytes，就是虚表的指针，前面我们说了虚函数表本质是一个存虚函数
//	//指针的指针数组，这个数组最后面放了一个nullptr
//	// 1.先取b的地址，强转成一个int*的指针
//	// 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
//	// 3.再强转成VFPTR*，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组。
//	// 4.虚表指针传递给PrintVTable进行打印虚表
//	// 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，
//	// 虚表最后面没有放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的 - 生成 - 清理解决方案，
//	// 再编译就好了。
//
//	VFPTR * vTableb = (VFPTR*)(*(int*)&b);
//	PrintVTable(vTableb);
//	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTabled);
//	return 0;
//}


class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%p,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}



int main()
{
	Derive d;
	//cout << sizeof(d) << endl;

	// 获取Base1部分的虚表指针
	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);

	// 获取Base2部分的虚表指针
	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVTable(vTableb2);

	return 0;
}














