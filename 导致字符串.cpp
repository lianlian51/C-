#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

stack<char> String_inversion(char* _str, stack<char> _s1, stack<char> _s2)
{
    // tem用于存储_s1的栈顶元素
	char tem = '0';
	int len = strlen(_str);
    // 数组遍历
	for (int i = 0; i <= len; i++)
	{
		if (*_str == ' ' || *_str == '\0')
		{
			_s1.push(' ');
            // _s1的所有压入_s2
			while (_s1.size() != 0)
			{
                // 因为栈没有遍历操作，所以取得栈顶然后压栈_s2
                // _s1出栈,知道_s1栈空
				tem = _s1.top();
				_s2.push(tem);
				_s1.pop();
			}
            _str++;
		}
		else
		{
            // 是字符的话就直接压栈
			_s1.push(*_str);
			_str++;
		}
	}
    return _s2;
}

int main()
{
    // s2最后接收
	stack<char> s1;
	stack<char> s2;

	char str[100] = { 0 };
	cin.getline(str, 100);

	if (strlen(str) == 0)
		return 0;

	s2 = String_inversion(str, s1, s2);
    // 打印
	while (s2.size() != 0)
	{
		cout << s2.top();
		s2.pop();
	}

	return 0;
}
