#ifndef _COMMON_H_
#define  _COMMON_H_

// 用到的头文件
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#define ElemType int
#include <vld.h> // 用于内存泄漏
#pragma warning(disable :4996)

#endif

/////////////////////////////////////////
#ifndef _SLIST_H_
#define _SLIST_H_


#include "Common.h"
typedef struct SListNode
{
	ElemType data;
	struct SListNode* next;
}SListNode;

// 不带头结点的单链表
typedef SListNode* SList;

void SListInit(SList* phead);
void SListPushBack(SList* phead,ElemType x);
void SListPushFront(SList* phead, ElemType x);
void SListNodeShow(SList* phead);
size_t SListLength(SList* phead);

void SListNodePopBack(SList* phead);
void SListNodePopFront(SList* phead);

SListNode* SListFind(SList* phead, ElemType x);
void SListEraseVal(SList* phead, ElemType x);
void SListSort(SList* phead);
void SListByVal(SList* phead, ElemType x);

int SListFront(SList phead);
int SListBack(SList phead);
void SListEraseValAll(SList* phead, ElemType x);
void SListClear(SList* phead);
void SlistDestory(SList * phead);
void SListReverse(SList* phead);
///////////////////////////////////////////////
void SListInit(SList* phead)
{
	assert(*phead != NULL);
	*phead = NULL;
}

void SListPushBack(SList* phead, ElemType x)
{
	assert(phead != NULL);
	SListNode * s = (SListNode*)malloc(sizeof(SListNode));
	s->data = x;
	s->next = NULL;

	SListNode* p = *phead;
	if (p == NULL)
		*phead = s;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = s;
	}
}

void SListNodeShow(SList phead)
{
	assert(phead != NULL);
	SListNode* s = phead;
	while (s != NULL)
	{
		printf("%d->", s->data);
		s = s->next;
	}
	printf("NULL\n");
}

void SListPushFront(SList* phead, ElemType x)
{
	assert(phead != NULL);
	SListNode * s = (SListNode*)malloc(sizeof(SListNode));
	s->data = x;
	s->next = *phead;

	*phead = s;
}

size_t SListLength(SList* phead)
{
	assert(phead != NULL);
	size_t count = 0;
	SListNode* p = *phead;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

void SListNodePopBack(SList* phead)
{
	//assert(phead != NULL);
	SListNode* p = *phead;
	SListNode* prev = NULL;
	if (p != NULL)
	{
		while (p->next != NULL)
		{
			prev = p;
			p = p->next;
		}
	
		if (prev == NULL)
			*phead = NULL;
		else
			prev->next = NULL;
		free(p);
	}
}

void SListNodePopFront(SList* phead)
{
	assert(phead != NULL);
	SListNode* DesNode = *phead;

	if (DesNode != NULL)
	{
		*phead = (*phead)->next;
		free(DesNode);
	}
}

SListNode* SListFind(SList* phead,ElemType x)
{
#if 0
	assert(phead != NULL);
	SListNode* p = *phead;
	if (p != NULL)
	{
		while (p != NULL)
		{
			if (p->data == x)
				return p;
			p = p->next;
		}
	}
	return NULL;
#endif

	SListNode* p = *phead;
	while (p != NULL && p->data != x)
		p = p->next;
	return p;
}

void SListEraseVal(SList* phead, ElemType x)
{
	assert(phead != NULL);
	SListNode* p = SListFind(phead, x);

	if (p == NULL)
		return ;

	if (p->next == NULL)
		SListNodePopBack(phead);
	else
	{
		SListNode* q = p->next;
		p->data = q->data;
		p->next = q->next;
		free(q);
	}
}

// 注意
void SListSort(SList* phead)
{
	assert(phead != NULL);
	if (SListLength(phead) <= 1)
		return;

	SListNode * tmp = *phead, *prev = NULL;
	SListNode* p = *phead;
	SListNode* q = p->next ;
	p->next = NULL;

	while (q != NULL)
	{
		p = q;
		q = q->next;

		while (tmp != NULL && p->data > tmp->data)
		{
			prev = tmp;
			tmp = tmp->next;
		}

		if (prev == NULL)
		{
			p->next = *phead;
			*phead = p;
		}
		else
		{
			p->next = prev->next;
			prev->next = p;
		}
		tmp = *phead;
		prev = NULL;
	}
}

void SListByVal(SList* phead, ElemType x)
{
	assert(phead != NULL);
	SListNode *p = *phead;
	SListNode* prev = NULL;
	while (p != NULL && p->data < x)
	{
		prev = p;
		p = p->next;
	}

	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL); // 保证s申请成功

	s->data = x;
	
	if (prev == NULL)
	{
		s->next = p;
		*phead = s;
	}
	else
	{
		s->next = prev->next;
		prev->next = s;
	}
}

int SListFront(SList phead)
{
	assert(phead != NULL);
	return phead->data;
}

int SListBack(SList phead)
{
	assert(phead != NULL);
	SListNode *p = phead;
	while (p->next  != NULL)
		p = p->next;
	return p->data;
}


void SListEraseValAll(SList* phead, ElemType x)
{
	assert(phead != NULL);
	SListNode* p = *phead, *prev = NULL;

	while (p != NULL)
	{
		while (p != NULL &&p->data != x)
		{
			prev = p;
			p = p->next;
		}

		if (p->data == x && p == *phead)
		{
			*phead = p->next;
			free(p);
			p = *phead;
		}

		if (p->data == x)
		{
			prev->next = p->next;
			free(p);
			p = prev->next;
		}
	}
}

void SListClear(SList* phead)
{
	assert(phead != NULL);
	SListNode* p = NULL;
	while (*phead != NULL)
	{
		p = *phead;
		*phead = (*phead)->next;
		free(p);
	}
}

void SlistDestory(SList * phead)
{
	SListClear(phead);
}

void SListReverse(SList* phead)
{
	assert(phead != NULL);
	SListNode* p = *phead, *q = p->next;
	(*phead)->next = NULL;

	while (q != NULL)
	{
		p = q;
		q = q->next;

		p->next = *phead;
		*phead = p;
	}
}

#endif
///////////////////////////////////////////////
#include "SList.h"
#pragma warning(disable :4996)

int main()
{
	SList list;
	SListInit(&list);
	SListNode* p;

	ElemType item;
	int pos;
	int select = 1;
	bool flag = true;
	// 棋盘
	while (select)
	{
		printf("********************************************\n");
		printf("**** [1] push_back      [2] push_front  ****\n");
		printf("**** [3] show_list      [0] quit_system ****\n");
		printf("**** [4] pop_back       [5] pop_front   ****\n");
		printf("**** [6] insert_pos     [7] insert_val  ****\n");
		printf("**** [8] erase_pos      [9] erase_val   ****\n");
		printf("**** [10] find          [11] length     ****\n");
		printf("**** [12] capcity       [13] sort       ****\n");
		printf("**** [14] reverse       [15] clear      ****\n");
		printf("**** [16] front         [17] back       ****\n");
		printf("**** [18] binary_find   [19] erase_all  ****\n");
		printf("********************************************\n");
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
				SListPushBack(&list, item);
			}
			printf("头部插入成功......\n");
			break;
		case 2:
			printf("请输入你要插入的数字<以-1结束>:");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&list, item);
			}
			printf("尾部插入成功......\n");
			break;
		case 3:
			SListNodeShow(list);
			break;
		case 4:
			SListNodePopBack(&list);
			printf("尾部删除成功......\n");
			break;
		case 5:
			SListNodePopFront(&list);
			printf("头部删除成功......\n");
			break;
		case 6:
			printf("请输入要插入的位置：>");
			scanf("%d", &pos);
			printf("清输入要插入的数字：>");
			scanf("%d", &item);
			//flag = SeqListInsertByPos(&list, pos, item);
			//if (flag)
				printf("插入数据成功......\n");
			//else
				printf("插入数据失败......\n");
			break;
		case 7:
			printf("请输入需要插入的数字：>");
			scanf("%d", &item);
			SListSort(&list);
			SListByVal(&list,item);
			printf("任意位置的插入成功......\n");
			break;
		case 8:
			printf("请输入你要删除的位置：>");
			scanf("%d", &pos);
			//flag = SeqListEraseByPos(&list, pos);
			if (flag)
				printf("删除自定位置元素成功......\n");
			else
				printf("删除自定位置元素失败......\n");
			break;
		case 9:
			printf("请输入要删除的元素：>");
			scanf("%d", &item);
			SListEraseVal(&list, item);
			printf("删除指定元素成功......\n");
			break;
		case 10:
			printf("请输入要查找的数字：>");
			scanf("%d", &item);
			p = SListFind(&list, item);
			if (p == NULL)
				printf("查找失败.....\n");
			else
				printf("查找成功.....\n");
			break;
		case 11:
			printf("Slist length = %d\n", SListLength(&list));
			break;
		case 12:
			//printf("SeqList capacity = %d\n",SeqListCapacity(&list));
			break;
		case 13:
			SListSort(&list);
			printf("顺序表排序成功.....\n");
			break;
		case 14:
			SListReverse(&list);
			printf("转置成功......\n");
			break;
		case 15:
			SListClear(&list);
			break;
		case 16:
			printf("表头元素为：%d\n", SListFront(list));
			break;
		case 17:
			printf("表尾元素为：%d\n", SListBack(list));
			break;
		case 19:
			printf("请输入要删除的元素：>");
			scanf("%d", &item);
			SListEraseValAll(&list, item);
			printf("删除指定元素成功......\n");
			break;
		default :
			printf("输入错误，请重新出入......\n");
			break;
		}
	}
	SlistDestory(&list);

	return 0;
}
