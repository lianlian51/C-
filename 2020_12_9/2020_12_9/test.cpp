//#include <iostream>
//using namespace std;
//
//int nums[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//
//int main()
//{
//	int y, m, d;
//	while (cin >> y >> m >> d)
//	{
//		int num = nums[m - 1];
//		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
//			num += 1;
//		cout << num << endl;
//	}
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int findMinimum(int n, vector<int> left, vector<int> right) {
//	// write code here
//	int sum = 0;
//	int leftSum = 0, rightSum = 0;
//	int leftMin = 30, rightMin = 30;
//	for (int i = 0; i < n; i++)
//	{
//		if (left[i] * right[i] == 0)
//			sum += (left[i] + right[i]);
//		else
//		{
//			leftSum += left[i];
//			rightSum += right[i];
//			leftMin = min(leftMin, left[i]);
//			rightMin = min(rightMin, right[i]);
//		}
//	}
//	return sum + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;
//}
//
//int main()
//{
//	int n = 4;
//	vector<int> v1{ 0, 7, 1, 6 };
//	vector<int> v2{ 1, 5, 0, 6 };
//	cout << findMinimum(n, v1, v2) << endl;
//	return 0;
//}

// 八皇后问题
#include <iostream>
using namespace std;

int place[8] = { 0 }; // 放置皇后
int flag[8] = { 0 };  // 防止列冲突
int d1[15] = { 0 };   // 主对角线差相等，有负数的情况，这里直接加上7
int d2[15] = { 0 };   // 次对角线的和相等
int count_ = 0;   // 记录放置成功的次数

void search(int k) // k:代表行
{
	for (int i = 0; i < 8; i++) // i:代表列
	{
		if (flag[i] == 0 && d1[k - i + 7] == 0 && d2[k + i] == 0)
		{
			place[i] = 1;
			flag[i] = 1;
			d1[k - i + 7] = 1;
			d2[k + i] = 1;
			if (k == 7)
			{
				count_++;
			}
			else
			{
				search(k + 1);
			}
			flag[i] = 0;
			d1[k - i + 7] = 0;
			d2[k + i] = 0;
		}
	}
}


int main()
{
	search(0);
	cout << count_ << endl;
	return 0;
}