#pragma once
#include<assert.h>

namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		// 类模板的成员函数可以是函数模板
		// 迭代器区间构造
		// 通过指定的迭代器区间 [first, last) 创建一个新的 vector 对象。
		// 这个构造函数允许你通过从另一个容器或范围内的元素，复制这些元素来初始化新的 vector
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		// 初始化一个 vector 对象，使其包含 n 个元素，每个元素的值都是 val
		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}


		// 构造函数
		vector()
		{}

		// 拷贝构造 v2(v1)
		vector(const vector<T>& v)
		{
			// 先扩容，预先分配足够的内存空间
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		void swap(vector<T> v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		// 赋值运算符重载
		vector<T> operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		// 析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		// 大小
		size_t size() const
		{
			return _finish - _start;
		}

		// 容量
		const size_t capacity() const
		{
			return _endofstorage - _start;
		}

		// [] 运算符重载，使得对象可以像数组一样使用下标操作来访问其内部存储的元素
		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t old_size = size();
				// memcpy是浅拷贝
				// memcpy(tmp, _start, size() * sizeof(T));

				// 解决方法,用for只把值拷贝过去
				for (size_t i = 0; i < old_size; i++)
				{
					tmp[i] = _start[i];
				}

				delete[] _start;

				_start = tmp;
				_finish = tmp + old_size;
				_endofstorage = tmp + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			//扩展 vector 的大小，需要确保有足够的内存空间来容纳新元素。
			//如果当前的容量不足以支持新的大小，需要先重新分配内存并将现有元素复制到新分配的内存中
			if (n > size())
			{
				if (n > capacity())
				{
					reserve(n);
				}

				// 插入
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				// 删除
				_finish = _start + n;
			}
		}

		// 尾插
		void push_back(const T& val)
		{
			//// 如果大小和容量相等了，说明满了，需要扩容
			//if (_finish == _endofstorage)
			//{
			//	// 在现有的容量大小上扩容两倍
			//	reserve(capacity() == 0 ? 4 : capacity() * 2);
			//}

			//// 没有满就直接插入数据，然后_finish后移一位
			//*_finish = val;
			//++_finish;

			insert(end(), val);
		}

		// 尾删
		void pop_back()
		{
			/*assert(!empty());
			--_finish;*/

			//左值（lvalue）才能使用递增（++）或递减（--）操作符
			// 而 end() 返回的是一个临时对象，属于右值（rvalue）
			//erase(--end()); // 错误：“--”需要左值
			erase(end() - 1);
		}

		// 判断是否为空
		bool empty() const
		{
			return _start == _finish;
		}

		// 插入
		void insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				// 如果扩容要更新pos,否则会发生迭代器失效
				pos = _start + len;
			}

			iterator it = _finish - 1;
			while (it >= pos)
			{
				*(it + 1) = *it;
				--it;
			}
			*pos = val;
			++_finish;

		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator it = pos;
			while (it < _finish - 1)
			{
				*it = * (it + 1);
				++it;
			}
			--_finish;

			return pos;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};


	void print_vector(const vector<int>& v)
	{
		//for (size_t i = 0; i < v.size(); i++)
		//{
		//	cout << v[i] << " ";
		//}
		//cout << endl;

		////vector<int>::const_iterator it = v.begin();
		//auto it = v.begin();
		//while (it != v.end())
		//{
		//	cout << *it << " ";
		//	++it;
		//}
		//cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	void testvector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		print_vector(v);

		v.pop_back();
		v.pop_back();
		print_vector(v);

		v.insert(v.begin(), 2);
		print_vector(v);
		v.insert(v.begin(), 2);
		print_vector(v);
		v.insert(v.begin(), 2);
		print_vector(v);
		v.insert(v.begin(), 2);
		print_vector(v);
		v.insert(v.begin(), 2);
		print_vector(v);
		v.insert(v.begin(), 2);
		print_vector(v);
		v.insert(v.begin(), 2);
		print_vector(v);
		v.erase(v.begin());
		print_vector(v);
	}

	void testvector2()
	{
		int i = 1;
		int j = int();
		int k = int(2);

		vector<int> v;
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		print_vector(v);

		v.reserve(10);
		print_vector(v.capacity());

		v.resize(9);
		print_vector(v);
		v.resize(3);
		print_vector(v);

	}

	void testvector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		print_vector(v);

		vector<int> v2;
		v2.push_back(40);
		v2.push_back(30);
		v2.push_back(20);
		v2.push_back(10);
		print_vector(v2);

		v = v2;
		print_vector(v);
	}

	void testvector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		print_vector(v);

		vector<int> v2(v.begin()+1,v.end()-1);
		print_vector(v2);

		string str("abcd");
		vector<int> v3(str.begin() + 1, str.end() - 1);
		print_vector(v3);
	}

	void testvector5()
	{
		// 这种在构造的时候有两种可以匹配
		// 解决方法是类型匹配再单独写一种int的，因为只有在传参是int的时候才会发生冲突，所以写一种优先级更高的
		vector<int> v(10, 1);
		print_vector(v);

		vector<int> v2(10u, 1);
		print_vector(v2);

		vector<int> v3(10, 'a');
		print_vector(v3);

	}

	void testvector6()
	{
		// reserve中扩容机制的memcpy拷贝问题
		// 如果这里传的是string类型
		vector<string> v;
		v.push_back("1111");
		v.push_back("2222");
		v.push_back("3333");
		v.push_back("4444");
		v.push_back("5555");
		v.push_back("6666");

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		/*std::vector 底层在进行内存扩展时，对于 std::string 这类非POD类型，
		会使用元素的拷贝构造函数或赋值操作符来确保深拷贝，避免使用 memcpy 导致的潜在问题。
		这里是模拟实现，只使用浅拷贝，不能实现string类型的vector存储*/

	}

	void testvector7()
	{
		// C++11中增加的构造方式
		auto x = { 1,2,3,4,5,6,7,8,9,10 };
		cout << typeid(x).name() << endl;
		for (auto e : x)
		{
			cout << e << " ";
		}
		cout << endl;

		// <int> y = { 1,2,3,4,5,6,7 };

		// 单参数的构造，支持隐式类型转换
		string str1 = "11111";  // 构造+拷贝构造 -> 优化 直接构造
		const string& str2 = "11111";  // 构造临时对象，引用的是临时对象
		vector<string> v;
		v.push_back(str1);
		v.push_back(string("22222"));
		v.push_back("33333");

		std::vector<int> v2 = { 1,2,3,4,5,6,7,8 };
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void testvector8()
	{
		// 迭代器失效

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		// 这里会发生扩容
		v.push_back(8);
		print_vector(v);

		// insert以后，it就失效了，不能使用了
		vector<int>::iterator it = v.begin() + 3;
		v.insert(it, 40);

		print_vector(v);

		// 这里给迭代器更新，才能继续使用
		it = v.begin() + 3;
		cout << *it << endl;
	}

	void testvector9()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		/*1 3 5 7*/

		/*v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(6);
		v.push_back(7);*/
		/*结果：1 3 4 7 erase后会跳过当前补上来的数*/

		/*v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(5);
		v.push_back(4);*/
		/*1 2 3 4 5 5 4 发生越界访问
		Assertion failed : pos < _finish, file D : \C C++\program\C++\STL_vector\STL_vector\vector.h, line 232*/

		/*print_vector(v);*/

		// 删除偶数
		/*vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				v.erase(it);
			}
			++it;
		}*/

		// 下面这种改进方法可以在linux环境下用，但是在VS不行
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				// 仅限在linux下
				// v.erase(it);
				// 改进，任何环节下都可以
				it = v.erase(it);
			}
			else {
				++it;
			}
		}

		print_vector(v);

		// VS的std::vector演示-----直接报错
		/*std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		v1.push_back(7);
		std::vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			if (*it % 2 == 0)
			{
				v1.erase(it);
			}
			else {
				++it;
			}
		}
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;*/
		

	}

}












