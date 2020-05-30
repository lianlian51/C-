#include <iostream>
using namespace std;
#include <queue>

#if 0
void Testpriority_queue1()
{
	priority_queue<int> q; // 默认情况下，优先级队列表示大堆
	q.push(4);
	q.push(5);
	q.push(1);
	q.push(2);
	q.push(9);
	q.push(8);
	q.push(7);

	cout << q.size() << endl;
	cout << q.top() << endl;

	// 栈顶元素不可修改
	// 有些编译器可以修改，但是修改之后不满足堆的特性
	// q.top() = 100;
	cout << q.size() << endl;
	cout << q.top() << endl;
}

// 小堆，需要调用头文件functional
#include <functional>
void Testpriority_queue()
{
	priority_queue<int, vector<int>, greater<int>> q; // 这里要表示小堆的话，就必须三个参数都写，否则编译失败
	q.push(4);
	q.push(5);
	q.push(1);
	q.push(2);
	q.push(9);
	q.push(8);
	q.push(7);

	cout << q.size() << endl;
	cout << q.top() << endl;
}

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}


	 自定义类型的Date默认不能进行比较，必须给出方法
	 第一种:运算符重载
	bool operator<(const Date& d)const
	{
		return _day < d._day;
	}

	bool operator>(const Date& d)const
	{
		return _day > d._day;
	}

private:
	size_t _year;
	size_t _month;
	size_t _day;
};



void Test1()
{
	Date d1(2020, 5, 6);
	Date d2(2020, 5, 7);
	Date d3(2020, 5, 8);

	// priority_queue<Date> p; // 大堆
	priority_queue<Date, vector<Date>, greater<Date>> p; // 小堆
	p.push(d1);
	p.push(d2);
	p.push(d3);
}
#endif


#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}


	friend bool IsLess(const Date& left, const Date& right);
private:
	size_t _year;
	size_t _month;
	size_t _day;
};

// 第二种方法：函数指针
bool IsLess(const Date& left, const Date& right)
{
	return left._day < right._day;
}

typedef bool(*Less)(const Date& left, const Date& right);


// 小堆
//bool IsGreater(const Date& left, const Date& right)
//{
//	return left._day > right._day;
//}
//
//typedef bool(*Greater)(const Date& left, const Date& right);


void Test2()
{
	Date d1(2020, 5, 6);
	Date d2(2020, 5, 7);
	Date d3(2020, 5, 8);

	priority_queue<Date, vector<Date>, Less> p(IsLess); // 大堆
	p.push(d1);
	p.push(d2);
	p.push(d3);
}
#endif

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	int Getday()
	{
		return _day;
	}
private:
	int _year;
	int _month;
	int _day;
};

// 第三种：仿函数----->函数对象
class Greater
{
public:
	// ():函数调用运算符
	bool operator()(Date& left, Date& right) // 这里不要写const，不然类型限定符不兼容
	{
		return left.Getday() > right.Getday();
	}
};

void Test3()
{
	Date d1(2020, 5, 6);
	Date d2(2020, 5, 7);
	Date d3(2020, 5, 8);

	priority_queue<Date, vector<Date>, Greater> p; // 小堆
	p.push(d1);
	p.push(d2);
	p.push(d3);
}
int main()
{
	// Testpriority_queue1();
	// Testpriority_queue();
	/*Test1();
	Test2();*/
	Test3();

	return 0;

}
