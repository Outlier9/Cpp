#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "������" << _name << endl;
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
//		// ��_age�ڸ�����˽�е�ʱ�����಻��ֱ�ӷ���
//		// cout << _age << endl;
//		// ���ǿ��Լ��ʹ��
//		Print(); // ���ӡ��_age��ֵ
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
//		cout << "������" << _name << endl;
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
//	// 1.���������Ը�ֵ���������/ָ��/����
//	Student t;
//	Person p = t;
//	Person& T = t;// ��Ƭ�����T����TT���и��ģ�Ҳ��ı�t
//	Person* TT = &t;
//
//	//2.��������ܸ�ֵ�����������
//	// t = T; // ���಻�ܸ�ֵ���������
//
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	TT = &t;
//	Student* psl = (Student*)TT;
//	psl->_age = 10;
//	
//	TT = &p;
//	Student* psl2 = (Student*)TT;// �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
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
//		cout << Person::_num << endl; // �ڲ�����
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
//	t.Person::func(); // �ⲿ����
//
//	return 0;
//}


// Ĭ�ϳ�Ա����
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
	string _name; // ����
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
	int _num; //ѧ��
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


// ��Ԫ����
//class Student;
//class Person
//{
//public:
//    friend void Display(const Person& p, const Student& s);
//protected:
//    string _name; // ����
//};
//
//class Student : public Person
//{
////protected:
//    int _stuNum; // ѧ��
//};
//
//void Display(const Person& p, const Student& s)
//{
//    cout << p._name << endl;
//    // cout << s._stuNum << endl; // �޷����������
//    // ��Ԫ�����޷��̳У����Ǳ��public������������Ҳ�����Ԫ����
//}
//void main()
//{
//    Person p;
//    Student s;
//    Display(p, s);
//}


// ��̬��Ա
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " ���� :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " ���� :" << Person::_count << endl;
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
//// ���
//class B
//{
//private:
//	A _aa;
//	int _b;
//};





