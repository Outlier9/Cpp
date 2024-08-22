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

		// ��ģ��ĳ�Ա���������Ǻ���ģ��
		// ���������乹��
		// ͨ��ָ���ĵ��������� [first, last) ����һ���µ� vector ����
		// ������캯��������ͨ������һ��������Χ�ڵ�Ԫ�أ�������ЩԪ������ʼ���µ� vector
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		// ��ʼ��һ�� vector ����ʹ����� n ��Ԫ�أ�ÿ��Ԫ�ص�ֵ���� val
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


		// ���캯��
		vector()
		{}

		// �������� v2(v1)
		vector(const vector<T>& v)
		{
			// �����ݣ�Ԥ�ȷ����㹻���ڴ�ռ�
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

		// ��ֵ���������
		vector<T> operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		// ��������
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		// ��С
		size_t size() const
		{
			return _finish - _start;
		}

		// ����
		const size_t capacity() const
		{
			return _endofstorage - _start;
		}

		// [] ��������أ�ʹ�ö������������һ��ʹ���±�������������ڲ��洢��Ԫ��
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
				// memcpy��ǳ����
				// memcpy(tmp, _start, size() * sizeof(T));

				// �������,��forֻ��ֵ������ȥ
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
			//��չ vector �Ĵ�С����Ҫȷ�����㹻���ڴ�ռ���������Ԫ�ء�
			//�����ǰ������������֧���µĴ�С����Ҫ�����·����ڴ沢������Ԫ�ظ��Ƶ��·�����ڴ���
			if (n > size())
			{
				if (n > capacity())
				{
					reserve(n);
				}

				// ����
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				// ɾ��
				_finish = _start + n;
			}
		}

		// β��
		void push_back(const T& val)
		{
			//// �����С����������ˣ�˵�����ˣ���Ҫ����
			//if (_finish == _endofstorage)
			//{
			//	// �����е�������С����������
			//	reserve(capacity() == 0 ? 4 : capacity() * 2);
			//}

			//// û������ֱ�Ӳ������ݣ�Ȼ��_finish����һλ
			//*_finish = val;
			//++_finish;

			insert(end(), val);
		}

		// βɾ
		void pop_back()
		{
			/*assert(!empty());
			--_finish;*/

			//��ֵ��lvalue������ʹ�õ�����++����ݼ���--��������
			// �� end() ���ص���һ����ʱ����������ֵ��rvalue��
			//erase(--end()); // ���󣺡�--����Ҫ��ֵ
			erase(end() - 1);
		}

		// �ж��Ƿ�Ϊ��
		bool empty() const
		{
			return _start == _finish;
		}

		// ����
		void insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				// �������Ҫ����pos,����ᷢ��������ʧЧ
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
		// �����ڹ����ʱ�������ֿ���ƥ��
		// �������������ƥ���ٵ���дһ��int�ģ���Ϊֻ���ڴ�����int��ʱ��Żᷢ����ͻ������дһ�����ȼ����ߵ�
		vector<int> v(10, 1);
		print_vector(v);

		vector<int> v2(10u, 1);
		print_vector(v2);

		vector<int> v3(10, 'a');
		print_vector(v3);

	}

	void testvector6()
	{
		// reserve�����ݻ��Ƶ�memcpy��������
		// ������ﴫ����string����
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
		/*std::vector �ײ��ڽ����ڴ���չʱ������ std::string �����POD���ͣ�
		��ʹ��Ԫ�صĿ������캯����ֵ��������ȷ�����������ʹ�� memcpy ���µ�Ǳ�����⡣
		������ģ��ʵ�֣�ֻʹ��ǳ����������ʵ��string���͵�vector�洢*/

	}

	void testvector7()
	{
		// C++11�����ӵĹ��췽ʽ
		auto x = { 1,2,3,4,5,6,7,8,9,10 };
		cout << typeid(x).name() << endl;
		for (auto e : x)
		{
			cout << e << " ";
		}
		cout << endl;

		// <int> y = { 1,2,3,4,5,6,7 };

		// �������Ĺ��죬֧����ʽ����ת��
		string str1 = "11111";  // ����+�������� -> �Ż� ֱ�ӹ���
		const string& str2 = "11111";  // ������ʱ�������õ�����ʱ����
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
		// ������ʧЧ

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		// ����ᷢ������
		v.push_back(8);
		print_vector(v);

		// insert�Ժ�it��ʧЧ�ˣ�����ʹ����
		vector<int>::iterator it = v.begin() + 3;
		v.insert(it, 40);

		print_vector(v);

		// ��������������£����ܼ���ʹ��
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
		/*�����1 3 4 7 erase���������ǰ����������*/

		/*v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(5);
		v.push_back(4);*/
		/*1 2 3 4 5 5 4 ����Խ�����
		Assertion failed : pos < _finish, file D : \C C++\program\C++\STL_vector\STL_vector\vector.h, line 232*/

		/*print_vector(v);*/

		// ɾ��ż��
		/*vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				v.erase(it);
			}
			++it;
		}*/

		// �������ָĽ�����������linux�������ã�������VS����
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				// ������linux��
				// v.erase(it);
				// �Ľ����κλ����¶�����
				it = v.erase(it);
			}
			else {
				++it;
			}
		}

		print_vector(v);

		// VS��std::vector��ʾ-----ֱ�ӱ���
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












