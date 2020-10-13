
// 构造函数
//#include <iostream>
//
//using namespace std;
//
//class Date
//{
//public:
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	d1.SetDate(2018, 5, 1);
//	d1.Display();
//
//	Date d2;
//	d2.SetDate(2018, 7, 1);
//	d2.Display();
//	return 0;
//}



//#include <iostream>
//
//using namespace std;
//
//class Date
//{
//public:
//	Date()
//	{}
//
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;  // 调用无参构造函数
//
//	Date d2(2015, 1, 1);  // 调用带参构造函数
//
//	return 0;
//}

//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = _day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Test()
//{
//	Date d1;
//}
#include <iostream>
using namespace std;
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
private:
	// 基本类型（内置类型）
	int _year;
	int _month;
	int _day;

	// 自定义类型
	Time _t;
};

int main()
{
	Date d;
	return 0;
}
// 析构函数
#include <assert.h>
#include <malloc.h>
typedef int DataType;

class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);

		_size = 0;
		_capacity = capacity;
	}

	~SeqList()
	{
		if (_pData)
		{
			free(_pData);
			_pData = NULL;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};

// 拷贝构造函数
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2(d1);
	return 0;
}

class String {
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2(s1);
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator==(const Date& d2)
	{
		return (_year == d2._year && _month == d2._month && _day == d2._day);
	}
private:
	int _year;
	int _month;
	int _day;
};

void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
}



class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
private:
	int _year;
	int _month;
	int _day;
};