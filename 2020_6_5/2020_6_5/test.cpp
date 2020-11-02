#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack<char> Digital_string(char* _str, stack<char> _s1, stack<char> _s2)
{
	int len = strlen(_str);
	char temp = '0';
	for (int i = 0; i <= len; i++)
	{
		if (*_str >= 'a' && *_str <= 'z')
		{
			if (_s1.size() != 0 && _s1.size() > _s2.size())
			{
				while (_s2.size() != 0)
				{
					_s2.pop();
				}
				while (_s1.size() != 0)
				{
					temp = _s1.top();
					_s2.push(temp);
					_s1.pop();
				}
			}
		}
		else if (*_str >= 0 && *_str <= 9)
		{
			_s1.push(*_str);
		}
	}
	return _s2;
}

int main()
{
	stack<char> s1;
	stack<char> s2;

	char str[255] = { 0 };
	cin.getline(str, 255);

	if (strlen(str) == 0)
		return 0;

	s2 = Digital_string(str, s1, s2);

	while (s2.size() != 0)
	{
		cout << s2.top();
		s2.pop();
	}

	return 0;
}