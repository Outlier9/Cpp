#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include"vector.h"

// ����
void test_vector1() {

	// д���ݣ�˳���β��
	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);*/

	// ��ʼ����10��1
	vector<int> v(10, 1);

	// һ��ѭ��д��
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	// ������
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ��Χfor
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

// ���ݻ���
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
	cout << "ʹ��reserve�ı仯" << endl;
	cout << v.capacity() << endl;
	cout << v.size() << endl;
	v.reserve(10);
	// ������
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	cout << "ʹ��resize�ı仯" << endl;
	cout << v.capacity() << endl;
	cout << v.size() << endl;
	v.resize(10);
	// size���˵���Ҳ��������
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	// �����Ҫ����,�ú����Ὣ��������С�����ڵ�ǰ��С��ֵ
	v.shrink_to_fit();
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	// a �Ĵ�С����Ϊ 10�����������ӵ�Ԫ�س�ʼ��Ϊ 0
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

	// ͷ��
	v.insert(v.begin(), 0);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;


	//Ҳ֧�ֲ��������������ͣ�����abcd�ᷢ����ʽ����ת��������97 98 99 100
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
	//��������
	vector<string> v;
	string s1("ƻ��");
	v.push_back(s1);
	v.push_back(string("�㽶"));
	v.push_back("�㽶");

	// Ƕ��
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