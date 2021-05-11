
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>


int getValue(vector<int> gifts, int n) {
	// write code here
	unordered_map<int, int> gift_map;
	for (int i = 0; i < n; ++i)
	{
		gift_map[gifts[i]]++;
	}
	for (auto gift : gift_map)
	{
		if (gift.second > n / 2)
			return gift.first;
	}
	return 0;
}



int main()
{
	std::vector<int> vec{ 1, 2, 3, 2, 2 };
	std::cout << getValue(vec, 5) << std::endl;
	return 0;
}