#pragma once
#include <stdio.h>

void Swap(int *left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

int Partion3(int* array, int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int key = array[right - 1];
	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			Swap(&array[cur], &array[prev]);

		cur++;
	}
	if (++prev != (right - 1))
		Swap(&array[prev], &array[right - 1]);

	return prev;
}

int Partion2(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int ret = GetIndexOfMid(array, left, right);
	int key = array[ret];//基准值
	Swap(&array[ret], &array[right - 1]);

	while (begin < end)
	{
		//从头开始大于key的值的位置
		while (begin < end && array[begin] <= key)
			begin++;

		//将这个值填到基准值的位置
		if (begin < end)
		{
			array[end--] = array[begin];//这里的end一定要往前走一步
		}

		//从尾开始大于key的值得位置
		while (begin < end && array[end] >= key)
			end--;

		//填坑在begin的位置
		if (begin < end)
		{
			array[begin++] = array[end];
		}
	}
	//将基准值填写到begin的位置（此时的begin和end的位置是一样的）
	array[begin] = key;

	return begin;
}


int Partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	//设置基准值，取数组最右侧的元素
	int key = array[end];

	while (begin < end)
	{
		//寻找大于基准值的数
		while (begin < end && array[begin] <= key)
			begin++;

		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
			Swap(&array[begin], &array[end]);
	}

	//这里将基准值和begin（end）交换
	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);

	return begin;//此时应该返回begin，key只是值（这里是下标操作）
}

//快排
void QuickSort(int* array, int left, int right)
{
	//right-left>1说明中间必有元素
	if (right - left > 1)
	{
		int div = Partion3(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

void Print(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

//三值取中法
int GetIndexOfMid(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] > array[right - 1])
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right;
		else
			return mid;
	}
	else
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right;
		else
			return mid;
	}
}