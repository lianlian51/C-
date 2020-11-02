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
	int key = array[ret];//��׼ֵ
	Swap(&array[ret], &array[right - 1]);

	while (begin < end)
	{
		//��ͷ��ʼ����key��ֵ��λ��
		while (begin < end && array[begin] <= key)
			begin++;

		//�����ֵ���׼ֵ��λ��
		if (begin < end)
		{
			array[end--] = array[begin];//�����endһ��Ҫ��ǰ��һ��
		}

		//��β��ʼ����key��ֵ��λ��
		while (begin < end && array[end] >= key)
			end--;

		//�����begin��λ��
		if (begin < end)
		{
			array[begin++] = array[end];
		}
	}
	//����׼ֵ��д��begin��λ�ã���ʱ��begin��end��λ����һ���ģ�
	array[begin] = key;

	return begin;
}


int Partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	//���û�׼ֵ��ȡ�������Ҳ��Ԫ��
	int key = array[end];

	while (begin < end)
	{
		//Ѱ�Ҵ��ڻ�׼ֵ����
		while (begin < end && array[begin] <= key)
			begin++;

		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
			Swap(&array[begin], &array[end]);
	}

	//���ｫ��׼ֵ��begin��end������
	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);

	return begin;//��ʱӦ�÷���begin��keyֻ��ֵ���������±������
}

//����
void QuickSort(int* array, int left, int right)
{
	//right-left>1˵���м����Ԫ��
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

//��ֵȡ�з�
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