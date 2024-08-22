#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include"vector.h"

// 遍历
void test_vector1() {

	// 写数据，顺序表尾插
	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);*/

	// 初始化成10个1
	vector<int> v(10, 1);

	// 一般循环写法
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	// 迭代器
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 范围for
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

// 扩容机制
void test_vector2() {
	size_t sz;
	vector<int> v;
	v.reserve(100);
	sz = v.capacity();
	// cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	cout << "使用reserve的变化" << endl;
	cout << v.capacity() << endl;
	cout << v.size() << endl;
	v.reserve(10);
	// 都不变
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	cout << "使用resize的变化" << endl;
	cout << v.capacity() << endl;
	cout << v.size() << endl;
	v.resize(10);
	// size变了但是也不会缩容
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	// 如果想要缩容,该函数会将其容量缩小到等于当前大小的值
	v.shrink_to_fit();
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	// a 的大小调整为 10，并将新增加的元素初始化为 0
	vector<int> a;
	a.resize(10, 0);
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;

}


void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	auto pos = find(v.begin(), v.end(), 3);

	if (pos != v.end())
	{
		v.insert(pos,30);
	}

	// 头插
	v.insert(v.begin(), 0);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;


	//也支持插入其他迭代类型，这里abcd会发生隐式类型转换，插入97 98 99 100
	string s("abcd");
	v.insert(v.begin(), s.begin(), s.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_vector4()
{
	//对象数组
	vector<string> v;
	string s1("苹果");
	v.push_back(s1);
	v.push_back(string("香蕉"));
	v.push_back("香蕉");

	// 嵌套
	vector<vector<int>>  vv;

}


void test_vector5()
{

}

void test_vector6()
{

}

int main()
{
	//test_vector1();
	//test_vector2();
	//test_vector3();

	// bit::testvector1();
	// bit::testvector2();
	// bit::testvector3();
	// bit::testvector4();
	// bit::testvector5();
	// bit::testvector6();
	// bit::testvector7();
	// bit::testvector8();
	bit::testvector9();

	return 0;
}