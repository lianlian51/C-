//#include <iostream>
//using namespace std;
//
//// �ж��Ƿ��Ƕ�����
//bool IsDig(long long n)
//{
//	// n1,n2��������λ��
//	// n3����n
//	long long n1, n2, n3 = n;
//	// flag ��¼����n1��n2�Ĳ�ͬ�Ĵ������������Σ�����2�������ʾ���Ƕ�����
//	long flag = 0;
//	if (n < 10)
//		return false;
//	while (1)
//	{
//		n1 = n3 % 10;
//		n3 /= 10;
//		n2 = n3 % 10;
//
//		// ��¼���Ƕ������Ĵ���
//		if (n1 != n2)
//			flag++;
//		if (flag == 2)
//			return false;
//		// ����������㣬���n3С��10�����ʾ�Ƕ�����
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
//	// ѭ������
//	while (1)
//	{
//		cin >> n;
//		// С��10��ֻ��һλ�������Բ��Ƕ�������ֱ�ӷ���0
//		if (n == 0)
//			return 0;
//		do
//		{
//			// i��ʾҪ�˵ı���
//			// ������do...while�ж�������ǲ��Ƕ�����
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