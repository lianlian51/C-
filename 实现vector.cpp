#pragma once
#include <assert.h>
#include <string.h>

namespace bite
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		vector()
			:start(nullptr)
			, finish(nullptr)
			, end_of_storage(nullptr)
		{}

		// 一个开辟了n个空间，值均为data的 string：string(size_t, const string& d)
		vector(int n, const T& data = T())
		{
			start = new T[n];
			for (int i = 0; i < n; i++)
				start[i] = data;
			// 更新finish和end_of_storage的位置
			finish = start + n;
			end_of_storage = finish;
		}

		// 区间构造一个函数 
		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			size_t size = 0;
			// 计算出区间的长度
			auto it = first;
			while (it++ != last) ++size;

			// 将元素拷贝到新创建的空间
			start = new T[size];
			finish = start;
			while (first != last)
			{
				*finish++ = *first++;
			}
			// 更新end_of_storage
			end_of_storage = finish;
		}
		// 拷贝构造函数（和上一个有点像，但是这个是可以直接计算出v的长度）
		vector(const vector<T>& v)
		{
			start = new T[v.size()];
			auto it = v.begin();
			finish = start;

			while (it != v.end())
			{
				*finish++ = *it++;
			}
			end_of_storage = finish;
		}

		// 析构函数
		~vector()
		{
			if (start)
				delete[] start;
			start = finish = end_of_storage = nullptr;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////
		// 迭代器
		iterator begin()
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}

		const_iterator begin()const
		{
			return start;
		}
		const_iterator end()const
		{
			return finish;
		}
		////////////////////////////////////////////////////////////////////////////////////////////////
		// 容量
		size_t size()const
		{
			return finish - start;
		}
		size_t capacity()const
		{
			return end_of_storage - start;
		}
		bool empty()const
		{
			return finsh == start;
		}


		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				// 将容量大小减少到newsize
				finish = start + newsize;
			}
			else
			{
				// 如果大于容量的话就得进行扩容
				if (newsize > capacity())
				{
					reserve(newsize);
				}

				// 将元素放进去
				for (size_t i = oldsize; i < newsize; i++)
				{
					*finish++ = data;
				}
			}
		}

		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = capacity();
			if (newcapacity > oldcapacity)
			{
				// 扩容
				// 1.开辟新空间
				T* temp = new T[newcapacity];
				size_t oldsize = size();
				if (start)
				{
					// 2.拷贝元素
					memcpy(temp, start, oldsize*sizeof(T));
					// 3.释放旧空间
					delete[] start;					
				}
				// 4.使用新空间
				start = temp;
				finish = start + oldsize;  // 这里用之前记录的oldsize，这里的旧空间被释放，所以size（）不能用
				end_of_storage = start + newcapacity;
			}
		}

		/////////////////////////////////////////////////////////////////////////////
		// acess
		T& operator[](size_t index)
		{
			assert(index < size());
			return  start[index];
		}

		const T& operator[](size_t index)const
		{
			assrt(index < size());
			return  start[index];
		}

		T& front()
		{
			return *start;
		}
		const T& front()const
		{
			return *start;
		}

		T& back()
		{
			return *(finish - 1);
		}
		const T& back()const
		{
			return *(finish - 1);
		}

		/////////////////////////////////////////////////////////////////////////////
		// modify
		void push_back(const T& data)
		{
			// 检测是否需要扩容
			if (finish == end_of_storage)
				reserve(2 * capacity() + 3); // 这里+3 是为了防止开始就是0，*2之后还是0

			*finish++ = data;
		}

		void pop_back()
		{
			finish--;
		}

		// 返回新插入元素的位置
		iterator insert(iterator pos, const T& data)
		{
			// 检测pos的合法性
			if (pos < start || pos > end())
				return end();

			if (finish == end_of_storage)
				reserve(2 * capacity() + 3);

			// 搬移元素
			auto cur = finish - 1;
			auto next = finish;

			while (cur >= pos)
			{
				*next-- = *cur--;
 			}
			*next = data;
			// 更新finish
			finish++;
			return pos;
		}

		iterator erase(iterator pos)
		{
			if (pos < start || pos >= finish) // 删除的时候注意一定要带上=，
				                              // 因为finish表示最后一个元素下一个的下标，所以是没有元素的
				                              // 因此删除不了
				return finish;

			auto prev =  pos;
			auto cur = prev + 1; 

			while (cur < finish)
			{
				*prev++ = *cur++;
			}
			--finish;
			return pos;
		}
		
		void clear()
		{
			finish = start;
		}

	private:
		iterator start;   // 空间的起始位置
		iterator finish;  // 最后一个元素的下一个位置
		iterator end_of_storage;  // 空间的末尾
	};
}


////////////////////////////////////////////////////////////////////////////////////
// 测试代码
#include "Vector.h"
#include <iostream>
using namespace std;

// 测试vector的构造函数 拷贝构造函数
void TestVector()
{
	bite::vector<int> v1();
	bite::vector<int> v2(10, 5);
	for (size_t i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;

	bite::vector<int> v3(v2);
	// bite::vector<int>::iterator it = v3.begin();
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	int array[] = { 1, 2, 3, 4, 5, 6 };
	bite::vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));
	for (auto e : v4)
		cout << e << " ";
	cout << endl;
}

// 测试push_back，pop_back
void Testvector1()
{
	// 尾插单个数字
	bite::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << v.size() << endl;

	// 扩容测试
	v.resize(7, 10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(20);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	// 尾删测试
	v.pop_back();
	cout << v.size() << endl;

	// 插入任意位置
	v.insert(v.begin(), 0);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	// 删除任意位置
	v.erase(v.begin());
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}



int main()
{
	// TestVector();
	// Testvector1();
	Test();
	return 0;
}
