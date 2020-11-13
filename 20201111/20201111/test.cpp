#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int nums[33][33] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			nums[i][j] = 1;
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			nums[i][j] = nums[i - 1][j] + nums[i - 1][j - 1];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%-5d", nums[i][j]);
		}
		cout << endl;
	}
	return 0;
}