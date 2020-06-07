#include <iostream>
#include <string>
using namespace std;

// 这个函数是为了判定它是不是回文数
bool is_reverse(const string& s)
{
	int left = 0;
	int right = s.size() - 1;
	while (left < right)
	{
		if (s[left] != s[right])
			return false;
		else
		{
			right--;
			left++;
		}
	}
	return true;
}

int main()
{
	int count = 0;
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		for (int i = 0; i <= s1.size(); i++)
		{
			// substr截断前面，然后将s2
			// 连接上去，在连接right，最后判断是否是回文数
			string left = s1.substr(0, i);
			string right = s1.substr(i);
			left += s2;
			left += right;
			if (is_reverse(left))
			{
				// 是的话就++
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
