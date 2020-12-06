////#include <iostream>
////#include <vector>
////using namespace std;
////
////int main()
////{
////	int A, B, C;
////
////	A = 105 - 3 * B;
////	C = 2 * B;
////
////	int ret = A + B + C;
////	printf("A+B+C: %d\n", ret);
////	return 0;
////}
//
//
//#include <iostream>
//using namespace std;
//#include <string>
//#include <vector>
//
//vector<string> v({"IV", "IX", "XL","XC","CD","CM"});
//
//int main()
//{
//	string s;
//	cin >> s;
//	int num = 0;
//	int flag = 0;
//	for (int i = 0; i < v.size(); i++)
//	{
//		flag = 1;
//		if (s == v[0])
//			num = 4;
//		else if (s == v[1])
//			num = 9;
//		else if (s == v[2])
//			num = 50;
//		else if (s == v[3])
//			num = 90;
//		else if (s == v[4])
//			num = 400;
//		else if (s == v[5])
//			num = 900;
//	}
//	if (flag == 1)
//		goto key;
//	int len = s.size();
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] == 'I')
//			num += 1;
//		else if (s[i] == 'V')
//			num += 5;
//		else if (s[i] == 'X')
//			num += 10;
//		else if (s[i] == 'L')
//			num += 50;
//		else if (s[i] == 'C')
//			num += 100;
//		else if (s[i] == 'D')
//			num += 500;
//		else if (s[i] == 'M')
//			num += 1000;
//	}
//	key:
//	cout << num << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//#include <vector>
//#include <algorithm>
//
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	if (n < k)
//	{
//		cout << "NO RESULT" << endl;
//		return 0;
//	}
//
//	vector<int> v;
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		v.push_back(temp);
//	}
//
//	sort(v.begin(), v.end());
//
//	int i = 0;
//	while (i < v.size() && k > 1)
//	{
//		if (v[i] != v[i + 1])
//		{
//			k--;
//		}
//	}
//	cout << v[i] << endl;
//}


//#include <iostream>
//using namespace std;
//
//int count(int num)
//{
//	if (num == 0)
//		return 1;
//	int n = num;
//	while (n)
//	{
//		int a = n % 10;
//		n /= 10;
//		if (a == 2 || a == 4)
//		{
//			return 0;
//		}
//	}
//	return count(n - 1);
//}
//
//int main()
//{
//	int num;
//	cin >> num;
//	int ret = count(num);
//	cout << ret << endl;
//	return 0;
//}


#include <iostream>
using namespace std;

int main()
{
	return 0;
}