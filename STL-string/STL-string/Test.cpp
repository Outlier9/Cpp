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

//typedef int STDataType;//用typedef只能解决一种类型
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
//	Stack<int> s1;  // 用模板，同一个类模板可以实例化出两个类型
//	Stack<double> s1;
//
//
//}

///////////////////////////////////////////////////////////////////
// 内存管理部分补充
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
	string s0; //什么也没有
	string s1("hello world"); // 给字符串"hello world"
	string s2(s1); // 拷贝构造，把s1给s2
	string s3(s1, 5, 3); // 拷贝构造，从第五个起（也就是第六个开始）取三位，拷贝构造给s3
	string s4(s1, 5, 10);  // 拷贝构造，从第五个起（也就是第六个开始）取十位，拷贝构造给s4，没有十位给剩下的
	string s5(s1, 5); // 拷贝构造，从第五个起（也就是第六个开始）拷贝构造给s5
	string s6(10, '#'); // 十个#构成一个字符串

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
	// 遍历字符串
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
		// cout << s1.operator[](i) << endl;
	}
	cout << endl;
	// 每个字符都加1
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

	const string s2("hello world");// 不能修改，只读
	// s2[0]++; // 错误

	string s3("hello world !!!!!!!");
	s3[0]++;

	cout << s3.size() << endl;
	cout << s3.capacity() << endl;

	// 迭代器
	string::iterator it3 = s1.begin();
	while (it3 != s1.end())
	{
		cout << *it3 << " ";
		it3++;
	}
	cout << endl;

	// 反向迭代器
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
		// *it6 += 3; // 错误，const迭代器只读
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

	// 扩容机制
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

	// 输出当前s1容量和存储占用的大小
	cout << "输出当前s1,s1容量和存储占用的大小" << endl;
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;
	// 清除数据，没有清除容量，查看s1容量和存储占用的大小
	cout << "清除数据，没有清除容量，查看s1,s1容量和存储占用的大小" << endl;
	s1.clear();
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;
	// 缩容，默认缩到15，再次查看s1容量和存储占用的大小
	cout << "缩容，默认缩到15，再次查看s1容量和存储占用的大小" << endl;
	s1.shrink_to_fit(); 
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;

	// reserve // 保留---> 扩容，提前开出多少个容量,但不一定和给出的数一样（只会更大），在g++上是开多少给多少
	// reveser // 翻转，反转
	cout << "输出当前s1,s1容量和存储占用的大小" << endl;
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

	s1.reserve(50); // 其实只有比现在的容量大才会生效，不能缩容
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	cout << "-----------------" << endl;

	// resize() 假设size为17
	//       10    删除       <size
	//       20    插入       size < n < capacity 其余的默认是‘\0’,也可以指定，在括号内给参数就可以
	//       40    扩容+插入  capacity < n
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

	// s1[15]; // 越界超出报错异常
	// s1.at(15);
}


void test_string7()
{
	string s1("hello world");

	s1.push_back('!'); // 只能加字符
	cout << s1 << endl;

	s1.append("hello append!"); // 加字符串
	cout << s1 << endl;

	s1.append(10, 'x'); // 加十个x
	cout << s1 << endl;

	string s2(" apple ");
	s1.append(s2); // 把s2加到s1后面
	cout << s1 << endl;

	s1.append(++s2.begin(), --s2.end()); // 从s2++后的一位开始，到s2--后的一位结束，加到s1后面
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

	s1.assign("xxxx"); // 覆盖
	cout << s1 << endl;

	s1.insert(0, "yyyy"); //pos=0处插入内容，效率低
	cout << s1 << endl;

	s1.erase(5, 3); // 从第五个位置开始删除三个字符,效率低
	cout << s1 << endl;

	string s2("hello world hello bit");
	//s2.replace(5, 1, "20%"); // 第五位开始的一个字符替换成"20%"
	//cout << s2 << endl;

	cout << "-----------------" << endl;

	size_t pos = s2.find(' ');
	while (pos != string::npos) // string::npos表明未找到匹配项,这句表示找到了匹配项也就是空格，然后进行了替换
	{
		s2.replace(pos, 1, "20%");
		pos = s2.find(' ');
	}
	cout << s2 << endl;

	// insert erase replace
	// 能少用就少用，因为基本都要挪动数据，效率不高

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
	// 拿到文件的后缀
	size_t pos1 = s1.find('.');

	if (pos1 != string::npos)
	{
		string suffix = s1.substr(pos1); // 取子串
		// string suffix = s1.substr(pos1, s1.size()-pos1); // 最后一个参数是表示到哪里结束
		cout << suffix << endl;
	}
	else
	{
		cout << "没有后缀" << endl;
	}

	// 用rfind，倒着取
	string s2("file.cpp.tar.zip");
	// 拿到文件的后缀
	size_t pos2 = s2.rfind('.'); // find的返回值需要用size_t来存储，没有找到会返回npos

	if (pos2 != string::npos)
	{
		string suffix = s2.substr(pos2); // 取子串
		// string suffix = s2.substr(pos1, s2.size()-pos1); // 最后一个参数是表示到哪里结束
		cout << suffix << endl;
	}
	else
	{
		cout << "没有后缀" << endl;
	}

	
}


void test_string10()
{
	string url1("https://blog.csdn.net/m0_63596031?spm=1010.2135.3001.5343");
	string url2("https://github.com/Outlier9");

	string protocol, domain, uri; // 协议，域名，资源地址
	size_t i1 = url1.find(':'); // find的返回值需要用size_t来存储，没有找到会返回npos

	if (i1 != string::npos)
	{
		protocol = url1.substr(0, i1 - 0); // 取子串，直到i1也就是冒号前（前闭后开，取不到冒号）
		cout << protocol << endl;
	}

	size_t i2 = url1.find('/', i1 + 3); // 要跳过“//”，又因为前闭后开爱，所以得指到开头的字母
	if (i2 != string::npos)
	{
		domain = url1.substr(i1 + 3, i2 - (i1 + 3)); // 取子串，直到i1也就是冒号前（前闭后开，取不到冒号）
		cout << domain << endl;

		uri = url1.substr(i2 + 1); // 剩余的都是uri
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

// 演示strcpy函数
//int main() {
//	char str1[20] = "xxxx"; // 显式地指定 str1 的大小并初始化为 "xxxx"
//	const char str2[] = "Hello, World!";
//
//	size_t len = strlen(str1);
//	// 如果不加len，将直接覆盖掉“xxxx”
//	strcpy(str1+len, str2);
//
//	printf("Copied string: %s\n", str1);
//
//	return 0;
//}
