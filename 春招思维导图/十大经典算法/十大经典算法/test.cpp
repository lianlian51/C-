#include <iostream>
using namespace std;
#include <vector>

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

// ð������
void BubbleSort(vector<int> & nums)
{
	int len = nums.size();
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (nums[j] > nums[j + 1])
			{
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}

// ѡ������
void SelectSort(vector<int>& nums)
{
	int len = nums.size();
	for (int i = 0; i < len - 1; i++)
	{
		int maxPos = 0; // �ҵ������ֵ��λ��
		for (int j = 0; j < len - i; j++)
		{
			if (nums[j] > nums[maxPos])
				maxPos = j;

		}

		if (maxPos != len - 1 - i)
			swap(nums[len - i - 1], nums[maxPos]);	
	}
}


// ��������
void InsertSort(vector<int>& nums)
{
	int len = nums.size();
	for (int i = 1; i < len; ++i)
	{
		int tmp = nums[i];
		int end = i - 1;
		while (end >= 0 && tmp < nums[end])
		{
			nums[end + 1] = nums[end];
			end--;
		}
		nums[end + 1] = tmp;
	}
}


// ϣ������
void ShellSort(vector<int>& nums)
{
	int gap = 3;
	int len = nums.size();
	while (gap >= 1)
	{
		for (int i = gap; i < len; ++i)
		{
			int tmp = nums[i];
			int end = i - gap;
			while (end >= 0 && tmp < nums[end])
			{
				nums[end + gap] = nums[end];
				end -= gap;
			}
			nums[end + gap] = tmp;
		}
		gap--;
	}
}

// �鲢����
void MergeData(int *nums, int left, int mid, int right, int* temp)
{
	// �Ƚ������Ϊ�������֣�һ����ͷ��ʼ��һ�����м俪ʼ
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;

	// index��ʾtemp���±�
	int index = left;

	// ѭ����С�ķŵ�temp��
	while (begin1 < end1 && begin2 < end2)
	{
		if (nums[begin1] > nums[begin2])
			temp[index++] = nums[begin2++];
		else
			temp[index++] = nums[begin1++];
	}

	// ����û�����������
	while (begin1 < end1)
		temp[index++] = nums[begin1++];

	while (begin2 < end2)
		temp[index++] = nums[begin2++];
}


void _MergeSort(int* nums, int left, int right, int* temp)
{
	int mid = left + ((right - left) >> 1);
	// ���õݹ�ķ�ʽ
	if (right - left > 1)
	{
		_MergeSort(nums, left, mid, temp);
		_MergeSort(nums, mid, right, temp);
		MergeData(nums, left, mid, right, temp);
		// ����һ��Ҫ����left����Ϊ��������ߣ������ұ�Ҫ�ţ��ұߵ��±�Ҳ�ü���left
		memcpy(nums + left, temp + left, (right - left)*sizeof(nums[0]));
	}
}

void MergeSort(int* nums, int size)
{
	// ����һ�������ռ�	
	int* temp = (int*)malloc(sizeof(nums[0] * size));

	// �ռ����Ƿ񿪱ٳɹ�
	if (NULL == temp)
	{
		assert(0);
		return;
	}

	_MergeSort(nums, 0, size, temp);
	//free(temp);
}


// ������
void Adjust(vector<int> & nums, int len, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	int maxIdx = index;
	if (left < len && nums[left] > nums[maxIdx]) maxIdx = left;
	if (right < len && nums[right] > nums[maxIdx]) maxIdx = right;

	if (maxIdx != index)
	{
		swap(nums[maxIdx], nums[index]);
		Adjust(nums, len, maxIdx);
	}
}

void HeapSort(vector<int>& nums)
{
	int len = nums.size();
	// �����һ����Ҷ�ӽڵ㿪ʼ���ϵ���
	for (int i = len / 2 - 1; i >= 0; --i)
	{
		Adjust(nums, len, i);
	}

	// �������
	for (int i = len - 1; i >= 1; --i)
	{
		swap(nums[0], nums[i]);
		// ����Υ�������ʵ�����
		Adjust(nums, i, 0);
	}
}





void TestSort()
{
	vector<int> nums{ 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int nums2[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };

	cout << "ԭʼ���飺";
	for (auto e : nums)
		cout << e << " ";
	cout << endl;

	//cout << "ð������";
	//BubbleSort(nums);
	//for (auto  e: nums)
	//	cout << e << " ";
	//cout << endl;

	//cout << "ѡ������";
	//SelectSort(nums);
	//for (auto e : nums)
	//	cout << e << " ";
	//cout << endl;

	//cout << "��������";
	//InsertSort(nums);
	//for (auto e : nums)
	//	cout << e << " ";
	//cout << endl;

	//cout << "ϣ������";
	//ShellSort(nums);
	//for (auto e : nums)
	//	cout << e << " ";
	//cout << endl;

	//cout << "�鲢����";
	//MergeSort(nums2, sizeof(nums2)/sizeof(nums2[0]));
	//for (int i = 0; i < sizeof(nums2) / sizeof(nums2[0]); ++i)
	//	cout << nums2[i] << " ";
	//cout << endl;

	cout << "������";
	HeapSort(nums);
	for (auto e : nums)
		cout << e << " ";
	cout << endl;
}

int main()
{
	TestSort();
	return 0;
}