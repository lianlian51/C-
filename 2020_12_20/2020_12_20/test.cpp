#include <iostream>
using namespace std;

#include <string>

#if 0
// ����̳�
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

// ���μ̳ж�����----��������̳�
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


// ��̬
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

// ע�⣺�ڳ�������ʱ������p�����ö���Ĳ�ͬ�����յ��õ��麯���Ͳ�һ��
// �ڳ������ʱ���޷�ȷ������Ҫ�����Ǹ��麯��---��Ϊ���ڱ���׶Σ�
//   ������������֪��p����ָ������Ǹ���Ķ���

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

// Э��
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
	// �������Test1�Ĺ�ϵΪͬ������
	void Test1()
	{
		cout << "D::Test1()" << endl;
	}

	// �������Test2�Ĺ�ϵΪ��д
	void Test2()
	{
		cout << "D::Test2()" << endl;
	}

	// �������Test3�Ĺ�ϵΪͬ������
	virtual void Test3()
	{
		cout << "D::Test3()" << endl;
	}

	// �������Test4�Ĺ�ϵΪ��д
	virtual void Test4()
	{
		cout << "D::Test4()" << endl;
	}

	// �������Test5�Ĺ�ϵΪͬ������
	virtual void Test5(int)
	{
		cout << "D::Test5()" << endl;
	}

	// �������Test6��ϵ���Ȳ�����дҲ����ͬ������
	virtual void Tset6()
	{
		cout << "D::Test6()" << endl;
	}

	// �������ʧ��
	virtual int Test8()
	{
		cout << "D::Test8()" << endl;
		return 0;
	}

	// �������Test9�Ĺ�ϵΪͬ������
	virtual int Test9()
	{
		cout << "D::Test9()" << endl;
		return 0;
	}

	// �������Test10�Ĺ�ϵΪͬ������
	virtual int Test10()
	{
		cout << "D::Test10()" << endl;
		return 0;
	}

private:
	// ����Test7��Ȩ����˽�еģ�Ϊʲô�����⻹���Ե��ã�
	// �������Test7�Ĺ�ϵΪ��д
	virtual void Test7()
	{
		cout << "D::Test7()" << endl;
	}

protected:
	int _d;
};