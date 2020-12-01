//#include <iostream>
//using namespace std;
//#include <string>
//
//bool PdString(string s)
//{
//	int len = s.size();
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		if (s[left] != s[right])
//		{
//			return false;
//		}
//		else
//		{
//			left++;
//			right--;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	string A;
//	string B;
//
//	int count = 0;
//
//
//	while (cin >> A >> B)
//	{
//		int a_len = A.size();
//		for (int i = 0; i < a_len; i++)
//		{
//			string C(A);
//			C.insert(i, B, 0, B.size());
//			if (PdString(C))
//			{
//				count++;
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//char func(char x, char y)
//{
//	if (x < y)
//		return x;
//	return y;
//}
//
//int main()
//{
//	int a = '1', b = '1', c = '2';
//	cout << func(func(a, b), func(b, c));
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//#include <string>
//
//int StrToInt(string str) {
//	int flag = 0;
//	int len = str.size();
//	string s;
//	if (str[0] == '+')
//	{
//		flag = 0;
//	}
//	else if (str[0] == '-')
//	{
//		flag = 1;
//	}
//	int i = 0;
//	if (flag == 1)
//	{
//		i = 1;
//	}
//	else if (flag == 0)
//	{
//		i = 0;
//	}
//
//	for (; i < len; i++)
//	{
//		if (str[i] < '0' || str[i] > '9')
//			return 0;
//		else
//		{
//			s.push_back(str[i]);
//		}
//	}
//
//	if (flag == 1)
//	{
//		s += '-';
//	}
//	sort(s.begin(), s.end());
//	long long ret = atoi(s.c_str());
//	return ret;
//}
//
//
//int main()
//{
//	string s0("123456");
//	int ret = StrToInt(s0);
//	cout << ret << endl;
//
//	string s2("1a223");
//	ret = StrToInt(s2);
//	cout << ret << endl;
//	return 0;
//}




//#include <iostream>
//#include <algorithm>
//using namespace std;
//#include <string>
//
//int StrToInt(string str) {
//	int flag = 0;
//	int len = str.size();
//	string s;
//	int i = 0;
//	if (str[0] == '+')
//	{
//		flag = 0;
//		i = 1;
//	}
//	else if (str[0] == '-')
//	{
//		flag = 1;
//		i = 1;
//	}
//
//	for (i; i < len; i++)
//	{
//		if (str[i] < '0' || str[i] > '9')
//			return 0;
//		else
//		{
//			s.push_back(str[i]);
//		}
//	}
//
//	long long int ret;
//	if (flag == 1)
//	{
//		ret = -atoi(s.c_str());
//	}
//	else
//	{
//		ret = atoi(s.c_str());
//	}
//	return ret;
//}
//
//
//int main()
//{
//	string s0("+2147483647");
//	int ret = StrToInt(s0);
//	cout << ret << endl;
//
//	string s2("-1a33");
//	ret = StrToInt(s2);
//	cout << ret << endl;
//	return 0;
//}

//#include <iostream>
//#include <stack>
//using namespace std;
//
//bool chkParenthesis(string A, int n) {
//	// write code here
//	if (n % 2 == 1)
//		return false;
//	stack<char> s;
//	for (int i = 0; i < n; i++)
//	{
//		if (A[i] != '(' && A[i] != ')')
//			return false;
//		if (A[i] == '(')
//			s.push(A[i]);
//		else if (A[i] == ')')
//		{
//			if (s.top() == '(')
//				s.pop();
//			else
//				return false;
//		}
//	}
//	if (s.empty())
//		return true;
//	else
//		return false;
//}
//
//int main()
//{
//	string s("(a()a)");
//	bool flag = chkParenthesis(s, s.size());
//	if (flag)
//		cout << "1" << endl;
//	else
//		cout << "0" << endl;
//	return 0;
//}

#include <iostream>
using namespace std;
#include <List>

struct ListNode {
	int val;
	struct ListNode *next;
};


ListNode* reverse(ListNode* head)
{
	ListNode* cur = head;
	cur->next = NULL;
	head = head->next;
	while (head)
	{
		ListNode* prev = head;
		head = head->next;

		prev->next = cur;
		cur = prev;
	}
	return cur;
}

int main()
{
	List he
	prev = reverse(head);
	
	return 0;
}