#include <iostream>
using namespace std;

int getTotalCount(int n)
{
	int n1 = 1, n2 = 0, n3 = 0;
	while (n--)
	{
		int temp = n3; // 记录新出生的兔子
		n3 += n2;   // 记录2个月到3个月的兔子+原本三个月的兔子和
		n2 = n1;   // 记录一个月到两个月的兔子
		n1 = temp;  // 将一个月的兔子给n1
	}
	return n1 + n2 + n3; // 将一个月两个月三个月的所有兔子返回
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