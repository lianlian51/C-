//#include <iostream>
//using namespace std;
//#include <vector>
//
//void Joker(vector<int>& vec)
//{
//	int n = vec.size() / 2;
//	vector<int> v;
//	int i = 2*n - 1;
//	int j = n - 1;
//	int temp = n;
//	while (temp--)
//	{
//		v.push_back(vec[i]);
//		v.push_back(vec[j]);
//		i--, j--;
//	}
//
//	for (int i = 0; i < 2 * n; i++)
//	{
//		vec[i] = v[2 * n - i - 1];
//	}
//}
//
//int main()
//{
//	int T, n, k;
//	cin >> T;
//	while (T--)
//	{
//		cin >> n >> k;
//		vector<int> vec;
//		for (int i = 0; i < 2 * n; i++)
//		{
//			int temp;
//			cin >> temp;
//			vec.push_back(temp);
//		}
//		while (k--)
//		{
//			Joker(vec);
//		}
//		for (int i = 0; i < 2 * n; i++)
//		{
//			cout << vec[i] << " ";
//		}
//	}
//	return 0;
//}


#include <iostream>
using namespace std;
#include <string>
#include <vector>

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	vector<int> vec({ 1, 2, 3, 4 });
	int flag = 1;
	if (n <= 4)
	{
		int count = s.size();
		for (int i = 0; i < count; i++)
		{
			if (s[i] == 'U')
			{
				if (flag == 1)
				{
					flag = n;
				}
				else
				{
					flag--;
				}
			}
			else if (s[i] == 'D')
			{
				if (flag == n)
				{
					flag = 1;
				}
				else
				{
					flag++;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
		cout << flag << endl;
	}
	else
	{
		int count = s.size();
		for (int i = 0; i < count; i++)
		{
			if (s[i] == 'U' && flag == 1)
			{

				flag = n;
				for (int j = 0; j < 4; j++)
				{
					vec[4 - j - 1] = n - j;
				}
			}
			else if (s[i] == 'U')
			{
				if (flag == vec[0])
				{
					for (int j = 0; j < 4; j++)
					{
						vec[j] -= 1;
					}
				}
				flag--;
			}
			else if (s[i] == 'D' && flag == n)
			{
				flag = 1;
				for (int j = 0; j < 4; j++)
				{
					vec[j] = 1 + j;
				}
			}
			else if (s[i] == 'D')
			{
				if (flag == vec[3])
				{
					for (int j = 0; j < 4; j++)
					{
						vec[j] += 1;
					}
				}
				flag++;
			}

		}

		for (int i = 0; i < 3; i++)
		{
			cout << vec[i] << " ";
		}
		cout << vec[3] << endl;
		cout << flag << endl;
	
	}
	return 0;
}
