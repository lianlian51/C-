#include <iostream>

using namespace std;


class Date{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	return 0;
}

class Date
{
public:
	Date(int year)
		: _year(year)
	{}
	explicit Date(int year)
		: _year(year)
	{}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020);
	// ��һ�����ͱ������������Ͷ���ֵ
	// ʵ�ʱ�����������2019����һ������������������������d1������и�ֵ
	d1 = 2019;
}

class B
{
public:
	B(int b = 0)
		: _b(b)
	{}

	int _b;
};

class A
{
public:
	void Print()
	{
		cout << a << endl;
		cout << b._b << endl;
		cout << p << endl;
	}
private:
	// �Ǿ�̬��Ա�����������ڳ�Ա����ʱ��ȱʡֵ
	int a = 10;
	B b = 20;
	int *p = (int*)malloc(4);
	static int n;
};


class Date{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);

public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}


private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}


int main()
{
	Date d;
	cin >> d;
	cout << d << endl;
	return 0;
}

class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;
			cout << a.h << endl;
		}
	};
};

int A::k = 1;

int main()
{
	A::B b;
	b.foo(A());
	return 0;
}