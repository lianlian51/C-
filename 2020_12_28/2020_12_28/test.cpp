// �������д��麯������---��Ϊ������
// �����಻��ʵ��������
// ��������һ��Ҫ���̳еģ�������������������Ҫ�Դ��麯��������д
// ���������û����д�������Ǹ����麯����������Ҳ�ǳ�����

#include <iostream>
using namespace std;
#include <string>

#if 0
class Work
{
public:
	void toEmployee()
	{
		cout << "����" << endl;
	}

	void toProgrammer()
	{
		cout << "����" << endl;
	}
};

class Person
{
public:
	// Employee��Ϣ��ȫ��,���Թ����ķ���û�а취ʵ��
	// ���麯��
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
	PrintPvft(b, "�������");
	D d;
	PrintPvft(d, "���������");
	return 0;
}