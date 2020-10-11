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