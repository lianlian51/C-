#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> v;
	string str;
    // len:str的长度 cur:将数字那块置为一个升序的数字序列
    // Max：记录v最大的数字 num：最长数字串的最后一个数字下标
	int len, cur = 1, Max = 0, num = 0;
	cin >> str;


	len = str.size();
	if (len > 0)
	{
		for (int i = 0; i < len; i++)
		{
            // 强转成int
			int temp = (int)str[i];
			if (temp >= 48 && temp <= 57)
			{
				v.push_back(cur);
				cur++;
			}
			else
			{
				v.push_back(0);
				cur = 1;
			}
		}
        // 寻找最长数字穿的下标
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] > Max)
			{
				Max = v[i];
				num = i;
			}
		}

        // 遍历，打印
		for (int i = num - Max + 1; i <= num; i++)
		{
			cout << str[i];
		}
	}
	return 0;
}
