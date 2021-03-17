#include <iostream>
using namespace std;
#include <vector>


// ≤Â»Î
void InsertSort(vector<int>& nums)
{
	int len = nums.size();
	int index, key;
	for (int i = 1; i < len; ++i)
	{
		 index = i - 1;
		 key = nums[i];
		while (index >= 0 && key < nums[index])
		{
			nums[index + 1] = nums[index];
			index--;
		}
		nums[index + 1] = key;
	}
}

void TestSort()
{
	vector<int> nums{ 9, 2, 3, 5, 1, 7, 8, 6 };
	InsertSort(nums);
	for (auto e : nums)
		cout << e << " ";
	cout << endl;
}

int main()
{
	TestSort();
	return 0;
}