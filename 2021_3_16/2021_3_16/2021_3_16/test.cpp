#include <iostream>
using namespace std;
#include <vector>

// √∞≈›≈≈–Ú
void BubbleSort(vector<int>& nums)
{
	int len = nums.size();
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (nums[j] > nums[j + 1])
			{
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}


// øÏÀŸ≈≈–Ú
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

int QuickSort1(int *array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = array[end];
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;

		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
			Swap(&array[begin], &array[end]);
	}
	if (begin != right - 1)
		Swap(&array[begin], &array[right-1]);
	return begin;
}

void QuickSort(int* array, int left, int right)
{
	if (right - left > 1)
	{
		int index = QuickSort1(array, left, right);
		QuickSort(array, left, index);
		QuickSort(array, index + 1, right);
	}
}

// ≤Â»Î≈≈–Ú
void InsertSort(vector<int>& nums)
{
	int i;
	int len = nums.size();
	for (i = 1; i < len; i++);
	{
		int key = nums[i];
		int index = i - 1;
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
	vector<int> nums{ 7, 9, 3, 2, 5, 6, 1, 4, 8 };
	

	//cout << "√∞≈›≈≈–Ú" << endl;
	//BubbleSort(nums);
	//for (auto e : nums)
	//	cout << e << " ";
	//cout << endl;

	int array[] = { 7, 9, 3, 2, 5, 6, 1, 4, 8 };

	// øÏÀŸ≈≈–Ú
	//cout << "øÏÀŸ≈≈–Ú" << endl;
	//QuickSort(array, 0, sizeof(array) / sizeof(array[0]));
	//int len = sizeof(array) / sizeof(array[0]);
	//for (int i = 0; i < len; ++i)
	//	cout << array[i] << " ";
	//cout << endl;

	cout << "≤Â»Î≈≈–Ú" << endl;
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


/*
#include <iostream>
#include <Windows.h>
#include <vector>
#include<algorithm>
using namespace  std;

int QuickPartition(vector<int>qic, int left, int right)
{
	int x = qic[left];
	int l = left;
	int r = right;
	while (l < r)
	{
		while (l<r&&qic[r] >= x)
		{
			r--;
		}
		while (l < r&&qic[l] <= x)
		{
			l++;
		}
		if (l < r)
		{
			swap(qic[r], qic[l]);
		}
	}
	if (left != r)
	{
		swap(qic[left], qic[r]);
	}

	return l;
}

void QuickSort(vector<int> qic, int left, int right)
{
	if (right - left > 1)
	{
		int div = QuickPartition(qic, left, right);
		QuickSort(qic, left, div);
		QuickSort(qic, div + 1, right);
	}
}

int main()
{
	vector<int> bub = { 5, 2, 6, 7, 8, 7, 1, 2, 3, 3 };
	QuickSort(bub, 0, bub.size() - 1);
	for (int i = 0; i < bub.size(); i++)
	{
		cout << bub[i] << " ";
	}
	system("pause");
	return 0;
}
*/