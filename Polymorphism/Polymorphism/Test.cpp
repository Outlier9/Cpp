#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//
//	/*ע�⣺����д�����麯��ʱ����������麯���ڲ���virtual�ؼ���ʱ����ȻҲ���Թ�����д(��
//   Ϊ�̳к������麯�����̳������������������ɱ����麯������),���Ǹ���д�����Ǻܹ淶��������
//   ����ʹ��*/
//   /*void BuyTicket() { cout << "��Ʊ-���" << endl; }*/
//};
//void Func(Person& p)
//{
//	// ��ͬ�Ķ�����ͬһ�����飬�в�ͬ�Ľ��
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
// ָ��p��B*���ͣ�ָ��B���͵Ŀռ䣬����test��ʱ��test���������this��A*���ͣ�p������testһ�ݣ�
// ���Դ��������A*���ͣ�ʹ���˸����ָ����Ϊ������ͬʱfunc����������д������pԭ��ָ��ľ���B���͵Ŀռ䣬
// ����ȥ����B���͵�func�������������B->������val=1����Ϊ��д�У���д���Ǻ�����ʵ�֣����������������õĸ��࣬
// ���Լ�ʹ����������д������ȱʡֵ�������õĸ���ģ���Ҳ��Ϊʲô������Բ���virtual��ԭ����Ϊ����д�ĸ��࣬
// �����Ѿ�������ؼ����ˣ�test������virtual�����Ի�

// final�ؼ���
// �������ܱ���д
//class Car
//{
//public:
//	virtual void Drive() final {} // ��final�ؼ��ʣ���ʾ�������ܱ���д
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};

// ʵ��һ���಻�ܱ��̳�
//class Car
//{
//public:
//
//private:
//	// C++98�ķ���������Ĺ��캯��˽��
//	// ����Ĺ����޷����ɺ�ʵ�֣�������������޷�ʵ����
//	// ���ǲ�ʵ�����Ļ��������ͨ��
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
//	Benz c; // ʵ�����ᱨ��
//	return 0;
//}

// C++11�ķ���
// final���ε���������࣬���ܼ̳�
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


// override�ؼ���
//class Car {
//public:
//	virtual void Drive() {}
//};
//class Benz :public Car {
//public:
//	// �ӵ��������д�麯��������Ƿ������д
//	virtual void Drive() override { cout << "Benz-����" << endl; }
//};


// ���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�
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



// �������Ĵ��������������¸���
// 1.��������һ��������Deriveȥ�̳�Base
// 2.Derive����дFunc1
// 3.Base������һ���麯��Func2��һ����ͨ����Func3
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
//    virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//    virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
//	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
//	cout << " ����ַ>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" ��%d���麯����ַ :0X%p,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}

//int main()
//{
//	Base b;
//	Derive d;
//	// ˼·��ȡ��b��d�����ͷ4bytes����������ָ�룬ǰ������˵���麯��������һ�����麯��
//	//ָ���ָ�����飬���������������һ��nullptr
//	// 1.��ȡb�ĵ�ַ��ǿת��һ��int*��ָ��
//	// 2.�ٽ�����ȡֵ����ȡ����b����ͷ4bytes��ֵ�����ֵ����ָ������ָ��
//	// 3.��ǿת��VFPTR*����Ϊ������һ����VFPTR����(�麯��ָ������)�����顣
//	// 4.���ָ�봫�ݸ�PrintVTable���д�ӡ���
//	// 5.��Ҫ˵�����������ӡ���Ĵ��뾭�����������Ϊ��������ʱ�����Ĵ����ɾ���
//	// ��������û�з�nullptr������Խ�磬���Ǳ����������⡣����ֻ��Ҫ��Ŀ¼���� - ���� - ������������
//	// �ٱ���ͺ��ˡ�
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
	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%p,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}



int main()
{
	Derive d;
	//cout << sizeof(d) << endl;

	// ��ȡBase1���ֵ����ָ��
	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);

	// ��ȡBase2���ֵ����ָ��
	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVTable(vTableb2);

	return 0;
}














