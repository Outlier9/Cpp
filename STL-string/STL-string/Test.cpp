#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>
using namespace std;



//int main()
//{
//	int x = 0, y = 1;
//	swap(x, y);
//
//	double m = 1.1, n = 2.2;
//	swap(m, n);
//
//	char p = 'a', q = 'b';
//	swap(p, q);
//
//	cout << x << y << m << n << endl;
//	cout << p << q << endl;
//
//	return 0;
//}

//typedef int STDataType;//��typedefֻ�ܽ��һ������
//
//template<class T>
//class Stack
//{
//public:
//	void push(const T& x)
//	{
//		//
//	}
//
//private:
//	T* _a;
//	int _top;
//	int _capacity;
//
//};
//
//int main()
//{
//	Stack<int> s1;  // ��ģ�壬ͬһ����ģ�����ʵ��������������
//	Stack<double> s1;
//
//
//}

///////////////////////////////////////////////////////////////////
// �ڴ�����ֲ���
//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//
//	cout << sizeof(num1) << " " << sizeof(char2) << " " << strlen(char2) << " " << sizeof(pChar3) << " " << strlen(pChar3) << " " << sizeof(ptr1) << endl;
//
//	free(ptr1);
//	free(ptr3);
//}
//
//int main()
//{
//	Test();
//	
//	return 0;
//		
//}
///////////////////////////////////////////////////////////////////


void test_string1()
{
	string s0; //ʲôҲû��
	string s1("hello world"); // ���ַ���"hello world"
	string s2(s1); // �������죬��s1��s2
	string s3(s1, 5, 3); // �������죬�ӵ������Ҳ���ǵ�������ʼ��ȡ��λ�����������s3
	string s4(s1, 5, 10);  // �������죬�ӵ������Ҳ���ǵ�������ʼ��ȡʮλ�����������s4��û��ʮλ��ʣ�µ�
	string s5(s1, 5); // �������죬�ӵ������Ҳ���ǵ�������ʼ�����������s5
	string s6(10, '#'); // ʮ��#����һ���ַ���

	cout << s0 << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << sizeof(void*) << endl;
}


//class string
//{
//public:
//	char& operator[](size_t pos)
//	{
//		return _str[pos];
//	}
//private:
//	char* _str;
//	size_t _size;
//	size_t _capacity;
//};


void test_string2()
{
	string s1("hello world");
	// �����ַ���
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
		// cout << s1.operator[](i) << endl;
	}
	cout << endl;
	// ÿ���ַ�����1
	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
	}
	cout << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	const string s2("hello world");// �����޸ģ�ֻ��
	// s2[0]++; // ����

	string s3("hello world !!!!!!!");
	s3[0]++;

	cout << s3.size() << endl;
	cout << s3.capacity() << endl;

	// ������
	string::iterator it3 = s1.begin();
	while (it3 != s1.end())
	{
		cout << *it3 << " ";
		it3++;
	}
	cout << endl;

	// ���������
	string::reverse_iterator rit3 = s1.rbegin();
	while (rit3 != s1.rend())
	{
		cout << *rit3 << " ";
		rit3++;
	}
	cout << endl;
}

void test_string3()
{
	string s1("hello world");
	string::iterator it5 = s1.begin();
	while (it5 != s1.end())
	{
		cout << *it5 << " ";
		it5++; 
	}
	cout << endl;

	const string s2("hello world");
	string::const_iterator it6 = s2.begin();
	while (it6 != s2.end())
	{
		cout << *it6 << " ";
		it6++;
		// *it6 += 3; // ����const������ֻ��
	}
	cout << "************************" << endl;

}


void test_string4()
{
	string s1("hello world hello world hello world hello world hello world hello world hello world hello world ");
	cout << s1.size() << endl;
	cout << s1.length() << endl;

	cout << s1.max_size() << endl;
	cout << s1.capacity() << endl;

	// ���ݻ���
	string s;
	size_t sz = s.capacity();
	cout << "capacity:" << sz << '\n';

	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}

	// �����ǰs1�����ʹ洢ռ�õĴ�С
	cout << "�����ǰs1,s1�����ʹ洢ռ�õĴ�С" << endl;
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;
	// ������ݣ�û������������鿴s1�����ʹ洢ռ�õĴ�С
	cout << "������ݣ�û������������鿴s1,s1�����ʹ洢ռ�õĴ�С" << endl;
	s1.clear();
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;
	// ���ݣ�Ĭ������15���ٴβ鿴s1�����ʹ洢ռ�õĴ�С
	cout << "���ݣ�Ĭ������15���ٴβ鿴s1�����ʹ洢ռ�õĴ�С" << endl;
	s1.shrink_to_fit(); 
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;

	// reserve // ����---> ���ݣ���ǰ�������ٸ�����,����һ���͸�������һ����ֻ����󣩣���g++���ǿ����ٸ�����
	// reveser // ��ת����ת
	cout << "�����ǰs1,s1�����ʹ洢ռ�õĴ�С" << endl;
	s1.reserve(100);
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;

}

void test_string5()
{
	string s1("hello world hello world hello world hello world hello world hello world hello world hello world ");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.reserve(50); // ��ʵֻ�б����ڵ�������Ż���Ч����������
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	cout << "-----------------" << endl;

	// resize() ����sizeΪ17
	//       10    ɾ��       <size
	//       20    ����       size < n < capacity �����Ĭ���ǡ�\0��,Ҳ����ָ�����������ڸ������Ϳ���
	//       40    ����+����  capacity < n
	string s2("hello world");
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	cout << "---------<size--------" << endl;

	s2.resize(10);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	cout << "---------size < n < capacity--------" << endl;

	s2.resize(14);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	cout << "---------capacity < n--------" << endl;

	s2.resize(40,'x');
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
}


void test_string6()
{
	string s1("hello world");
	cout << s1[5] << endl;
	cout << s1.at(5) << endl;

	// s1[15]; // Խ�糬�������쳣
	// s1.at(15);
}


void test_string7()
{
	string s1("hello world");

	s1.push_back('!'); // ֻ�ܼ��ַ�
	cout << s1 << endl;

	s1.append("hello append!"); // ���ַ���
	cout << s1 << endl;

	s1.append(10, 'x'); // ��ʮ��x
	cout << s1 << endl;

	string s2(" apple ");
	s1.append(s2); // ��s2�ӵ�s1����
	cout << s1 << endl;

	s1.append(++s2.begin(), --s2.end()); // ��s2++���һλ��ʼ����s2--���һλ�������ӵ�s1����
	cout << s1 << endl;


	string s3("hello world");
	s3 += " ";
	s3 += "apple";
	cout << s3 << endl;
}

void test_string8()
{
	string s1("hello world");
	cout << s1 << endl;

	s1.assign("xxxx"); // ����
	cout << s1 << endl;

	s1.insert(0, "yyyy"); //pos=0���������ݣ�Ч�ʵ�
	cout << s1 << endl;

	s1.erase(5, 3); // �ӵ����λ�ÿ�ʼɾ�������ַ�,Ч�ʵ�
	cout << s1 << endl;

	string s2("hello world hello bit");
	//s2.replace(5, 1, "20%"); // ����λ��ʼ��һ���ַ��滻��"20%"
	//cout << s2 << endl;

	cout << "-----------------" << endl;

	size_t pos = s2.find(' ');
	while (pos != string::npos) // string::npos����δ�ҵ�ƥ����,����ʾ�ҵ���ƥ����Ҳ���ǿո�Ȼ��������滻
	{
		s2.replace(pos, 1, "20%");
		pos = s2.find(' ');
	}
	cout << s2 << endl;

	// insert erase replace
	// �����þ����ã���Ϊ������ҪŲ�����ݣ�Ч�ʲ���

	cout << "-----------------" << endl;
	string s3;
	s3.reserve(s2.size());
	for (auto ch : s2)
	{
		if (ch != ' ')
		{
			s3 += ch;
		}
		else
		{
			s3 += "20%";
		}
		
	}
	cout << s3 << endl;
	s2.swap(s3);
	cout << s2 << endl;
}

void test_string9()
{
	string s1("file.cpp");
	// �õ��ļ��ĺ�׺
	size_t pos1 = s1.find('.');

	if (pos1 != string::npos)
	{
		string suffix = s1.substr(pos1); // ȡ�Ӵ�
		// string suffix = s1.substr(pos1, s1.size()-pos1); // ���һ�������Ǳ�ʾ���������
		cout << suffix << endl;
	}
	else
	{
		cout << "û�к�׺" << endl;
	}

	// ��rfind������ȡ
	string s2("file.cpp.tar.zip");
	// �õ��ļ��ĺ�׺
	size_t pos2 = s2.rfind('.'); // find�ķ���ֵ��Ҫ��size_t���洢��û���ҵ��᷵��npos

	if (pos2 != string::npos)
	{
		string suffix = s2.substr(pos2); // ȡ�Ӵ�
		// string suffix = s2.substr(pos1, s2.size()-pos1); // ���һ�������Ǳ�ʾ���������
		cout << suffix << endl;
	}
	else
	{
		cout << "û�к�׺" << endl;
	}

	
}


void test_string10()
{
	string url1("https://blog.csdn.net/m0_63596031?spm=1010.2135.3001.5343");
	string url2("https://github.com/Outlier9");

	string protocol, domain, uri; // Э�飬��������Դ��ַ
	size_t i1 = url1.find(':'); // find�ķ���ֵ��Ҫ��size_t���洢��û���ҵ��᷵��npos

	if (i1 != string::npos)
	{
		protocol = url1.substr(0, i1 - 0); // ȡ�Ӵ���ֱ��i1Ҳ����ð��ǰ��ǰ�պ󿪣�ȡ����ð�ţ�
		cout << protocol << endl;
	}

	size_t i2 = url1.find('/', i1 + 3); // Ҫ������//��������Ϊǰ�պ󿪰������Ե�ָ����ͷ����ĸ
	if (i2 != string::npos)
	{
		domain = url1.substr(i1 + 3, i2 - (i1 + 3)); // ȡ�Ӵ���ֱ��i1Ҳ����ð��ǰ��ǰ�պ󿪣�ȡ����ð�ţ�
		cout << domain << endl;

		uri = url1.substr(i2 + 1); // ʣ��Ķ���uri
		cout << uri << endl;
	}

	string ss1 = "xxx";
	string ss2 = "yyy";
	string ret = ss1 + ss2;
	cout << ret << endl;


}

void test()
{
	string a[100];
	cout << typeid(a[0]).name() << endl;
	cout << typeid(a).name() << endl;
}



//int main()
//{
//	test_string1();
//	test_string2();
//	test_string3();
//	test_string4();
//	test_string5();
//	test_string6();
//	test_string7();
//	test_string8();
//	test_string9();
//	test_string10(); 
//	test();
//
//	return 0;
//}


#include"string.h"


int main()
{
	/*bit::string Example;
	Example.string1();*/


	bit::test_string1();
	bit::test_string2();
	bit::test_string3();
	bit::test_string4();
	bit::test_string5();
	bit::test_string6();
	bit::test_string7();
	bit::test_string8();
	return 0;
}

// ��ʾstrcpy����
//int main() {
//	char str1[20] = "xxxx"; // ��ʽ��ָ�� str1 �Ĵ�С����ʼ��Ϊ "xxxx"
//	const char str2[] = "Hello, World!";
//
//	size_t len = strlen(str1);
//	// �������len����ֱ�Ӹ��ǵ���xxxx��
//	strcpy(str1+len, str2);
//
//	printf("Copied string: %s\n", str1);
//
//	return 0;
//}
