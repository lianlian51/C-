//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int num;
//	cin >> num;
//	int count = 0;
//	int temp = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//		{
//			temp++;
//		}
//		if (num % 2 == 0)
//		{
//			temp = 0;
//		}
//		num /= 2;
//		if (temp > count)
//			count = temp;
//	}
//	cout << count << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#define sqr(A) A*A
//
//int main()
//{
//	int x = 6, y = 3, z = 2;
//	x /= sqr(y + z) / sqr(y + z);
//	cout << x << endl;
//	return 0;
//}

#include <iostream>
using namespace std;

bool isNum(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int bin = n / 2;
	int a = bin;
	int b = bin;
	for (int i = 0;; i++)
	{
		while (!isNum(a))
			a--;
		while (!isNum(b))
			b++;
		if (a + b == n)
			break;
		else if (a + b < n)
		{
			b++;
		}
		else if (a + b > n)
		{
			a--;
		}
	}
	cout << a << endl;
	cout << b << endl;
	return 0;
}