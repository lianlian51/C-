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
	// ���뵥��Test���͵Ŀռ�
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);

	// ����10��Test���͵Ŀռ�
	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
	free(p2);
}

void Test2()
{
	// ���뵥��Test���͵Ķ���
	Test* p1 = new Test;
	delete p1;

	//����10��Test���͵Ķ���
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
	// pt����ָ��Ĳ�������Test������ͬ��С��һ�οռ䣬
	// ����������һ��������Ϊ���캯��û��ִ��
	Test* pt = (Test*)malloc(sizeof(Test));

	new(pt) Test(10); // ע�⣺���Test��Ĺ��캯���в�ʱ���˴���Ҫ����
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