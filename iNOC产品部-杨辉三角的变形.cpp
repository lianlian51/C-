#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
        // 定义一个二维数组，n行，2*n + 1 列（这本应该是2*n - 1列）
		vector<vector<int>> vv(n, vector<int>(2 * n + 1, 0));
        // 将第一行最中间的数字置为1 
		vv[0][(2 * n + 1) / 2] = 1;
        
        // 从第二行开始，每次都是上面的j，j - 1，j - 2来进行加和
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < 2 * n; j++)
			{
				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j] + vv[i - 1][j + 1];
			}
		}

		int i = 1;
        // 遍历第n行，遇到第一个偶数直接打印下标，然后break
		for (i; i < 2 * n + 1; i++)
		{
			if (vv[n - 1][i] % 2 == 0)
			{
				cout << i << endl;
				break;
			}
		}
        
        // 如果此行没有偶数，直接打印-1
		if (i == 2 * n + 1)
			cout << -1 << endl;
	}
	return 0;
}
