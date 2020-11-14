//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int nums[33][33] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			nums[i][j] = 1;
//		}
//	}
//
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			nums[i][j] = nums[i - 1][j] + nums[i - 1][j - 1];
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%-5d", nums[i][j]);
//		}
//		cout << endl;
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int nums[12] = { 0 };
//	int i = 0;
//	while (n)
//	{
//		int a = n % 6;
//		n = n / 6;
//		nums[i++] = a;
//	}
//
//	for (i; i > 0; i--)
//		cout << nums[i];
//	cout << endl;
//	return 0;
//}


#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	if (n > m)
	{
		int tmp = n;
		n = m;
		m = tmp;
	}
	long int a = 1;
	long int c = n * m;
	long int b = c;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0 && m % i == 0)
		{
			if (a < i)
				a = i;
		}
	}
	
	for (int i = n; i <= c; i++)
	{
		if (i % n == 0 && i % m == 0)
		{
			if (b > i)
				b = i;
		}
	}
	cout << a + b << endl;
	return 0;
}