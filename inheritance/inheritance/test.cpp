#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "姓名：" << _name << endl;
//	}
//
//
//protected:
////private:
//	string _name = "peter";
//	int _age;
//	string _address;
//};
//
//class Student :public Person
//{
//public:
//	void func()
//	{
//		// 当_age在父类是私有的时候，子类不能直接访问
//		// cout << _age << endl;
//		// 但是可以间接使用
//		Print(); // 会打印出_age的值
//	}
//
//protected:
//	int _stuid;
//};
//
//class Teacher :public Person
//{
//protected:
//	int _jobid;
//};
//
//
//int main()
//{
//	Student t;
//	t._name += 'x';
//	t.Print();
//
//	return 0;
//}


//class Person
//{
//public:
//	void Print()
//	{
//		cout << "姓名：" << _name << endl;
//	}
//
////private:
//	string _name = "peter";
//	int _age;
//	string _address;
//};
//
//class Student :public Person
//{
//public:
//	void func()
//	{
//		
//	}
//
//protected:
//	int _stuid;
//};
//
//class Teacher :public Person
//{
//protected:
//	int _jobid;
//};
//
//
//int main()
//{
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Student t;
//	Person p = t;
//	Person& T = t;// 切片，如果T或者TT进行更改，也会改变t
//	Person* TT = &t;
//
//	//2.基类对象不能赋值给派生类对象
//	// t = T; // 父类不能赋值给子类对象
//
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	TT = &t;
//	Student* psl = (Student*)TT;
//	psl->_age = 10;
//	
//	TT = &p;
//	Student* psl2 = (Student*)TT;// 这种情况转换时虽然可以，但是会存在越界访问的问题
//	psl2->_age = 12;
//
//	return 0;
//}





//class Person
//{
//public:
//	void func()
//	{
//		cout << _num << endl;
//	}
//
//
//protected:
//	int _age;
//	int _num = 0;
//};
//
//class Student :public Person
//{
//public:
//	void func()
//	{
//		cout << _num << endl;
//		cout << Person::_num << endl; // 内部调用
//	}
//
//protected:
//	int _stuid;
//	int _num = 1;
//};
//
//class Teacher :public Person
//{
//protected:
//	int _jobid;
//};
//
//
//int main()
//{
//	Student t;
//	t.func();
//	t.Person::func(); // 外部调用
//
//	return 0;
//}


// 默认成员函数
class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person & p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};
class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
};
void Test()
{
	Student s1("jack", 18); 
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}

int main() {
	Test();
	return 0;
}


// 友元函数
//class Student;
//class Person
//{
//public:
//    friend void Display(const Person& p, const Student& s);
//protected:
//    string _name; // 姓名
//};
//
//class Student : public Person
//{
////protected:
//    int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//    cout << p._name << endl;
//    // cout << s._stuNum << endl; // 无法访问子类的
//    // 友元函数无法继承，除非变成public或者在子类中也添加友元函数
//}
//void main()
//{
//    Person p;
//    Student s;
//    Display(p, s);
//}


// 静态成员
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//}
//
//int main()
//{
//	TestPerson;
//	return 0;
//}


//class A
//{
//private:
//	int _a;
//};
//
//// 组合
//class B
//{
//private:
//	A _aa;
//	int _b;
//};





