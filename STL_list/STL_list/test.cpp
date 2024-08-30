#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<list>
#include"list.h"

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	/*list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;*/

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// 翻转
	lt.reverse();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// 排序，默认升序
	lt.sort();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// 去重
	lt.push_back(5);
	lt.push_back(5);
	lt.unique();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// 转移
	lt.splice(lt.end(),lt, lt.begin());
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int> ltlt;
	ltlt.push_back(10);
	ltlt.push_back(20);
	ltlt.push_back(30);
	ltlt.push_back(40);
	ltlt.push_back(50);

	lt.splice(lt.begin(), ltlt);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}







































int main()
{
	//test_list1();
	/*bit::test_list1();
	bit::test_list2();*/
	bit::test_list3();

	return 0;
}