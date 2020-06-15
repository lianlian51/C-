#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		// 计数空格的数量
		int count = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
				count++;
			if (str[i] == '"')
			{
				do{
					i++;
				} while (str[i] != '"');
			}
		}
		// 参数的个数一定比空格多1
		cout << count + 1 << endl;

	    int flag = 1;
	    for (int i = 0; i < str.size(); i++)
     	{
		    // 如果是“的话就flag置为0
		    if (str[i] == '"')
			    flag ^= 1;

		    // 不是空格和双引号直接打印
		    if (str[i] != ' ' && str[i] != '"')
			    cout << str[i];

		    // 不在双引号内的空格直接换行
		    if (str[i] == ' ' && (flag))
			    cout << ' ' << endl;

		    // 双引号内的空格直接打印
		    if (str[i] == ' ' && (!flag))
			    cout << str[i];
	    }
    }
	cout << endl;
	return 0;
}
