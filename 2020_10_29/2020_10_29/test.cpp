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