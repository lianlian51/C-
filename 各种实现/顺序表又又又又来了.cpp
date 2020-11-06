#ifndef _COMMON_H_
#define  _COMMON_H_

// 用到的头文件
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include <vld.h> // 用于内存泄漏
#pragma warning(disable :4996)

#endif
/////////////////////////////////////////


#include "Seqlist.h"
#pragma warning(disable :4996)

int main()
{
	SeqList list;
	SeqListInit(&list);

	ElemType item;
	int pos;
	int select = 1;
	bool flag;
	// 棋盘
	while (select)
	{
		printf("***************************************\n");
		printf("**** [1] push_back  [2] push_front ****\n");
		printf("**** [3] show_list  [0] quit       ****\n");
		printf("**** [4] pop_back   [5] pop_front  ****\n");
		printf("**** [6] insert_pos [7] insert_val ****\n");
		printf("**** [8] erase_pos  [9] erase_val  ****\n");
		printf("**** [10] find      [11] length    ****\n");
		printf("**** [12] capcity   [13] sort      ****\n");
		printf("**** [14] reverse   [15] clear     ****\n");
		printf("***************************************\n");
		printf("请选择：>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入你要插入的数字<以-1结束>:");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPush_back(&list, item);
			}
			printf("头部插入成功......\n");
			break;
		case 2:
			printf("请输入你要插入的数字<以-1结束>:");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPush_front(&list, item);
			}
			printf("尾部插入成功......\n");
			break;
		case 3:
			show_list(&list);
			break;
		case 4:
			SeqListPop_back(&list);
			printf("尾部删除成功......\n");
			break;
		case 5:
			SeqListPopFront(&list);
			printf("头部删除成功......\n");
			break;
		case 6:
			printf("请输入要插入的位置：>");
			scanf("%d", &pos);
			printf("清输入要插入的数字：>");
			scanf("%d", &item);
			flag = SeqListInsertByPos(&list, pos, item);
			if (flag)
				printf("插入数据成功......\n");
			else
				printf("插入数据失败......\n");
			break;
		case 7:
			printf("请输入需要插入的数字：>");
			scanf("%d", &item);
			SeqListSort(&list);
			flag = SeqListInsertByVal(&list, item);
			if (flag)
				printf("任意位置的插入成功......\n");
			else
				printf("任意位置的插入失败......\n");
			break;
		case 8:
			printf("请输入你要删除的位置：>");
			scanf("%d", &pos);
			flag = SeqListEraseByPos(&list, pos);
			if (flag)
				printf("删除自定位置元素成功......\n");
			else
				printf("删除自定位置元素失败......\n");
			break;
		case 9:
			printf("请输入要删除的元素：>");
			scanf("%d", &item);
			flag = SeqListEraseVal(&list, item);
			if (flag)
				printf("删除指定元素成功......\n");
			else
				printf("删除指定元素失败......\n");
			break;
		case 10:
			printf("请输入要查找的数字：>");
			scanf("%d", &item);
			flag = SeqListFind(&list, item);
			if (flag)
				printf("查找成功.....\n");
			else
				printf("查找失败.....\n");
			break;
		case 11:
			printf("Seqlist length = %d\n", SeqListLength(&list));
			break;
		case 12:
			printf("SeqList capacity = %d\n",SeqListCapacity(&list));
			break;
		case 13:
			SeqListSort(&list);
			printf("顺序表排序成功.....\n");
			break;
		case 15:
			SeqListClear(&list);
			break;
		default :
			printf("输入错误，请重新出入......\n");
			break;
		}
		system("pause");
		system("cls");
	}
	SeqlistDestory(&list);

	return 0;
}

///////////////////////////////////////////////
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "Common.h"

#define ElemType int
#define SEQLIST_DEFAULT_SIZE 8

// 顺序表
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;

// 用到的所有的函数
void SeqListInit(SeqList *plist);
void SeqlistDestory(SeqList *plist);
void SeqListPush_back(SeqList *plist, ElemType x);
void SeqListPush_front(SeqList *plist, ElemType x);
void show_list(SeqList *plist);

size_t SeqListLength(SeqList *plist);
void SeqListPop_back(SeqList *plist);
void SeqListClear(SeqList *plist);
bool SeqListInsertByPos(SeqList*plist, int pos, ElemType x);
void SeqListSort(SeqList* plist);
size_t SeqListCapacity(SeqList *plist);

void SeqListPopFront(SeqList* plist);
bool SeqListInsertByVal(SeqList* plist, ElemType x);
bool SeqListEraseByPos(SeqList* plist, int pos);
bool SeqListEraseVal(SeqList* plist, ElemType x);
bool SeqListFind(SeqList* plist,ElemType x);
/////////////////////////////////////////////////
// 判断是否满
bool ISFull(SeqList* plist)
{
	assert(plist != NULL);
	return plist->size >= plist->capacity;
}
// 判断是否为空
bool ISEmpty(SeqList* plist)
{
	assert(plist != NULL);
	return plist->size == 0;
}
// 初始化
void SeqListInit(SeqList *plist)
{
	plist->capacity = SEQLIST_DEFAULT_SIZE;
	plist->base = (ElemType*)malloc(sizeof(ElemType)*plist->capacity);
	plist->size = 0;
}
// 尾插
void SeqListPush_back(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (ISFull(plist))
	{
		printf("顺序表已满，%d 不能尾部插入\n", x);
	}
	plist->base[plist->size++] = x;
}
// 头插
void SeqListPush_front(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (ISFull(plist))
	{
		printf("顺序表已满，%d 不能头部插入\n", x);
	}

	// 这里的i需要大于0就行了
	for (int i = plist->size; i > 0; --i)
	{
		plist->base[i] = plist->base[i - 1]; // 前一个给后一个赋值数据
	}
	plist->base[0] = x;// 
	plist->size++; //没有size++
}
// 打印
void show_list(SeqList *plist)
{
	assert(plist != NULL);
	for (int i = 0; i < plist->size; ++i)
		printf("%d ", plist->base[i]);
	printf("\n");
}
// 毁灭棋盘
void SeqlistDestory(SeqList *plist)
{
	assert(plist != NULL);
	free(plist->base); // 先free释放
	plist->base = NULL;// 在置为空
	plist->capacity = plist->size = 0;
}
// 链表长度
size_t SeqListLength(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size;
}
// 尾删
void SeqListPop_back(SeqList *plist)
{
	assert(plist != NULL);
	// 判空
	if (ISEmpty(plist))
	{
		printf("顺序表为空，不能尾部删除\n");
	}
	plist->size--;
}
// 清空链表
void SeqListClear(SeqList *plist)
{
	assert(plist != NULL);
	plist->size = 0;
}
// 任意位置的插入
bool SeqListInsertByPos(SeqList*plist, int pos, ElemType x)
{
	assert(plist != NULL);
	if (ISFull(plist))
	{
		printf("顺序表已满，% 的不能插入在 %d 的位置", x, pos);
		return false;
	}

	if (pos < 0 || pos >plist->size)
	{
		printf("要插入的位置[%d]非法，%d 不能插入\n", pos, x);
	}

	for (int i = plist->size; i < pos; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[pos] = x;
	plist->size ++; // 要size++
	return true;
}
// 排序
void SeqListSort(SeqList* plist)
{
	for (size_t i = 0; i < plist->size; ++i)
	{
		for (size_t j = i + 1; j < plist->size; ++j)
		{
			if (plist->base[i] > plist->base[j])
			{
				int temp = plist->base[i];
				plist->base[i] = plist->base[j];
				plist->base[j] = temp;
			}
		}
	}
}
// 容量
size_t SeqListCapacity(SeqList *plist)
{
	assert(plist != NULL);
	return plist->capacity;
}
// 头删
void SeqListPopFront(SeqList* plist)
{
	assert(plist != NULL);
	assert(!ISEmpty(plist));

	for (size_t i = 0; i < plist->size; ++i)
		plist->base[i] = plist->base[i + 1];
	plist->size--;// 元素变动，需要++/--
}
// 按值插入
bool SeqListInsertByVal(SeqList* plist, ElemType x)
{
	assert(plist != NULL);
	if (ISFull(plist))
	{
		printf("顺序表已满，%d 不能插入......\n");
		return false;
	}
#if 0
	size_t pos = 0;
	while (pos < plist->size && x > plist->base[pos])
		pos++;
	
	for (size_t i = plist->size; i > pos; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[pos] = x;
	plist->size++;
#endif
	size_t end = plist->size - 1;
	while (end >= 0 && x < plist->base[end])
	{
		plist->base[end + 1] = plist->base[end];
		end--;
	}
	plist->base[end + 1] = x;
	plist->size++;
}
// 按位置删除
bool SeqListEraseByPos(SeqList* plist, int pos)
{
	assert(plist != NULL);
	if (ISFull(plist))
	{
		printf("顺序表已满，不能插入......\n");
		return false;
	}
	for (size_t i = pos; i < plist->size; ++i)
		plist->base[i] = plist->base[i + 1];
	plist->size--;
}
// 按值删除
bool SeqListEraseVal(SeqList* plist, ElemType x)
{
	assert(plist != NULL);
	if (ISEmpty(plist))
	{
		printf("顺序表为空，不能删除......\n");
		return false;
	}

	size_t pos = 0;
	while (pos < plist->size && plist->base[pos] != x)
		pos++;

	for (size_t i = pos; i < plist->size; ++i)
		plist->base[i] = plist->base[i + 1];
	plist->size--;
}
// 寻找元素
bool SeqListFind(SeqList* plist, ElemType x)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; ++i)
	{
		if (plist->base[i] == x)
		{
			printf("%d 已找到......\n",x);
			return true;
		}
	}
	return false;
}

#endif
