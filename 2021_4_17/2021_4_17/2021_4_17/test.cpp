//#include <iostream>
//using namespace std;
//#include <map>
//
//bool fncomp(char lhs, char rhs) { return lhs<rhs; }
//
//template<class T>
//struct classcomp
//{
//	bool operator() (const char& lhs, const char& rhs) const
//	{
//		return lhs<rhs;
//	}
//};
//
//int main()
//{
//	map<char, int> first;//默认升序 以key abcd 的顺序存储
//	first['a'] = 10;
//	first['b'] = 30;
//	first['d'] = 50;
//	first['c'] = 70;
//	//注意：map的下标操作，其行为与vector很不相同：使用一个不在容器中关键字作为下标，会添加一个具有此关键字的元素到map中。一般使用find函数代替下标操作。
//	map<char, int> second(first.begin(), first.end());
//
//	map<char, int> third(second);
//
//	map<char, int, classcomp<int>> fourth; // 降序 以key dcba的顺序存储
//	fourth['a'] = 10;
//	fourth['b'] = 30;
//	fourth['d'] = 50;
//	fourth['c'] = 70;
//
//	bool(*fn_pt)(char, char) = fncomp;
//	map<char, int, bool(*)(char, char)> fifth(fn_pt); // function pointer as Compare
//}
//
//
//#include <iostream>
//using namespace std;
//#include <string>
//
//int main()
//{
//	string s;
//	while (cin >> s){
//		int l = s.size();
//		int i = 0;
//		int ret = 0;
//		while (i < l){
//			if (i + 1 < l && s[i] == 'a' && s[i + 1] == 'b'){
//				string t1 = s.substr(0, i);
//				string t2 = s.substr(i + 2);
//				s = t1 + "bba" + t2;
//				i -= 2, ++ret;
//			}
//			l = s.size();
//			++i;
//			i = i < 0 ? 0 : i;
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//#include <map>
//#include <algorithm>
//#include <vector>
//
//int main()
//{
//	string s;
//	map<int, int> madd({ { 1, 100 }, { 2, 200 }, { 3, 360 }, { 4, 220 } });
//	map<int, int> msub({ { 1, 120 }, { 2, 350 }, { 3, 200 }, { 4, 320 } });
//	while (cin >> s){
//		int l = s.size();
//		int left = 0;
//		int right = l - 1;
//		int ret = 0;
//		while (left < right){
//			if (s[left] == s[right]){
//				++left, --right;
//			}
//			else{
//				int sl = s[left] - '0';
//				int sr = s[right] - '0';
//				int slr = min(sl, sr);
//				if (slr == 3){
//					ret += msub[slr];
//				}
//				else {
//					ret += madd[slr];
//				}
//
//				if (slr == sl){
//					++left;
//				}
//				else if (slr == sr){
//					--right;
//				}
//			}
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//#include <string>
//#include <map>
//#include <algorithm>
//#include <vector>
//
//int main()
//{
//	string s;
//	map<int, int> madd({ { 1, 100 }, { 2, 200 }, { 3, 360 }, { 4, 220 } });
//	map<int, int> msub({ { 1, 120 }, { 2, 350 }, { 3, 200 }, { 4, 320 } });
//	while (cin >> s){
//		int l = s.size();
//		int left = 0;
//		int right = l - 1;
//		int ret = 0;
//		while (left < right){
//			if (s[left] == s[right]){
//				++left, --right;
//			}
//			else{
//				int sl = s[left] - '0';
//				int sr = s[right] - '0';
//				if (sl == 3){
//					ret += msub[sl];
//					++left;
//					continue;
//				}
//				else if (sr == 3){
//					ret += msub[sr];
//					--right;
//					continue;
//				}
//				if (madd[sl] < madd[sr]){
//					ret += madd[sl];
//					++left;
//					continue;
//				}
//				else if (madd[sl] > madd[sr]){
//					ret += madd[sr];
//					--right;
//					continue;
//				}
//			}
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//#include <vector>
//#include <algorithm>
//
//int find(vector<int> v, int m)
//{
//	int l = v.size();
//	for (int i = 0; i < l; ++i){
//		if (m == v[i])
//			return i;
//	}
//	return -1;
//}
//
//int main()
//{
//	int n, m;
//	while (cin >> n >> m)
//	{
//		vector<int> v(n);
//		for (int i = 0; i < n; ++i){
//			cin >> v[i];
//		}
//		int mid = find(v, m);
//		int left = mid;
//		int right = mid;
//		int ret = 1;
//		while (left >= 0 && right < n)
//		{
//			--left, ++right;
//			int newleft = left;
//			int newright = right;
//			while (newleft >= 0 && newright < n){
//				vector<int> tmp;
//				for (int i = newleft; i <= newright; ++i){
//					tmp.push_back(v[i]);
//				}
//				int lt = tmp.size();
//				if (lt % 2 == 0)
//					continue;
//				sort(tmp.begin(), tmp.end());
//				if (tmp[lt / 2] == m){
//					ret++;
//				}
//				newleft--, newright++;
//			}
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}
//
////#endif
////
////#include <iostream>
////using namespace std;
////#include <string>
////
////string func1(string s1, string s2, int l)
////{
////	for (int i = 0; i < l; ++i){
////		if (s1[i] != s2[i])
////			return "NO";
////	}
////	return "YES";
////}
////
////string func2(string s1, string s2, int l)
////{
////	string tmp = "YES";
////	for (int i = 1; i < l - 1; ++i){
////		string s11 = s1.substr(0, i);
////		string s12 = s1.substr(i);
////		string s21 = s2.substr(0, i);
////		string s22 = s2.substr(i);
////		if (s11.size() == s12.size() && (s11 == s22 || s12 == s21)){
////			tmp = "YES";
////		}
////
////		if (s11 == s21 || s12 == s22)
////			tmp = "YES";
////	}
////	return tmp;
////}
////
////int main()
////{
////	int t;
////	cin >> t;
////	while (t--)
////	{
////		string s1, s2;
////		cin >> s1 >> s2;
////		int l = s1.size();
////		string flag;
////		if (l % 2 == 1){
////			// 奇数
////			flag = func1(s1, s2, l);
////		}
////		else {
////			// 偶数
////			 flag = func2(s1, s2, l);
////		}
////		cout << flag << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//#include <string>
//
//string func1(string s1, string s2, int l)
//{
//	for (int i = 0; i < l; ++i){
//		if (s1[i] != s2[i])
//			return "NO";
//	}
//	return "YES";
//}
//
//string func2(string s1, string s2, int l)
//{
//	string tmp = "NO";
//	for (int i = 1; i < l - 1; ++i){
//		string s11 = s1.substr(0, i);
//		string s12 = s1.substr(i);
//		string s21 = s2.substr(0, i);
//		string s22 = s2.substr(i);
//		if (s11.size() == s12.size() && (s11 == s22 && s12 == s21)){
//			return "YES";
//		}
//
//		if (s11 == s21 && s12 == s22)
//			tmp = "YES";
//	}
//	return tmp;
//}
//
//int main()
//{
//	int t;
//	while (t--)
//	{
//		string s1, s2;
//		cin >> s1 >> s2;
//		int l = s1.size();
//		string flag;
//		if (l % 2 == 1){
//			// 奇数
//			flag = func1(s1, s2, l);
//		}
//		else {
//			// 偶数
//			flag = func2(s1, s2, l);
//		}
//		cout << flag << endl;
//	}
//	return 0;
//}


#include <iostream>
using namespace std;
#include <string>

string func1(string s1, string s2, int l)
{
	for (int i = 0; i < l; ++i){
		if (s1[i] != s2[i])
			return "NO";
	}
	return "YES";
}

string func2(string s1, string s2, int l)
{
	string tmp = "NO";
	for (int i = 1; i < l - 1; ++i){
		string s11 = s1.substr(0, i);
		string s12 = s1.substr(i);
		string s21 = s2.substr(0, i);
		string s22 = s2.substr(i);
		if (s11.size() == s12.size() && (s11 == s22 && s12 == s21)){
			return "YES";
		}

		if (s11 == s21 && s12 == s22)
			tmp = "YES";
	}
	return tmp;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int l = s1.size();
		string flag;
		if (l % 2 == 1){
			// 奇数
			flag = func1(s1, s2, l);
		}
		else {
			// 偶数
			flag = func2(s1, s2, l);
		}
		cout << flag << endl;
	}
	return 0;
}