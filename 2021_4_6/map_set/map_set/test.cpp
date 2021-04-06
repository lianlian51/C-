#include <iostream>
using namespace std;


#if 0
#include <map>
#include <string>

void TestMap1()
{
	map<int, string> m1;
	// c++11列表构造
	map<string, string> m2{ { "orange", "juzi" }, { "apple", "pinguo" } };

	// 迭代器
	auto it = m2.begin();
	while (it != m2.end())
	{
		cout << "[" << (*it).first << "," << it->second << "]" << endl;
		++it;
	}
	// 反向迭代器和范围for都可以
}

void TestMap2()
{
	map<string, string> m;
	// 插入元素
	m.insert(pair<string, string>("orange", "juzi"));
	m.insert(make_pair("apple", "pingguo"));

	auto ret = m.insert(make_pair("peach", "taozi"));
	// ret:<iterator, bool>
	cout << ret.second << endl;
	cout << (*(ret.first)).first << endl;
	cout << (*(ret.first)).second << endl;

	cout << m.size() << endl;
	cout << m["apple"] << endl;
	m["banana"] = "xiangjiao";
	cout << m["banana"] << endl;

	cout << m.erase("apple") << endl;
}
#endif

#if 0
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <string>

class Com
{
public:
	bool operator()(const pair<string, size_t>&left, const pair<string, size_t>& right)
	{
		return left.second > right.second;
	}
};

void TestMap3()
{
	string Fruits[] = { "p", "p", "p", "p", "p", "x", "x", "x", "x", "q", "q", "a", "a", "a" };
	map<string, size_t> m;
	for (auto& e : Fruits)
		m[e]++;
	// 通过优先级队列找到top-k
	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Com> p;

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
	set<string> Vret;
	while (!p.empty())
	{
		Vret.insert(p.top().first);
		p.pop();
	}

	for (auto & e : Vret)
	{
		cout << e << " ";
	}
	cout << endl;
}
#endif


// set:去重+排序
#include <set>
void TestSet()
{
	int array[] = { 1, 2, 3, 4, 5, 0, 9, 8, 7, 6, 9, 7, 5, 3, 1, 2, 4, 6, 8, 0 };
	// set<int> s;
	// for(auto e : array)
	//    s.insert(e);

	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
	cout << s.size() << endl;

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = s.find(5);
	if (it != s.end())
		s.erase(it);

	s.erase(0);

	for (auto e : s)
		cout << e << " ";
	cout << endl;

	s.clear();
	cout << s.size() << endl;
}

void TestMultiset()
{
	int array[] = { 1, 2, 3, 4, 5, 0, 9, 8, 7, 6, 9, 7, 5, 3, 1, 2, 4, 6, 8, 0 };
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	cout << s.size() << endl;

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = s.find(5);
	if (it != s.end())
		s.erase(it);   

	s.erase(0);   

	for (auto e : s)
		cout << e << " ";
	cout << endl;

	s.clear();
	cout << s.empty() << endl;
}




int main()
{
	//TestMap2();
	// TestMap3();
	// TestSet();
	TestMultiset();
	return 0;
}
