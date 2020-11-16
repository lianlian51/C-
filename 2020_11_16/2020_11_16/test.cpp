//#include <iostream>
//using namespace std;
//
//// 判断是否是二段数
//bool IsDig(long long n)
//{
//	// n1,n2保存两个位数
//	// n3保存n
//	long long n1, n2, n3 = n;
//	// flag 记录下面n1和n2的不同的次数，超过两次（包括2），则表示不是二段数
//	long flag = 0;
//	if (n < 10)
//		return false;
//	while (1)
//	{
//		n1 = n3 % 10;
//		n3 /= 10;
//		n2 = n3 % 10;
//
//		// 记录不是二段数的次数
//		if (n1 != n2)
//			flag++;
//		if (flag == 2)
//			return false;
//		// 上面情况满足，如果n3小于10，则表示是二段数
//		if (n3 < 10)
//			return true;
//	}
//}
//
//int main(void)
//{
//	int n;
//	long long i = 1;
//	long long a = 0;
//	// 循环输入
//	while (1)
//	{
//		cin >> n;
//		// 小于10的只有一位数，所以不是二段数，直接返回0
//		if (n == 0)
//			return 0;
//		do
//		{
//			// i表示要乘的倍数
//			// 这里用do...while判定这个数是不是二段数
//			i++;
//			a = (i * n);
//		} while (!IsDig(a));
//		cout << n << ":" << a << endl;
//		i = 1;
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	if (n < 0 || n > 100)
//	{
//		cout << "F" << endl;
//		goto ret;
//	}
//	n /= 10;
//
//	switch (n)
//	{
//	case '10':
//		cout << "A" << endl;
//		break;
//	case '9':
//		cout << "A" << endl;
//		break;
//	case '8':
//		cout << "B" << endl;
//		break;
//	case '7':
//		cout << "C" << endl;
//		break;
//	case '6':
//		cout << "D" << endl;
//		break;
//	default:
//		cout << "E" << endl;
//		break;
//	}
//ret:
//	return 0;
//}

//
//#include <iostream>
//using namespace std;
//
//int Num(int n)
//{
//	if (n == 1)
//		return 1;
//
//	int a = n;
//	int num = 1;
//	for (int i = a; i > 0; i--)
//	{
//		num *= i;
//	}
//	return num;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int num = 0;
//	for (int i = n; i > 0; i--)
//	{
//		num += Num(i);
//	}
//	cout << num << endl;
//	return 0;
//}


#include <iostream>
using namespace std;

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int max3(int a, int b, int c)
{
	if (a > b)
		Swap(a, b);
	if (b < c)
		return c;
	else
		return b;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	double m = max3(a + b, b, c) / (max3(a, b + c, c) + max3(a, b, b + c));
	printf("%.2f\n", m);
	return 0;
}