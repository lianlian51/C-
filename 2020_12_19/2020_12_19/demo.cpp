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
	// ������ͬ�������γ�����
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
	// ͬ������
	// ͨ�������������Լ������TestFuncû�������
	// ����������ʸ����TestFunc�ǲ��е�
	// ����̳л���������TestFunc����ͬ������

	Derived d;
	d.TestFunc(10);

	// ������������
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

// ������Ŀ������캯��������û���Ŀ���������ɻ���Ŀ�����ʼ��
// ���������operator=����Ҫ���û����operator=��ɻ���ĸ�ֵ

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

	// ע�⣺������������������Ĺ���
	// 1.�Ƚ��Լ��ڲ�����Դ����ɾ�---�����Լ����ܹ����������Լ�����Դ
	// 2.Ȼ������ӻ���̳���������Դ---��������ɣ��������ڱ�������ڼ䣬
	//   �������������������һ����Ч���֮������˵��û�����������
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
	// ͬ������
	// ͨ�������������Լ������TestFuncû�������
	// ����������ʸ����TestFunc�ǲ��е�
	// ����̳л���������TestFunc����ͬ������

	Derived d;
	d.TestFunc(10);

	// ������������
	d.Base::TestFunc();
	return 0;
}
