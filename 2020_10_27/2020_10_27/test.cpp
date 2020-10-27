#include <iostream>
using namespace std;

class Test{
public:
	Test(int t = 0)
		: _t(t)
	{
		cout << "Test(int):" << this << endl;
	}

	~Test()
	{
		cout << "~Test(int):" << this << endl;
	}

private:
	int _t;
};

int main()
{
	int *p1 = new int;
	int *p2 = new int(10);

	int* p3 = new int[10];
	int* p4 = new int[10]{1, 2, 3, 4, 5};

	delete p1;
	delete p2;

	delete[] p3;
	delete[] p4;
	return 0;
}