#include <iostream>
#include <map>
#include <string>

#if 0
int main()
{
	std::map<std::string, std::string> m;
	auto ret = m.insert(std::make_pair("a", "A"));
	std::cout << ret.second << std::endl;
	std::cout << (*ret.first).first << std::endl;
	std::cout << (*ret.first).second << std::endl;

	ret = m.insert(std::make_pair("a", "B"));
	std::cout << ret.second << std::endl;
	std::cout << (*ret.first).first << std::endl;
	std::cout << (*ret.first).second << std::endl;

	m["a"] = "C";
	std::cout << m["a"] << std::endl;

	m["b"] = "B";
	std::cout << m.erase("b") << std::endl;
	std::cout << m.erase("b") << std::endl;

	return 0;
}
#endif
#include <vector>
#include <queue>

class Com
{
public:
	bool operator()(const std::pair<std::string, size_t>& left, const std::pair<std::string, size_t>& right)
	{
		return left.second > right.second;
	}
};
void TestMap()
{
	std::string Fruits[] = { "Æ»¹û", "Æ»¹û", "Ïã½¶", "Ïã½¶", "À±Ìõ", "À±Ìõ", "éÙ×Ó", "Î÷¹Ï", "ÃÔºıÌÒ", "ÃÔºıÌÒ", "ÃÔºıÌÒ", "ÃÔºıÌÒ", "Ñ¼Àæ", "Ñ¼Àæ", "À±Ìõ", "À±Ìõ", "À±Ìõ", "Æ»¹û", "²İİ®" };

	std::map<std::string, size_t> m;
	for (auto& e : Fruits)
		++m[e];

	std::priority_queue<std::pair<std::string, size_t>, std::vector<std::pair<std::string, size_t>>, Com> p;
	int k = 0;
	for (auto& e : m)
	{
		if (k < 3)
		{
			k++;
			p.push(e);
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

	std::vector<std::string> vec;
	while(!p.empty())
	{
		vec.push_back(p.top().first);
		p.pop();
	}

	for (int i = 0; i < 3; ++i)
	{
		std::cout << vec[i] << std::endl;
	}
}


int main()
{
	TestMap();
	return 0;
}