#pragma once

#include<iostream>
#include<assert.h>

namespace bit
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		ListNode(const T& x=T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};

	template<class T>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T> Self;

		Node* _node;

		ListIterator(Node* node)
			:_node(node)
		{}

		T* operator->()
		{
			return &_node->_data;
		}

		T& operator*()
		{
			return _node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T> iterator;
		typedef ListIterator<T> const_iterator;

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}

		list()
		{
			empty_init();
		}

		// lt2(lt1)
		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}


		// 需要析构，一般就需要自己写深拷贝
		// 不需要析构，一般就不需要自己写深拷贝，默认浅拷贝就可以

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		// lt1 = lt3
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}


		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void push_back(const T& x)
		{
			/*Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());

		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(val);
			Node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			_size++;

		}


		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;
			_size--;

			return iterator(next);
		}

		size_t size() const
		{
			return _size;
		}

		bool empty()
		{
			return _size == 0;
		}

	private:
		Node* _head;
		size_t _size;
	};

	

	void test_list1()
	{
		bit::list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		for (bit::list<int>::iterator it = lt.begin(); it != lt.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		lt.push_front(10);
		lt.push_front(20);
		lt.push_front(30);

		for (bit::list<int>::iterator it = lt.begin(); it != lt.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		lt.pop_back();
		lt.pop_back();
		lt.pop_back();
		lt.pop_back();


		for (bit::list<int>::iterator it = lt.begin(); it != lt.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		lt.pop_front();
		lt.pop_front();
		lt.pop_front();




		for (bit::list<int>::iterator it = lt.begin(); it != lt.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	struct A
	{
		int _a1;
		int _a2;

		A(int a1 = 0,int a2 = 0)
			:_a1(a1)
			,_a2(a2)
		{}
	};

	void test_list2()
	{
		list<A> lt;
		A aa1(1, 1);
		A aa2 = { 1,1 };

		lt.push_back(aa1);
		lt.push_back(aa1);
		lt.push_back(A(2,2));
		lt.push_back({ 3,3 });
		lt.push_back({ 4,4 });

		A* ptr = &aa1;
		(*ptr)._a1;
		ptr->_a1;

		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it += 10; 
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;
			cout << it->_a1 << ":" << it->_a2 << endl;
			//cout << it.operator->()->_a1 << ":" << it.operator->()->_a2 << endl;

			++it;
		}
		cout << endl;

	}

	void PrintList(const list<int>& clt)
	{
		list<int>::iterator it = clt.begin();
		while (it != clt.end())
		{
			//*it += 10;

			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		PrintList(lt);

		list<int> lt1(lt);
		PrintList(lt1);
	}

}