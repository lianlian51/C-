#include <iostream>
using namespace std;

#include <string>

class Person
{
public:
	void SetPerson(const string& name, const string &sex, int age)
	{
		name_ = name;
		sex_ = sex;
		age_ = age;
	}

	void PrintPerson()
	{
		cout << name_ << "-" << sex_ << "-" << age_ << endl;
	}
private:
	string name_;
	string sex_;
	int age_;
};

class Student : public Person
{
public:
	void SetStudent(const string& name, const string &sex, int age, int stuID)
	{
		SetPerson(name, sex, age);
		stuID = stuID_;
	}

private:
	int stuID_;
};



#if 0
class Base
{
public:
	void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}
private:
	int b_;
};

class Derived : public Base
{
public:
	// 作用域不同，不能形成重载
	void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}

	void TestFunc(int b)
	{
		cout << "Derived::TestFunc(int)" << endl;
	}
private:
	int d_;
	char b_;
};

int main()
{
	// 同名隐藏
	// 通过子类对象访问自己定义的TestFunc没有问题的
	// 但是子类访问父类的TestFunc是不行的
	// 子类继承基类下来的TestFunc发生同名隐藏

	Derived d;
	d.TestFunc(10);

	// 加上域名访问
	d.Base::TestFunc();
	return 0;
}
#endif

class Base
{
public:
	Base(int b = 10)
		: b_(b)
	{
		cout << "Base::Base(int)" << endl;
	}

	Base(const Base& b)
		: b_(b.b_)
	{}

	Base& operator=(const Base& b)
	{
		if (this != &b)
		{
			b_ = b.b_;
		}
		return *this;
	}


	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
private:
	int b_;
};

// 派生类的拷贝构造函数必须调用基类的拷贝构造完成基类的拷贝初始化
// 派生类的牌operator=必须要调用基类的operator=完成基类的赋值

class Derived : public Base
{
public:
	Derived(int b = 10, int d = 20)
		: Base(b)
		, d_(d)
	{
		cout << "Derived::Derived(int, int)" << endl;
	}

	Derived(const Derived& d)
		: Base(d)
		, d_(d.d_)
	{}

	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			Base::operator=(d);
			d_ = d.d_;
		}
		return *this;
	}

	// 注意：派生类对象析构函数的规则
	// 1.先将自己内部的资源清理干净---调用自己的熊沟函数清理自己的资源
	// 2.然后清理从基类继承下来的资源---编译器完成：编译器在编译代码期间，
	//   给派生类析构函数最后一条有效语句之后添加了调用基类析构函数
	~Derived()
	{
		cout << "Derived::Derived()" << endl;

		// call ~Base();
	}


private:
	int d_;
};

int main()
{
	// 同名隐藏
	// 通过子类对象访问自己定义的TestFunc没有问题的
	// 但是子类访问父类的TestFunc是不行的
	// 子类继承基类下来的TestFunc发生同名隐藏

	Derived d;
	d.TestFunc(10);

	// 加上域名访问
	d.Base::TestFunc();
	return 0;
}
