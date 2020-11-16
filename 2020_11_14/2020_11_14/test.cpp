//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int num;
//	cin >> num;
//	int nums[11] = { 0 };
//	int i = 0;
//	while (num)
//	{
//		int a = num % 10;
//		num /= 10;
//		if (a % 2 == 0)
//			nums[i++] = 0;
//		else if (a % 2 == 1)
//			nums[i++] = 1;
//	}
//	int count = i;
//	int k = i;
//	while (nums[k - 1] == 0)
//	{
//		count--;
//		k--;
//	}
//
//	for (k = count; k > 0; k--)
//	{
//		cout << nums[k - 1];
//	}
//	return 0;
//}



#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int nums[50001] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		nums[tmp]++;
	}
	for (int i = 0; i < 50001; i++)
	{
		if (nums[i] != 0)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}