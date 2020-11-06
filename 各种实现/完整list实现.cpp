// list作为一个带头结点的双向循环链表，初始状态时有一个空的节点组成双向循环链表。
// 它的优点是插入、删除等操作时不会使其他迭代器失效（甚至进行操作的那个迭代器也不会失效）
// STL算法，使用定制的迭代器而不能使用原生态的指针
// list实现四种函数构造，resize,push_back,push_front,pop_back,pop_front,insert,erase

#pragma once

namespace bite
{
	// list底层是链表，所以先构建节点
	template <class T>
	struct listNode
	{
		listNode<T>* prev;
		listNode<T>* next;
		T val;

		// 构造函数
		listNode(const T& value = T())
			: prev(nullptr)
			, next(nullptr)
			, val(value)
		{}
	};

	// 因为底层是链表，所以原生态指针失效
	template <class T, class Ref, class Ptr>
	class listiterator
	{
	public:
		typedef listNode<T> Node;
		// 迭代器
		typedef listiterator self;

	public:
		listiterator(Node* node = nullptr)
			:_node(node)
		{}

		// 使其具有指针类似的行为
		Ref operator*()
		{
			return _node->val;
		}

		Ptr operator->()
		{
			// return &(_node->val)
			return &(operator*());
		}


		// 迭代器移动
		// 前置++
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}

		// 后置++
		self operator++(int)
		{
			self temp (*this);
			_node = _node->next;
			return temp;
		}

		// 前置--
		self& operator--()
		{
			_node =  _node->prev;
			return *this;
		}

		// 后置--
		self operator--(int)
		{
			self temp (*this);
			_node = _node->prev;
			return temp;
		}

		// 比较
		bool operator!=(const self& s)const
		{
			return _node != s._node;
		}

		bool operator==(const self& s)const
		{
			return _node == s._node;
		}

		Node* _node;
	};



	template<class T>
	class list
	{
		typedef listNode<T> Node;
		// typedef T* iterator; 不能用原生态指针来进行++操作，因为链表的++ 不一定是下一个节点
		// 链表的下一个节点只能通过next来进行
	public:
		// 下面这种迭代器好操作，可以容易控制const类型的iterator
		typedef listiterator<T, T&, T*> iterator;
		typedef listiterator<T, const T&, const T*> const_iterator;

	public:
		list()
		{
			CreateHead();
		}

		list(int n, const T& value = T())
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
			{
				push_back(value);
			}
		}

		// 区间构造
		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(list<T>& L)
		{
			CreateHead();
			auto it = L.begin();
			while (it != L.end())
			{
				push_back(*it);
				++it;
			}
		}

		list<T>& operator=(const list<T>& L);

		~list()
		{
			// 1.删除有效节点
			// 2.删除头结点
			erase(begin(), end());
			delete head;
			head = nullptr;
		}

		////////////////////////////////////////////////////
		// 迭代器
		iterator begin()
		{
			return iterator(head->next);
		}

		iterator end()
		{
			// iterator ret(head);
			// return ret;
			return iterator(head);
		}

		// const_iterator
		const_iterator cbegin()const
		{
			return (const_iterator(head->next));
		}

		const_iterator cend()const
		{
			// iterator ret(head);
			// return ret;
			return (const_iterator(head));
		}


		////////////////////////////////////////////////////
		// 容量

		// 访问链表算出size
		size_t size()const
		{
			size_t count = 0;
			auto it = cbegin();
			while (it != cend()) ++it, ++count;
			return count;
		}

		// 判空
		bool empty()const
		{
			return head->next == head;
		}

		// 扩容
		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (oldsize > newsize)
			{
				for (size_t i = newsize; i < oldsize; ++i)
					pop_back();
			}
			else
			{
				for (size_t i = oldsize; i < newsize; ++i)
					push_back(data);
			}
		}
		//////////////////////////////////////////////////
		// acess
		int front()
		{
			return head->next->val;
		}

		int front()const
		{
			return head->next->val;
		}

		int back()
		{
			return head->prev->val;
		}

		int back()const
		{
			return head->prev->val;
		}

		///////////////////////////////////////////////
		// 修改
		void push_back(const T& data)
		{
			insert(end(), data);
		}

		void pop_back()
		{
			auto it = end();
			erase(--it);
		}

		void push_front(const T& data)
		{
			insert(begin(), data);
		}

		void pop_front()
		{
			erase(begin());
		}

		// 任意位置的插入（链表的基本操作）
		iterator insert(iterator pos, const T& data)
		{
			Node* newnode = new Node(data);
			newnode->prev = pos._node->prev;
			newnode->next = pos._node;
			newnode->prev->next = newnode;
			pos._node->prev = newnode;
			return iterator(newnode);
		}

		// 任意位置的删除（基操）
		iterator erase(iterator pos)
		{
			// 为了防止迭代器失效，就必须返回下一个节点
			Node* ret = pos._node->next;

			Node* cur = pos._node;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			delete cur;

			return iterator(ret);
		}

		// 区间删除
		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				first = erase(first);
			}

			return end();
		}

		// 清空链表
		void clear()
		{
			erase(begin(), end());
		}

		void swap(list<T>& L)
		{
			std::swap(head, L.head);
		}

	private:
		// 头节点
		void CreateHead()
		{
			head = new Node;
			head->next = head;
			head->prev = head;
		}
	private:
		Node* head;
	};
};


///////////////////////////////////////////////////////////////////

#include "list.h"
#include <iostream>
using namespace std;

#include <vector>

void Testlist()
{
	// 测构造函数
	bite::list<int> L1;
	bite::list<int> L2(10, 4);
	auto it = L2.begin();
	while(it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int> v{ 1, 2, 3, 4, 5 };
	bite::list<int> L3(v.begin(), v.end());
	for (auto e : L3)
	{
		cout << e << " ";
	}
	cout << endl;

	// 拷贝构造
	bite::list<int> L4(L3);
	for (auto e : L4)
	{
		cout << e << " ";
	}
	cout << endl;
}

// Find函数
template <class Iterator, class T>
Iterator Find(Iterator first, Iterator last, const T& data)
{
	while (first != last)
	{
		if (*first == data)
			return first;
		++first;
	}
	return last;
}

// 测试代码
void Testlist1()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	bite::list<int> L(v.begin(), v.end());
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	// resize
	L.resize(10);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.resize(4);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	// push_back
	L.push_back(6);
	cout << L.front() << endl;
	cout << L.back() << endl;

	// pop_back
	L.pop_back();
	cout << L.front() << endl;
	cout << L.back() << endl;

	// push_front
	L.push_front(0);
	cout << L.front() << endl;
	cout << L.back() << endl;

	// pop_front
	L.pop_front();
	cout << L.front() << endl;
	cout << L.back() << endl;

	// insert
	auto it = Find(L.begin(), L.end(), 3);
	if (it != L.end())
	{
		L.insert(it, 10);
		for (auto e : L)
			cout << e << " ";
		cout << endl;
	}

	// erase
	L.erase(it);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	// 清空
	L.erase(L.begin(), L.end());
}

int main()
{
	// Testlist();
	Testlist1();
	return 0;
}
