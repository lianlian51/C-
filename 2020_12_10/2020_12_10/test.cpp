//#include <iostream>
//using namespace std;
//#include <vector>
//#include <algorithm>
//
//bool PerfectNum(int n)
//{
//	vector<int> v;
//	v.resize(1, 0);
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//		{
//			v.push_back(i);
//			int temp = n / i;
//			v.push_back(temp);
//		}
//	}
//	int len = v.size();
//	int num = 0;
//	for (int i = 0; i < len; i++)
//	{
//		num += v[i];
//	}
//	if (num == n)
//		return true;
//	else
//		return false;
//}
//
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			if (PerfectNum(i))
//				count++;
//		}
//		if (count == 0)
//			cout << "-1" << endl;
//		else
//			cout << count << endl;
//	}
//	return 0;
//}

#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s("hel-bit");
	unsigned pos = s.find("-");
	string s1 = s.substr(0, pos);
	string s2 = s.substr(pos + 1, s.size());
	cout << s1 <<" " << s2 << endl;
	return 0;
}