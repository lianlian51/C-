#include <iostream>
#include <vector>
using namespace std;
#include <string>
#include <queue>

#if 0
#include <map>
void TestMap1()
{
	map<int, string> m1;
	map<string, string> m2{ { "orange", "橘子" }, { "apple", "苹果" }, { "peach", "梨子" } };

	auto it = m2.begin();
	while (it != m2.end())
	{
		cout << "[" << (*it).first << (*it).second << endl;
		++it;
	}

	cout << endl;


	// 反向迭代器
	auto rit = m2.rbegin();
	while (rit != m2.rend())
	{
		cout << "[" << rit->first << (*rit).second << endl;
		++rit;
	}
	cout << endl;

	//for (auto & e : m2)
	//{

	//}
}

void TestMap2()
{
	map<string, string> m;
	m.insert(pair<string, string>("orange", "橘子"));
	m.insert(make_pair("apple", "苹果"));

	auto ret = m.insert(make_pair("peach", "桃子"));
	// ret: <iterator, bool>
	cout << ret.second << endl;
	cout << (*(ret.first)).first << endl;
	cout << (*(ret.first)).second << endl;

	cout << m.size() << endl;

	cout << m["apple"] << endl;
}


int main()
{
	TestMap2();
	return 0;
}

#endif

#if 0
#include <set>
#include <map>

class Com
{
public:
	bool operator()(const pair<string, size_t>& left, const pair<string, size_t>& right)
	{
		return left.second > right.second;
	}
};

void TestMap3()
{
	string Fruits[] = { "苹果", "苹果", "香蕉", "香蕉", "辣条", "辣条", "橘子", "西瓜", "迷糊桃", "迷糊桃", "迷糊桃", "迷糊桃", "鸭梨", "鸭梨", "辣条", "辣条", "辣条", "苹果", "草莓" };

	map<string, size_t> m;
	for (auto& e : Fruits)
		m[e]++;

	// 利用priority_queue找top-k
	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Com> p;

	// 如果需要前k个最大的元素，应该建立一个小堆
	int k = 0;
	for (auto& e : m)
	{
		if (k < 3)
		{
			p.push(e);
			k++;
		}
		else
		{
			if (e.second > p.top().second)
			{
				p.pop();
				p.push(e);
			}
		}
	}
	
	set<string> vRet;
	while (!p.empty())
	{
		vRet.insert(p.top().first);
		p.pop();
	}
	for (auto& e : vRet)
	{
		cout << e << " ";
	}
	cout << endl;
}

#endif

#include <set>
void TestSet()
{
	int array[] = { 1, 2, 3, 4, 5, 0, 9, 8, 7, 6, 9, 7, 5, 3, 1, 2, 4, 6, 8, 0 };

	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
	cout << s.size() << endl;

	// 位置删除
	auto it = s.find(5);
	if (it != s.end())
		s.erase(it);

	// 数字删除
	s.erase(0);

	// 范围for打印

	s.clear();

	cout << s.empty << endl;
}

// 测试multiset也是一样的，不过multiset可以重复
// set和multiset都是键值对，不过multiset可以重复

int main()
{
	TestSet();
	return 0;
}