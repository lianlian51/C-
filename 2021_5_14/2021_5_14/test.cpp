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
	std::string Fruits[] = { "son", "son", "mom", "mom", "dad", "dad", "sister", "brother", "grandfather", "grandfather", "grandfather", "grandfather", "grandmonther", "grandmonther", "dad", "dad", "dad", "son", "grandson" };

	// 使用map统计英文单词的个数
	std::map<std::string, size_t> m;
	for (auto& e : Fruits)
		++m[e];

	// 建立大顶堆，找到前三个个数最多的英文单词
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

	while (!p.empty())
	{
		std::cout << p.top().first << std::endl;
		p.pop();
	}
#if 0
	// 将堆中的元素放在数组中
	std::vector<std::string> vec;
	while(!p.empty())
	{
		vec.push_back(p.top().first);
		p.pop();
	}

	// 打印出出现次数最多的单词
	for (int i = 0; i < 3; ++i)
	{
		std::cout << vec[i] << std::endl;
	}

#endif
}


int main()
{
	TestMap();
	return 0;
}