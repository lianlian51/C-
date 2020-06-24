#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int T, n, k;
    cin >> T;
	while (T--)
	{
        cin >> n >> k;
		int num = 2 * n;
		// 转换的数组
		vector<int> table(num);
        // 给数组输入值
		for (int i = 0; i < num; i++)
			cin >> table[i];

		// 打印的数组
		vector<int> v(table.begin(), table.end());

		while (k--)
		{
            // table的下标
			int index = 0;
            // left：左手的最后一张牌 right：右手的最后一张牌
			int left = (v.size() / 2) - 1;
			int right = v.size() - 1;
            // 左右手都有牌
			while (left >= 0 && right >= (v.size() / 2))
			{
                // 先赋值右手，然后左手
				table[index++] = v[right--];
				table[index++] = v[left--];
			}
            // 将洗好的牌给反向v
			for (int i = 0; i < table.size(); i++)
				v[i] = table[table.size() - 1 - i];
		}
        // 打印v
		for (int i = 0; i < v.size() - 1; i++)
			cout << v[i] << " ";
		cout << v[v.size() - 1] << endl;
	}
	return 0;
}
