#include <iostream> 
using namespace std;

#include <vector>


void MergeData(vector<int> &vec, int left, int mid, int right, vector<int> &temp)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;

	int index = left;
	while (begin1 < end1&&begin2 <end2)
	{
		if (vec[begin1]>vec[begin2])
		{
			temp[index++] = vec[begin1++];
		}
		else
		{
			temp[index++] = vec[begin2++];
		}
	}
	while (begin1 < end1)
	{
		temp[index++] = vec[begin1++];
	}
	while (begin2 < end2)
	{
		temp[index++] = vec[begin2++];
	}
}

void MergeSort(vector<int>&vec, int left, int right, vector<int>&temp)
{
	int mid = left + ((right - left) >> 1);

	if (right - left > 1)
	{
		MergeSort(vec, left, mid, temp);
		MergeSort(vec, mid, right, temp);
		MergeData(vec, left, mid, right, temp);
		for (int i = left; i < right; ++i)
		{
			vec[i] = temp[i];
		}
	}
}
int main()
{
	vector<int> vec = { 8, 5, 6, 4, 2, 15, 77, 6, 9 };
	int len = vec.size();
	vector<int> temp(len);
	MergeSort(vec, 0, len, temp);
	for (int i = 0; i < len; i++)
	{
		cout << vec[i] << " ";
	}

	return 0;
}
