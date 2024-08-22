#pragma once
#include<assert.h>
#include<iostream>
// ��������������ռ��е���Ҫ�ô�֮һ�Ǳ���ȫ��������ͻ
using namespace std;
namespace bit
{
	class string
	{
	public:
		// ������������������ʵ�֣�test_string2��
		// �����ͨ����ĵ�����
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		// ���const�����const������
		typedef char* const_iterator;

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		// ���캯��
		/*
		// ��������ǲ���Ҫ�����κβ���
		string()
			:_str(new char[1])
			,_size(0)
			,_capacity(0)
		{
			_str[0] = '\0';
		}
		
		// const char* str����û��Ĭ��ֵ
		// ��˵��ù��캯��ʱ���봫��һ��C����ַ�����Ϊ����
		// ����ѡ�񲻴��ݲ���
		string(const char* str)
			:_size(strlen(str))
			, _str(new char[strlen(str) + 1])
			, _capacity(strlen(str))
		{
			strcpy(_str, str);
		}*/

		
		
		// ȫȱʡ��Ĭ�ϲ���const char* str = ""
		// ����ζ���ڵ��ù��캯��ʱ����ѡ�񲻴����κβ���
		// ��ʱ��Ĭ��ʹ�ÿ��ַ������й���
		// ����������������������
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// ��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		// �������캯���Ĵ�ͳд��
		/*string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}*/
		// �������캯�����ִ�д��
		string(const string& s)
		{
			string tmp(s._str);
			swap(tmp);
		}

		// ��ֵ��test_string5��
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

		// ��ֵ���ص��ִ�д�����ڴ���ʱ���Ƚ��п�������
		string& operator=(string tmp)
		{
			swap(tmp);

			return *this;
		}
		// �ִ�д�����ϱߵĸ����
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
		// ����size��С��װ�˶��ٸ���
		size_t size() const
		{
			return _size;
		}
		// ����������С���ܹ������ɶ��ٸ���
		size_t capacity() const
		{
			return _capacity;
		}
		// �����ַ������ض�λ�õ��ַ��������������[ ]��
		// ����һ�����ַ������ض�λ�õ��ַ��ķǳ�������
		// ���������޸������õĶ����ֵ
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		// ����һ�����ַ������ض�λ�õ��ַ��ĳ�������
		// ���������޸������õĶ����ֵ
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		/*
		* ����operator���￪ͷ�ͽ�β����Ҫ����const��
		*��������begin��end��������Ҫ�ڿ�ͷ��const�Ľ���
		* 
		* ���� begin() ����������һ�� const ��Ա������
		*���ֻ��Ҫ��ĩβ���� const��
		*��ʾ����һ�� const ��Ա������
		* 
		*������ operator[] ������������һ�� const ��Ա������
		*�ַ���һ�������ݳ�Ա�� const ���ã�
		*�����Ҫ�������ط����� const��
		*/

		// ʵ��puchback֮ǰ������
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				// �ֶ�����
				char* tmp = new char[n+1]; // ���һ���ռ�桮/0��
				strcpy(tmp, _str);
				delete _str;
				_str = tmp;

				_capacity = n;
			}
		}

		//β�����������ʵ�֣�test_string3��
		void push_back(char ch)
		{
			// ����
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}

			// ʵ�ֲ������
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			// ����
			if (_size + len > _capacity)
			{
				reserve(_size + len + 1);
			}
			
			// ʵ�ֲ����������strcpyֱ�Ӹ���
			strcpy(_str + _size, str);
			// �ı����ַ�����С
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

		//����λ�ò��������ʵ�֣�test_string4��
		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			// ����
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}

			// ��һ��д��
			//int end = _size;// end����ָ��\0��,int���ͣ���ΪҪ����pos����0�����
			//while (end >= (int)pos) // ���end��int��pos��size_t���ᷢ������������intʵ�ʻ��Ǳ����⵱����size_t
			//	                    //����ǿתposΪint��Ȼ����posΪ0��ʱ������
			//{
			//	_str[end + 1] = _str[end];
			//	--end;
			//}
			//_str[pos] = ch;
			//++_size;

			// �ڶ���д��
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
			// ����
			if (_size + len > _capacity)
			{
				reserve(_size + len + 1);
			}

			size_t end = _size + len;
			// while(end > pos) Ҳ���ԣ��������е��滻��pos+len�Ժ�
			// ǰ�ߵ�û�б�Ҫ���ƶ�����ߣ����Կ���ֹͣ�ˣ�ֱ�Ӹ��ǵ��Ϳ���
			while (end >= pos + len) 
			{
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, str, len);
			// ������ָ���������ַ���ͻ�ֹͣ������Դ�ַ����Ƿ��Ѿ�����
			// ���Դ�ַ�������С�� n���� strncpy ���ÿ��ַ� '\0' �����Ŀ���ַ�����ʣ�ಿ��
			_size +=len;

		}

		//ɾ��������ʵ�֣�test_string4��
		void erase(size_t pos, size_t len = npos)
		{
			// if (len == npos || len + pos >= _size)�����
			// ������� pos ��ֵ�������ַ��� _str �ĳ��ȷ�Χ������ _size �����˿ɷ����ڴ�ķ�Χ
			// �ͻᷢ�����������ܵ������ڴ��и��ǲ������ַ��� _str �Ĳ��֣����ߵ��³������
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

		// ��n�Ժ��λ�ö�����Ϊ�ض��ַ���test_string4��
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				// ����
				reserve(n);

				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}

		}
		// ������test_string6��
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		// �����ַ��������±꣨test_string6��
		size_t find(char ch, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		// �����Ӵ�����������ĸ�±꣨test_string6��
		size_t find(const char* sub, size_t pos = 0) const
		{
			assert(pos < _size);
			const char* p = strstr(_str + pos, sub); // strstr�������Զ����ƥ���ж�
			if (p)
			{
				return p - _str; // ����ָ��֮���ƫ���������ҵ������ַ�����ԭʼ�ַ����е����λ��
			}
			else
			{
				return npos;
			}
		}

		// ���ַ�����ȡ�Ӵ� (test_string7) 
		// �ӵ�pos��λ���𣨲�����pos������ȡlen��
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

	// ����ʹ�õ�Ч��ǳ�������������ʹ��������У��ڲ����Ƹ�Ϊ�����swap��ȫ������
	void swap(string& x, string& y)
	{
		x.swap(y);
	}

	// ȫ�ֵĸ�����������أ�Ҳ���Բ���ȫ�֣���Ϊ����ʽ����ת��
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
	// ����ȫ���������������ض���Ϊ��Ա��������ֻ�������ڵ�ǰ��Ķ���
	// ���޷�Ӧ������������׼������֮��Ĳ�����
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
		// ���ʹ��in����ȡ�����ܶ�ȡ�ո�ͻس�
		// ��ʹ���ն������˿ո�Ҳʶ�𲻵�������Ҳ�������±ߵ�whileѭ��
		// ������Ҫ��get����ȡ
		/*ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;*/

		// ����ַ����̣�ֱ�����ݣ�����ɿռ���˷�
		// �±����ַ������ظ�����һ�οռ䣬ʵ���ַ����Ķ�ȡ
		ch = in.get();
		char buff[128];
		size_t i = 0;
		// ��ʡ�ռ�
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
		// ��ʡ�ռ�
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


	// ����
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
		// s1[100]; // ����Խ��assert
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		const string s3("xxxx");
		for (size_t i = 0; i < s3.size(); i++)
		{
			cout << s3[i] << " "; // Error��const�޷����÷�const��Ȩ�޵ķŴ�
			// ������������س�Ա����const char& operator[](size_t pos) const
		}
		cout << endl;
	}

	// ʹ�õ������ı���
	void test_string2()
	{
		// ��ͨ������
		string s3("hello world");
		// ������
		string::iterator it3 = s3.begin();
		while (it3 != s3.end())
		{
			cout << *it3 << " ";
			it3++;
		}
		cout << endl;
		// ��Χfor
		for (auto ch : s3)
		{
			cout << ch << " ";

		}
		cout << endl;

		// const������
		const string s4("hello cpp");
		// ������
		string::const_iterator it4 = s4.begin();
		while (it4 != s4.end())
		{
			cout << *it4 << " ";
			it4++;
		}
		cout << endl;
		// ��Χfor
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

	// insert �� erase
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

	} // ���ε�����������������

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

		cout << s1.find('o') << endl; // ��������ַ������á���
		cout << s1.find("llo") << endl; // ��������ַ������á���
	}

	void test_string7()
	{
		string s1("hello string7");
		string s2 = s1.substr(1, 3);

		cout << s2.c_str() << endl;
		//// �Ƚ������==����
		cout << (s1 == s2) << endl;

		cout << s1 << endl;
		string s3, s4;
		cin >> s3 >> s4;
		cout << s3 << endl;
		cout << s4 << endl;

		getline(cin, s3);
		cout << s3 << endl;

		// ����>>���ص����ݻ���
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

