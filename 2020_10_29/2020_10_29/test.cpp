#include <iostream>
using namespace std;

#if 0
class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << endl;
	}

	~Test()
	{
		cout << "~Test():" << endl;
	}
private:
	int _data;
};

void Test2()
{
	// 申请单个Test类型的空间
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);

	// 申请10个Test类型的空间
	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
	free(p2);
}

void Test2()
{
	// 申请单个Test类型的对象
	Test* p1 = new Test;
	delete p1;

	//申请10个Test类型的对象
	Test* p2 = new Test[10];
	delete[] p2;
}
#endif
#include <string.h>
#include <malloc.h>


class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this <<  endl;
	}
private:
	int _data;
};

void Test()
{
	// pt现在指向的不过是与Test对象相同大小的一段空间，
	// 还不能算是一个对象，因为构造函数没有执行
	Test* pt = (Test*)malloc(sizeof(Test));

	new(pt) Test(10); // 注意：如果Test类的构造函数有参时，此处需要传参
}


int main()
{
	Test();
	return 0;
}



#include <iostream>
using namespace std;

int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}