#include <iostream>
using namespace std;
#include <vector>

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

// 冒泡排序
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

// 选择排序
void SelectSort(vector<int>& nums)
{
	int len = nums.size();
	for (int i = 0; i < len - 1; i++)
	{
		int maxPos = 0; // 找到的最大值的位置
		for (int j = 0; j < len - i; j++)
		{
			if (nums[j] > nums[maxPos])
				maxPos = j;

		}

		if (maxPos != len - 1 - i)
			swap(nums[len - i - 1], nums[maxPos]);	
	}
}


// 插入排序
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


// 希尔排序
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

// 归并排序
void MergeData(int *nums, int left, int mid, int right, int* temp)
{
	// 先将数组分为两个部分，一个从头开始，一个从中间开始
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;

	// index表示temp的下标
	int index = left;

	// 循环将小的放到temp中
	while (begin1 < end1 && begin2 < end2)
	{
		if (nums[begin1] > nums[begin2])
			temp[index++] = nums[begin2++];
		else
			temp[index++] = nums[begin1++];
	}

	// 处理还没有排序的数字
	while (begin1 < end1)
		temp[index++] = nums[begin1++];

	while (begin2 < end2)
		temp[index++] = nums[begin2++];
}


void _MergeSort(int* nums, int left, int right, int* temp)
{
	int mid = left + ((right - left) >> 1);
	// 采用递归的方式
	if (right - left > 1)
	{
		_MergeSort(nums, left, mid, temp);
		_MergeSort(nums, mid, right, temp);
		MergeData(nums, left, mid, right, temp);
		// 这里一定要加上left，因为你排了左边，还有右边要排，右边的下标也得加上left
		memcpy(nums + left, temp + left, (right - left)*sizeof(nums[0]));
	}
}

void MergeSort(int* nums, int size)
{
	// 开辟一个辅助空间	
	int* temp = (int*)malloc(sizeof(nums[0] * size));

	// 空间检测是否开辟成功
	if (NULL == temp)
	{
		assert(0);
		return;
	}

	_MergeSort(nums, 0, size, temp);
	//free(temp);
}


// 堆排序
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

// 堆排序
void HeapSort(vector<int>& nums)
{
	int len = nums.size();
	// 从最后一个非叶子节点开始向上调整
	for (int i = len / 2 - 1; i >= 0; --i)
	{
		Adjust(nums, len, i);
	}

	// 调整大堆
	for (int i = len - 1; i >= 1; --i)
	{
		swap(nums[0], nums[i]);
		// 调整违反堆性质的区域
		Adjust(nums, i, 0);
	}
}

// 计数排序
void countSort(int* nums, int size)
{
	// 1.找到最大的值
	int max = nums[0];
	for (int i = 0; i < size; ++i)
	{
		if (nums[i] > max)
			max = nums[i];
	}

	// 2.确定数组的长度并进行初始化
	int* countData = new int[max + 1];
	for (int i = 0; i <= max; ++i)
	{
		countData[i] = 0;
	}

	// 3.遍历数组，统计每个数字的次数
	for (int i = 0; i < size; ++i)
		++countData[nums[i]];

	// 4.累计输出数字
	int index = 0;
	for (int i = 0; i <= max; ++i)
	{
		for (int j = 0; j < countData[i]; ++j)
		{
			nums[index++] = i;
		}
	}
}

// 桶排序
void bucketSort(int nums[], int size)
{
	int i, j;
	int buckets[105];

	for (i = 0; i < 105; ++i)
	{
		buckets[i] = 0;
	}
	for (i = 0; i < size; ++i)
	{
		++buckets[nums[i]];
	}

	for (i = 0, j = 0; i < 105; ++i)
	{
		while (buckets[i] > 0)
		{
			nums[j++] = i;
			--buckets[i];
		}
	}
}

// 基数排序
int maxbit(int data[], int n)
{
	int d = 1; //保存最大的位数
	int p = 10;
	for (int i = 0; i < n; ++i)
	{
		while (data[i] >= p)
		{
			p *= 10;
			++d;
		}
	}
	return d;
}

void radixsort(int data[], int n) //基数排序
{
	int d = maxbit(data, n);
	int tmp[n];
	int count[10]; //计数器
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //进行d次排序
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器
		for (j = 0; j < n; j++)
		{
			k = (data[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
		for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
		{
			k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //将临时数组的内容复制到data中
			data[j] = tmp[j];
		radix = radix * 10;
	}
}





void TestSort()
{
	vector<int> nums{ 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int nums2[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };

	cout << "原始数组：";
	for (auto e : nums)
		cout << e << " ";
	cout << endl;

	//cout << "冒泡排序：";
	//BubbleSort(nums);
	//for (auto  e: nums)
	//	cout << e << " ";
	//cout << endl;

	//cout << "选择排序：";
	//SelectSort(nums);
	//for (auto e : nums)
	//	cout << e << " ";
	//cout << endl;

	//cout << "插入排序：";
	//InsertSort(nums);
	//for (auto e : nums)
	//	cout << e << " ";
	//cout << endl;

	//cout << "希尔排序：";
	//ShellSort(nums);
	//for (auto e : nums)
	//	cout << e << " ";
	//cout << endl;

	//cout << "归并排序：";
	//MergeSort(nums2, sizeof(nums2)/sizeof(nums2[0]));
	//for (int i = 0; i < sizeof(nums2) / sizeof(nums2[0]); ++i)
	//	cout << nums2[i] << " ";
	//cout << endl;

	/*cout << "堆排序：";
	HeapSort(nums);
	for (auto e : nums)
		cout << e << " ";
	cout << endl;*/

	//cout << "计数排序：";
	//countSort(nums2, sizeof(nums2) / sizeof(nums2[0]));
	//for (int i = 0; i < sizeof(nums2) / sizeof(nums2[0]); ++i)
	//	cout << nums2[i] << " ";
	//cout << endl;

	cout << "桶排序：";
	bucketSort(nums2, sizeof(nums2) / sizeof(nums2[0]));
	for (int i = 0; i < sizeof(nums2) / sizeof(nums2[0]); ++i)
		cout << nums2[i] << " ";
	cout << endl;
}

int main()
{
	TestSort();
	return 0;
}