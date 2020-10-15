#include <iostream>
using namespace std;

class Date
{
public:
	void Display()
	{
		cout << "Display()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl;
	}

	void Display()const
	{
		cout << "Display()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void Test()
{
	Date d1;
	d1.Display();

	const Date d2;
	d2.Display();
}


//class Date
//{
//public:
//	Date*operator&()
//	{
//		return this;
//	}
//	const Date* operator&()const
//	{
//		return this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};