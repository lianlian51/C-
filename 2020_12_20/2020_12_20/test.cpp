#include <iostream>
using namespace std;

#include <string>

#if 0
// 虚拟继承
class Base
{
private:
	int b_;
};

class Derived : virtual public Base
{
private:
	int d_;
};

// 菱形继承二义性----借助虚拟继承
class B
{
public:
	void Test()
	{}

private:
	int b_;
};

class C1 : virtual public B
{
private:
	int c1_;
};

class C2 : virtual public B
{
private:
	int c2_;
};

class D : public C1, public C2
{
private:
	int d_;
};


// 多态
class Fruit
{
public:
	virtual void Print()
	{
		cout << "Fruit::Print()" << endl;
	}
protected:
	string f_;
};

class Apple : public Fruit
{
public:
	virtual void Print()
	{
		cout << "Apple::Print()" << endl;
	}
protected:
	int a_;
};

class Orange : public Fruit
{
public:
	virtual void Print()
	{
		cout << "Orange::Print()" << endl;
	}
protected:
	int o_;
};

void TestPrint(Fruit& f)
{
	f.Print();
}

// 注意：在程序运行时，根据p所引用对象的不同，最终调用的虚函数就不一样
// 在程序编译时，无法确定具体要调用那个虚函数---因为：在编译阶段，
//   编译器根本不知道p到底指向的是那个类的对象

int main()
{
	Fruit f;
	TestPrint(f);

	Apple a;
	TestPrint(a);

	Orange o;
	TestPrint(o);
}

#endif
#if 0 
class A{};
class B : public A{};

// 协变
class Base
{
public:
	virtual Base& Test1()
	{
		cout << "Base::Test1()" << endl;
		return *this;
	}

	virtual A* Test2()
	{
		cout << "Base::Test2()" << endl;
		return nullptr;
	}
};

class Derived : public Base
{
public:
	virtual Derived& Test1()
	{
		cout << "Derived::Test1()" << endl;
		return *this;
	}

	virtual B* Test2()
	{
		cout << "Derived::Test2()" << endl;
		return nullptr;
	}
};

void TestVirtual(Base& b)
{
	b.Test1();
	b.Test2();
}

int main()
{
	Base b;
	TestVirtual(b);
	cout << "--------------" << endl;
	Derived d;
	TestVirtual(d);

	return 0;
}


#endif

class B
{
public:
	void Test1()
	{
		cout << "B::Test1()" << endl;
	}

	virtual void Test2()
	{
		cout << "B::Test2()" << endl;
	}

	void Test3()
	{
		cout << "B::Test3()" << endl;
	}

	virtual void Test4()
	{
		cout << "B::Test4()" << endl;
	}

	virtual void Test5()
	{
		cout << "B::Test5()" << endl;
	}

	virtual void Test6()
	{
		cout << "B::Test6()" << endl;
	}

	virtual void Test7()
	{
		cout << "B::Test7()" << endl;
	}

	virtual void Test8()
	{
		cout << "B::Test8()" << endl;
	}

	void Test9()
	{
		cout << "B::Test9()" << endl;
	}

	virtual void Test10(int a = 10)
	{
		cout << "B::Test10()" << endl;
	}
protected:
	int _b;
};

class D : public B
{
public:
	// 与基类中Test1的关系为同名隐藏
	void Test1()
	{
		cout << "D::Test1()" << endl;
	}

	// 与基类中Test2的关系为重写
	void Test2()
	{
		cout << "D::Test2()" << endl;
	}

	// 与基类中Test3的关系为同名隐藏
	virtual void Test3()
	{
		cout << "D::Test3()" << endl;
	}

	// 与基类中Test4的关系为重写
	virtual void Test4()
	{
		cout << "D::Test4()" << endl;
	}

	// 与基类中Test5的关系为同名隐藏
	virtual void Test5(int)
	{
		cout << "D::Test5()" << endl;
	}

	// 与基类中Test6关系：既不是重写也不是同名隐藏
	virtual void Tset6()
	{
		cout << "D::Test6()" << endl;
	}

	// 代码编译失败
	virtual int Test8()
	{
		cout << "D::Test8()" << endl;
		return 0;
	}

	// 与基类中Test9的关系为同名隐藏
	virtual int Test9()
	{
		cout << "D::Test9()" << endl;
		return 0;
	}

	// 与基类中Test10的关系为同名隐藏
	virtual int Test10()
	{
		cout << "D::Test10()" << endl;
		return 0;
	}

private:
	// 子类Test7的权限是私有的，为什么在类外还可以调用？
	// 与基类中Test7的关系为重写
	virtual void Test7()
	{
		cout << "D::Test7()" << endl;
	}

protected:
	int _d;
};