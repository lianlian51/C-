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
	map<string, string> m2{ { "orange", "����" }, { "apple", "ƻ��" }, { "peach", "����" } };

	auto it = m2.begin();
	while (it != m2.end())
	{
		cout << "[" << (*it).first << (*it).second << endl;
		++it;
	}

	cout << endl;


	// ���������
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
	m.insert(pair<string, string>("orange", "����"));
	m.insert(make_pair("apple", "ƻ��"));

	auto ret = m.insert(make_pair("peach", "����"));
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
	string Fruits[] = { "ƻ��", "ƻ��", "�㽶", "�㽶", "����", "����", "����", "����", "�Ժ���", "�Ժ���", "�Ժ���", "�Ժ���", "Ѽ��", "Ѽ��", "����", "����", "����", "ƻ��", "��ݮ" };

	map<string, size_t> m;
	for (auto& e : Fruits)
		m[e]++;

	// ����priority_queue��top-k
	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Com> p;

	// �����Ҫǰk������Ԫ�أ�Ӧ�ý���һ��С��
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

	// λ��ɾ��
	auto it = s.find(5);
	if (it != s.end())
		s.erase(it);

	// ����ɾ��
	s.erase(0);

	// ��Χfor��ӡ

	s.clear();

	cout << s.empty << endl;
}

// ����multisetҲ��һ���ģ�����multiset�����ظ�
// set��multiset���Ǽ�ֵ�ԣ�����multiset�����ظ�

int main()
{
	TestSet();
	return 0;
}