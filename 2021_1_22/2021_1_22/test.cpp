//#include <iostream>
//using namespace std;
//#include <vector>
//
//int Sum(int a, int b)
//{
//	for (int i = b; i > 0; i--)
//	{
//		if (b % i == 0 && a % i == 0)
//			return i;
//	}
//	return 0;
//}
//int main()
//{
//	int a, c;
//	while (cin >> a >> c)
//	{
//		vector<int> vec;
//		for (int i = 0; i < a; i++)
//		{
//			int temp;
//			cin >> temp;
//			vec.push_back(temp);
//		}
//		int len = vec.size();
//		for (int i = 0; i < len; i++)
//		{
//			if (vec[i] <= c)
//			{
//				c += vec[i];
//			}
//			else
//			{
//				int b = vec[i];
//				int num = Sum(b, c);
//				c += num;
//			}
//		}
//		cout << c << endl;
//	}
//	return 0;
//}


#include <iostream>
using namespace std;
#include <string>


int main()
{
	string s;
	while (cin >> s)
	{
		int num[130] = { 0 };
		while (*s)
		{
			num[*s]++;
			*s++;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (num[s[i]] == 1)
				cout << s[i] << endl;
		}
		cout << "-1" << endl;
	}
	return 0;
}