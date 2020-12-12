//#include <iostream>
//using namespace std;
//#include <vector>
//
//int FindNum(vector<vector<int>> vec_, int n)
//{
//	vec_[0][n] = 1;
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 1; j < 2 * n; j++)
//		{
//			vec_[i][j] = vec_[i - 1][j - 1] + vec_[i - 1][j] + vec_[i - 1][j + 1];
//		}
//	}
//	int ret = -1;
//	int len = 2 * n;
//	int row = n - 1;
//	for (int i = 1; i < len; i++)
//	{
//		if (vec_[row][i] % 2 == 0)
//		{
//			ret = i;
//			break;
//		}
//
//	}
//	return ret;
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<vector<int>> vec_(n);
//		for (int i = 0; i < n; i++)
//		{
//			vec_[i].resize(2 * n + 1, 0);
//		}
//
//		int num = FindNum(vec_, n);
//		cout << num << endl;
//	}
//	return 0;
//}

#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
	int a = 100;
	char buffer[33];
	_itoa_s(a, buffer, 16);
	cout << buffer << endl;
	return 0;
}