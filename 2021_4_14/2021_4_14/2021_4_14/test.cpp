#include <iostream>
using namespace std;
#include <memory>

#if 0
template<class T>
class SmartPtr
{
public:
	// 构造函数
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	// operator*
	T& operator*()
	{
		return *_ptr;
	}

	// operator->
	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};
#endif



#if 0
void TestAuto()
{
	auto_ptr<int> ap(new int);
	auto_ptr<int> ap2(ap);

	if (ap.get() == nullptr){
		cout << "C++11中的auto_ptr使用的是资源转移实现的" << endl;
	}
}

namespace test
{
	template <class T>
	class auto_ptr
	{
	public:
		auto_ptr(int* ptr)
			: _ptr(ptr)
		{}

		auto_ptr<T>(auto_ptr<T>& ap)
			: _ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete _ptr;

				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		// 具有指针类似的行为
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}
	private:
		int *_ptr;
	};
}
#endif


#if 0
namespace test
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(auto_ptr<T>& ap)
			: _ptr(ap._ptr)
			, _owner(false)
		{
			if (_ptr)
				_owner = true;
		}

		auto_ptr<T>(auto_ptr<T>& ap)
			: _ptr(ap._ptr)
			, _owner(ap._owner)
		{
			ap._owner = false;
		}

		auto_ptr<int>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr && ap._ptr)
				{
					delete _ptr;
				}

				_ptr = ap._owner;
				_owner = ap._owner;
				ap._owner = false;
			}

			return *this;
		}

		~auto_ptr()
		{
			if (_ptr && _owner)
			{
				delete _ptr;
				_ptr = nullptr;
				_owner = false;
			}
		}

		// 具有指针类似的行为
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}
		
	private:
		int* _ptr;
		mutable bool _owner;
	};
}
#endif

#if 0
#include <stdio.h>
#include <fcntl.h>
#pragma warning(disable:4996)
// 定制删除器
template<class T>
class Delete
{
public:
	void operator()(T* & p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

template<class T>
class Free
{
	void operator()(T* &p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};

class FClose
{
public:
	void operator()(FILE* &p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};


namespace test
{
	template<class T, class DF = Delete<T>>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				// delete _ptr; 不能写死，得用资源的类型去释放
				// 利用仿函数
				DF df;
				df(_ptr);
				_ptr = nullptr;
			}
		}

	private:
		unique_ptr(auto_ptr<T>&) = delete;
		unique_ptr<T>& operator=(auto_ptr<T>&) = delete;
	private:
		T* _ptr;
	};
}


void TestUnique()
{
	test::unique_ptr<int> up1(new int);
	test::unique_ptr<int, Free<int>> up2((int*)malloc(sizeof(int)));
	test::unique_ptr<FILE, FClose> up3(fopen("1.txt", "w"));
}
#endif


#if 0
void TestShared()
{
	shared_ptr<int> sp1(new int);
	shared_ptr<int> sp2(sp1);

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	shared_ptr<int> sp3;
	sp3 = sp2;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	cout << sp3.use_count() << endl;
}
#endif 
#if 0
#include <mutex>

namespace test
{
	template<class T>
	class Delete
	{
	public:
		void operator()(T* &p)
		{
			if (_ptr)
			{
				delete p;
				p = nullptr;
			}
		}
	};
	template<class T, class DF = Delete<T>>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(nullptr)
			, _pMutex(nullptr)
		{
			if (ptr)
			{
				_pCount = new int(1);
				_pMutex = new mutex;
			}
		}

		~shared_ptr()
		{
			Release();
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		shared_ptr(shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMutex(sp._pMutex)
		{
			if (_ptr)
				AddRef();
		}

		shared_ptr<T>operator=(shared_ptr<T> & sp)
		{
			if (this != &sp)
			{
				Release();

				_ptr = sp._ptr;
				_pCount = sp._pCount;
				_pMutex = sp._pMutex;
				AddRef();
			}
			return *this;
		}


		// 考虑线程安全问题
		void AddRef()
		{
			_pMutex.lock();
			++(*_pCount);
			_pMutex.unlock();
		}

		int SubRef()
		{
			_pMutex.lock();
			--(*_pCount);
			_pMutex.unlock();
			return *_pCount;
		}

	private:
		Release()
		{
			if (_ptr && 0 == SubRef())
			{
				DF df;
				df(_ptr);

				delete _pCount;
				_pCount = nullptr;

				delete _pMutex;
				_pMutex = nullptr;
			}
		}

	private:
		T* _ptr;
		int* _pCount;
		mutex* _pMutex;
	};
}
#endif

#if 0

struct ListNode{
	ListNode(int x = 0)
	: left(nullptr)
	, right(nullptr)
	, data(x)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode():" << endl;
	}

	shared_ptr<ListNode> left;
	shared_ptr<ListNode> right;
	int data;
};

void TestShared()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));

	cout << sp1.use_count() << endl;
	cout << sp1.use_count() << endl;

	sp1->right = sp2;
	sp2->left = sp1;

	cout << sp1.use_count() << endl;
	cout << sp1.use_count() << endl;
}
#endif


struct ListNode{
	ListNode(int x = 0)
	: data(x)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode():" << endl;
	}

	weak_ptr<ListNode> left;
	weak_ptr<ListNode> right;
	int data;
};

void TestShared()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));

	cout << sp1.use_count() << endl;
	cout << sp1.use_count() << endl;

	sp1->right = sp2;
	sp2->left = sp1;

	cout << sp1.use_count() << endl;
	cout << sp1.use_count() << endl;
}

int main()
{
	// TestAuto();
	// TestShared();
	TestShared();
	return 0;
}