#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("0x%x 0%o", &a, &b); // 八进制和十六进制相加
	printf("%d\n", a + b); // 十进制输出
	return 0;
}