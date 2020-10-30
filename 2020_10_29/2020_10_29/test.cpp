#if 0
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
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Fun1(char *arr, int len)
{
	for (int i = 0; i < len - 2; i++)
	{
		for (int j = 0; j = len - i - 3; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				char tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	char arr[] = "dsgcds";
	printf("%s\n", arr);
	int num = sizeof(arr) / sizeof(arr[0]);
	
	for (int i = 0; i < num - 2; i++)
	{
		for (int j = 0; j < num - i - 3; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				char tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	printf("%s\n", arr);
	return 0;
}