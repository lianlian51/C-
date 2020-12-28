// 将包含有纯虚函数的类---称为抽象类
// 抽象类不能实例化对象
// 抽象类是一定要被继承的，而且在其后序的子类中要对纯虚函数进行重写
// 如果子类中没有重写抽象类那个纯虚函数，则子类也是抽象类

#include <iostream>
using namespace std;
#include <string>

#if 0
class Work
{
public:
	void toEmployee()
	{
		cout << "工人" << endl;
	}

	void toProgrammer()
	{
		cout << "经理" << endl;
	}
};

class Person
{
public:
	// Employee信息不全面,所以工作的方法没有办法实现
	// 纯虚函数
	virtual void toWork(Work& w) = 0;

protected:
	string name_;
	int age_;
};

class Emolyee : public Person
{
public:
	virtual void toWork(Work& w)
	{
		w.toEmployee();
	}
};

class Programmer :public Person
{
public:
	virtual void toWork(Work& w)
	{
		w.toProgrammer();
	}
};

#include <windows.h>

void TestWork(int n)
{
	Work w;
	Person* p = nullptr;
	for (int i = 0; i < n; i++)
	{
		if (rand() % 2)
		{
			p = new Emolyee();
		}
		else
		{
			p = new Programmer();
		}
		p->toWork(w);
		delete p;
		Sleep(1000);
	}
}

int main()
{
	TestWork(10);
	return 0;
}

#endif

class B
{
public:
	B(int b = 10)
		: b_(b)
	{}

	void Test0()
	{
		cout << "B::Test0()" << endl;
	}

	virtual void Test1()
	{
		cout << "B::Test1()" << endl;
	}

	virtual void Test2()
	{
		cout << "B::Test2()" << endl;
	}

	int b_;
};

class D:public B
{
public:
	virtual void Test1()
	{
		cout << "D::Test1()" << endl;
	}

	virtual void Test2()
	{
		cout << "D::Test2()" << endl;
	}

	virtual void Test3()
	{
		cout << "D::Test3()" << endl;
	}

	int d_;
};

typedef void(*PVFT)();

void PrintPvft(B &b, string info)
{
	cout << info << endl;

	PVFT* pvft = (PVFT*)(*(int*)&b);

	while(*pvft)
	{
		(*pvft)();
		pvft++;
	}
	cout << endl;
}

int main()
{
	B b;
	PrintPvft(b, "基类虚表：");
	D d;
	PrintPvft(d, "派生类虚表：");
	return 0;
}