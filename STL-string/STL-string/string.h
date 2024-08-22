#pragma once
#include<assert.h>
#include<iostream>
// 将类放置在命名空间中的主要好处之一是避免全局命名冲突
using namespace std;
namespace bit
{
	class string
	{
	public:
		// 遍历方法——迭代器实现（test_string2）
		// 针对普通对象的迭代器
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		// 针对const对象的const迭代器
		typedef char* const_iterator;

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		// 构造函数
		/*
		// 这种情况是不需要传递任何参数
		string()
			:_str(new char[1])
			,_size(0)
			,_capacity(0)
		{
			_str[0] = '\0';
		}
		
		// const char* str参数没有默认值
		// 因此调用构造函数时必须传递一个C风格字符串作为参数
		// 不能选择不传递参数
		string(const char* str)
			:_size(strlen(str))
			, _str(new char[strlen(str) + 1])
			, _capacity(strlen(str))
		{
			strcpy(_str, str);
		}*/

		
		
		// 全缺省，默认参数const char* str = ""
		// 这意味着在调用构造函数时可以选择不传递任何参数
		// 此时会默认使用空字符串进行构造
		// 这种相对灵活，结合了上述两种
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// 析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		// 拷贝构造函数的传统写法
		/*string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}*/
		// 拷贝构造函数的现代写法
		string(const string& s)
		{
			string tmp(s._str);
			swap(tmp);
		}

		// 赋值（test_string5）
		/*string& operator=(const string& s)
		{
			char* tmp = new char[s._capacity + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;

			return *this;
		}*/

		// 赋值重载的现代写法，在传参时候先进行拷贝构造
		string& operator=(string tmp)
		{
			swap(tmp);

			return *this;
		}
		// 现代写法，上边的更简洁
		/*string& operator=(const string& s)
		{
			string ss(s);
			swap(ss);
			return *this; 
		}*/


		const char* c_str() const
		{
			return _str;
		}
		// 返回size大小（装了多少个）
		size_t size() const
		{
			return _size;
		}
		// 返回容量大小（总共可容纳多少个）
		size_t capacity() const
		{
			return _capacity;
		}
		// 访问字符串中特定位置的字符，重载运算符“[ ]”
		// 返回一个对字符串中特定位置的字符的非常量引用
		// 可以用于修改所引用的对象的值
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		// 返回一个对字符串中特定位置的字符的常量引用
		// 不能用于修改所引用的对象的值
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		/*
		* 对于operator这里开头和结尾都需要加上const，
		*而迭代器begin和end函数不需要在开头加const的解释
		* 
		* 对于 begin() 函数，它是一个 const 成员函数，
		*因此只需要在末尾加上 const，
		*表示它是一个 const 成员函数。
		* 
		*而对于 operator[] 函数，它既是一个 const 成员函数，
		*又返回一个对数据成员的 const 引用，
		*因此需要在两个地方加上 const。
		*/

		// 实现puchback之前的扩容
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				// 手动扩容
				char* tmp = new char[n+1]; // 多加一个空间存‘/0’
				strcpy(tmp, _str);
				delete _str;
				_str = tmp;

				_capacity = n;
			}
		}

		//尾部插入操作的实现（test_string3）
		void push_back(char ch)
		{
			// 扩容
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}

			// 实现插入操作
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			// 扩容
			if (_size + len > _capacity)
			{
				reserve(_size + len + 1);
			}
			
			// 实现插入操作，用strcpy直接复制
			strcpy(_str + _size, str);
			// 改变后的字符串大小
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		//任意位置插入操作的实现（test_string4）
		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			// 扩容
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}

			// 第一种写法
			//int end = _size;// end在这指向‘\0’,int类型，因为要考虑pos等于0的情况
			//while (end >= (int)pos) // 如果end是int而pos是size_t，会发生整型提升，int实际还是被以这当成了size_t
			//	                    //所以强转pos为int，然后处理pos为0的时候的情况
			//{
			//	_str[end + 1] = _str[end];
			//	--end;
			//}
			//_str[pos] = ch;
			//++_size;

			// 第二种写法
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;

		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			// 扩容
			if (_size + len > _capacity)
			{
				reserve(_size + len + 1);
			}

			size_t end = _size + len;
			// while(end > pos) 也可以，但是运行到替换了pos+len以后，
			// 前边的没有必要再移动到后边，所以可以停止了，直接覆盖掉就可以
			while (end >= pos + len) 
			{
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, str, len);
			// 复制完指定数量的字符后就会停止，不管源字符串是否已经结束
			// 如果源字符串长度小于 n，则 strncpy 会用空字符 '\0' 来填充目标字符串的剩余部分
			_size +=len;

		}

		//删除操作的实现（test_string4）
		void erase(size_t pos, size_t len = npos)
		{
			// if (len == npos || len + pos >= _size)的情况
			// 如果变量 pos 的值超出了字符串 _str 的长度范围，或者 _size 超出了可分配内存的范围
			// 就会发生溢出，这可能导致在内存中覆盖不属于字符串 _str 的部分，或者导致程序崩溃
			if (len == npos || len >= _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else 
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		// 把n以后的位置都设置为特定字符（test_string4）
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				// 扩容
				reserve(n);

				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}

		}
		// 交换（test_string6）
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		// 查找字符并返回下标（test_string6）
		size_t find(char ch, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		// 查找子串并返回首字母下标（test_string6）
		size_t find(const char* sub, size_t pos = 0) const
		{
			assert(pos < _size);
			const char* p = strstr(_str + pos, sub); // strstr函数会自动完成匹配判断
			if (p)
			{
				return p - _str; // 两个指针之间的偏移量，即找到的子字符串在原始字符串中的相对位置
			}
			else
			{
				return npos;
			}
		}

		// 在字符串中取子串 (test_string7) 
		// 从第pos个位置起（不包含pos）往后取len个
		string substr(size_t pos, size_t len = npos)
		{
			string sub;
			if (len > _size - pos)
			{
				for (size_t i = pos; i < _size; i++)
				{
					sub += _str[i];
				}
			}
			else
			{
				for (size_t i = pos; i < pos + len; i++)
				{
					sub += _str[i];
				}
			}

			return sub;
		}

		bool operator==(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

	private:
		char* _str = nullptr;
		size_t _size;
		size_t _capacity;
	public:
		static const int npos;
	};

	const int string::npos = -1;

	// 避免使用低效的浅拷贝交换，如果使用则会运行，内部机制改为深拷贝的swap，全局声明
	void swap(string& x, string& y)
	{
		x.swap(y);
	}

	// 全局的各种运算符重载，也可以不是全局，因为会隐式类型转换
	bool operator==(const string& s1, const string& s2)
	{
		int ret = strcmp(s1.c_str(), s2.c_str());
		return ret == 0;
	}

	bool operator<(const string& s1, const string& s2)
	{
		int ret = strcmp(s1.c_str(), s2.c_str());
		return ret < 0;
	}

	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}

	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}
	// 必须全局如果将运算符重载定义为成员函数，它只能作用于当前类的对象
	// 而无法应用于类对象与标准库类型之间的操作。
	ostream& operator<<(ostream& out, const string s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch;
		// in >> ch;
		// 如果使用in来读取，不能读取空格和回车
		// 即使在终端输入了空格也识别不到，所以也跳不出下边的while循环
		// 所以需要用get来获取
		/*ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;*/

		// 如果字符串短，直接扩容，会造成空间的浪费
		// 下边这种方法，重复利用一段空间，实现字符串的读取
		ch = in.get();
		char buff[128];
		size_t i = 0;
		// 节省空间
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}


	istream& getline(istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		char buff[128];
		size_t i = 0;
		// 节省空间
		while (ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}


	// 遍历
	void test_string1()
	{
		string s1("hello world");
		string s2;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i]++;
		}
		cout << endl;
		// s1[100]; // 测试越界assert
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		const string s3("xxxx");
		for (size_t i = 0; i < s3.size(); i++)
		{
			cout << s3[i] << " "; // Error：const无法调用非const，权限的放大
			// 解决方法：重载成员函数const char& operator[](size_t pos) const
		}
		cout << endl;
	}

	// 使用迭代器的遍历
	void test_string2()
	{
		// 普通迭代器
		string s3("hello world");
		// 迭代器
		string::iterator it3 = s3.begin();
		while (it3 != s3.end())
		{
			cout << *it3 << " ";
			it3++;
		}
		cout << endl;
		// 范围for
		for (auto ch : s3)
		{
			cout << ch << " ";

		}
		cout << endl;

		// const迭代器
		const string s4("hello cpp");
		// 迭代器
		string::const_iterator it4 = s4.begin();
		while (it4 != s4.end())
		{
			cout << *it4 << " ";
			it4++;
		}
		cout << endl;
		// 范围for
		for (auto ch : s4)
		{
			cout << ch << " ";
		}
		cout << endl;
		
	}

	// push_back
	void test_string3()
	{
		string s3("hello string3");
		s3.push_back('1');
		s3.push_back('2');

		cout << s3.c_str() << endl;

		s3 += 'x';
		cout << s3.c_str() << endl;
		s3 += "YYYY";
		cout << s3.c_str() << endl;
		s3.append("WWW");
		cout << s3.c_str() << endl;

	}

	// insert 和 erase
	void test_string4()
	{
		string s1("hello string4");
		s1.insert(6,'x');
		cout << s1.c_str() << endl;

		string s2("hello string4");
		s2.insert(6, "xxxx");
		cout << s2.c_str() << endl;

		string s3("hello string4");
		s3.erase(6, 3);
		cout << s3.c_str() << endl;
		s3.erase(6, 30);
		cout << s3.c_str() << endl;
		s3.erase(3, string::npos);
		cout << s3.c_str() << endl;

		string s4("hello string4");
		s4.resize(5);
		cout << s4.c_str() << endl;
		s4.resize(20,'x');
		cout << s4.c_str() << endl;

	} // 两次调用析构函数？？？

	void test_string5()
	{
		string s1("hello string5");
		cout << s1.c_str() << endl;
		string s2(s1);
		cout << s2.c_str() << endl;
		s1[1] = 'x';
		cout << s1.c_str() << endl;
		string s3 = s1;
		cout << s3.c_str() << endl;

	}


	void test_string6()
	{
		string s1("hello string6");
		string s2("nihao string6");

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		swap(s1, s2);
		s1.swap(s2);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		cout << s1.find('o') << endl; // 传入的是字符串，用‘’
		cout << s1.find("llo") << endl; // 传入的是字符串，用“”
	}

	void test_string7()
	{
		string s1("hello string7");
		string s2 = s1.substr(1, 3);

		cout << s2.c_str() << endl;
		//// 比较运算符==重载
		cout << (s1 == s2) << endl;

		cout << s1 << endl;
		string s3, s4;
		cin >> s3 >> s4;
		cout << s3 << endl;
		cout << s4 << endl;

		getline(cin, s3);
		cout << s3 << endl;

		// 测试>>重载的扩容机制
		string s5;
		cin >> s5;
		cout << s5.capacity() << endl;
	}

	void test_string8()
	{
		string s1("hello string7");
		string(s2);

		cout << s1 << endl;
		cout << s2 << endl;

	}

}

