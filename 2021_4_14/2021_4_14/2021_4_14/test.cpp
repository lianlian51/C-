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




void TestAuto()
{
	auto_ptr<int> ap(new int);
	auto_ptr<int> ap2(ap);

	if (ap.get() == nullptr){
		cout << "C++11中的auto_ptr使用的是资源转移实现的" << endl;
	}
}

int main()
{
	TestAuto();
	return 0;
}