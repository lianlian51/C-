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
//	map<char, int> first;//Ĭ������ ��key abcd ��˳��洢
//	first['a'] = 10;
//	first['b'] = 30;
//	first['d'] = 50;
//	first['c'] = 70;
//	//ע�⣺map���±����������Ϊ��vector�ܲ���ͬ��ʹ��һ�����������йؼ�����Ϊ�±꣬�����һ�����д˹ؼ��ֵ�Ԫ�ص�map�С�һ��ʹ��find���������±������
//	map<char, int> second(first.begin(), first.end());
//
//	map<char, int> third(second);
//
//	map<char, int, classcomp<int>> fourth; // ���� ��key dcba��˳��洢
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


#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <algorithm>
#include <vector>

int main()
{
	string s;
	map<int, int> madd({ { 1, 100 }, { 2, 200 }, { 3, 360 }, { 4, 220 } });
	map<int, int> msub({ { 1, 120 }, { 2, 350 }, { 3, 200 }, { 4, 320 } });
	while (cin >> s){
		int l = s.size();
		int left = 0;
		int right = l - 1;
		int ret = 0;
		while (left < right){
			if (s[left] == s[right]){
				++left, --right;
			}
			else{
				int sl = s[left] - '0';
				int sr = s[right] - '0';
				if (sl == 3){
					ret += msub[sl];
					++left;
					continue;
				}
				else if (sr == 3){
					ret += msub[sr];
					--right;
					continue;
				}
				if (madd[sl] < madd[sr]){
					ret += madd[sl];
					++left;
					continue;
				}
				else if (madd[sl] > madd[sr]){
					ret += madd[sr];
					--right;
					continue;
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}