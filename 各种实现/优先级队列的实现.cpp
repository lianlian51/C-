#pragma once

#include <functional>
#include <vector>

namespace  Test
{
	template<class T, class Container = std::vector<T>, class Cmp = std::less<T>>
	class priority_queue
	{
	public:
		// 构造函数
		priority_queue(const Cmp& cmp = Cmp(), const Container& con = Container())
			: _con(con)
			, _cmp(cmp)
		{}

		// 区间建堆
		template<class Iterator>
		priority_queue(Iterator first, Iterator last, const Cmp& cmp = cmp(), const Container& con = Container())
			: _con(con)
			, _cmp(cmp)
		{
			_con.insert(_con.begin(), first, last);

			// 需要调整一下使其满足堆的性质
			int root = (_con.size() - 2) >> 1;
			for (int i = root; i >= 0; --i)
				_AdjustDown(root);
		}

		void push(const T& data)
		{
			// 1.尾插
			_con.push_back(data);
			// 2.调整元素
			_AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			if (empty())
				return;

			// 1.交换堆顶元素和最后一个元素
			swap(_con[0], _con[_con.size() - 1]);
			// 2.尾删
			_con.pop_back();
			// 3.调整堆
			_AdjustDown(0);
		}

		// 获取堆顶元素
		const T& top()
		{
			return _con[0];
		}

		// 获取堆的长度
		size_t size()
		{
			return _con.size();
		}

		// 判空
		bool empty()
		{
			return _con.empty();
		}

	private:
		// 删除用向下
		void _AdjustDown(int parent)
		{
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && _cmp(_con[child] , _con[child + 1]))
					child += 1; // 这里不用交换，直接改一下标记就可

				if (_cmp(_con[parent] , _con[child]))
				{
					swap(_con[child], _con[parent]);
					// 因为这个本来就满足堆的性质，所以如果不交换的话那一定是满足堆的性质
					// 交换之后不一定满足，所以需要再次判断
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					return;
				}
			}
		}

		// 插入时用向上
		void _AdjustUp(int child)
		{
			int parent = (child - 1) >> 1;
			while (parent >= 0)
			{
				if (_cmp(_con[parent] , _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) >> 1;
				}
				else
				{
					return;
				}
			}
		}
	private:
		Container _con;    // 容器
		Cmp _cmp;      // 比较
	};
}
/////////////////////////////////////////////////////////////////////////////

#include "priority_queue.h"
using namespace std;
#include <iostream>

void Testpriority_queue()
{
	Test::priority_queue<int> p;
	p.push(4);
	p.push(3);
	p.push(5);
	p.push(9);
	p.push(7);
	p.push(0);
	p.push(6);
	p.push(1);
	p.push(2);

	cout << p.size() << endl;
	cout << p.top() << endl;

	p.pop();
	p.pop();
	cout << p.size() << endl;
	cout << p.top() << endl;
}


void Testpriority_queue2()
{
	Test::priority_queue<int, vector<int>, greater<int>> p;
	p.push(4);
	p.push(3);
	p.push(5);
	p.push(9);
	p.push(7);
	p.push(0);
	p.push(6);
	p.push(1);
	p.push(2);

	cout << p.size() << endl;
	cout << p.top() << endl;
}


// 自定义类型
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	int Getday()
	{
		return _day;
	}
private:
	int _year;
	int _month;
	int _day;
};
	
	// 第三种：仿函数----->函数对象
class Greater
{
public:
	// ():函数调用运算符
	bool operator()(Date& left, Date& right) // 这里不要写const，不然类型限定符不兼容
	{
		return left.Getday() > right.Getday();
	}
};
	
void Testpriority_queue3()
{
	Date d1(2020, 5, 6);
	Date d2(2020, 5, 7);
	Date d3(2020, 5, 8);

	Test::priority_queue<Date, vector<Date>, Greater> p;  // 小堆
	p.push(d1);
	p.push(d2);
	p.push(d3);
}


int main()
{
	// Testpriority_queue();
	// Testpriority_queue2();
	Testpriority_queue3();
	return 0;
}
