//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string str;
//	cin >> str;
//	string s = "";
//	int i = 0, max_len = 0, str_len = str.size();
//	while (i < str_len)
//	{
//		if (str[i] < '0' || str[i] > '9')
//			i++;
//		else
//		{
//			int count = 0;
//			string temp = "";
//
//			while ((str[i] >= '0' && str[i] <= '9') && i < str_len)
//			{
//				temp = temp + str[i];
//				count++;
//				i++;
//			}
//
//			if (count > max_len)
//			{
//				max_len = count;
//				s = temp;
//			}
//		}
//	}
//
//	cout << s << endl;
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;


int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	int count = 0;
	int num = 0;
	int len = numbers.size();
	for (int i = 0; i < len; i++)
	{
		if (count == 0)
		{
			num = numbers[i];
		}

		if (num == numbers[i])
			count++;
		else
			count--;
	}
	return num;
}


int main()
{
	vector<int> v{ 1, 2, 2, 1, 1, 2, 1 };
	int num = MoreThanHalfNum_Solution(v);
	cout << num << endl;
	return 0;
}