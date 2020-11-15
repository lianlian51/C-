#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	int nums1[100][100] = { 0 };
	int nums2[100][100] = { 0 };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nums1[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nums2[i][j];
		}
	}

	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (nums1[i][j] == nums2[i][j])
			{
				count++;
			}
		}
	}

	printf("%.2f\n", count / (m * n));
	return 0;
}