#include <iostream>
using namespace std;

int getTotalCount(int n)
{
	int n1 = 1, n2 = 0, n3 = 0;
	while (n--)
	{
		int temp = n3; // ��¼�³���������
		n3 += n2;   // ��¼2���µ�3���µ�����+ԭ�������µ����Ӻ�
		n2 = n1;   // ��¼һ���µ������µ�����
		n1 = temp;  // ��һ���µ����Ӹ�n1
	}
	return n1 + n2 + n3; // ��һ���������������µ��������ӷ���
}

int main()
{
	int n;
	while (cin >> n)
	{
		int ret = getTotalCount(n);
		cout << ret << endl;
	}
	return 0;
}