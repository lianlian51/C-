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
////////////////////////////////////////////
#ifndef __DCLIST_H__
#define __DCLIST_H__
#include "Common.h"

typedef struct DCListNode
{
	ElemType data;
	DCListNode *prev;
	DCListNode *next;
}DCListNode;

typedef DCListNode* DCList;


void DCListInit(DCList *phead);
void DCListPushBack(DCList* phead, ElemType x);
void DCListNodeShow(DCList phead);
void DCListPushFront(DCList *phead, ElemType x);
void DCListNodePopBack(DCList* phead);
void DCListNodePopFront(DCList* phead);
void DCListByVal(DCList* phead,ElemType x);
void DCListEraseVal(DCList phead, ElemType x);
DCListNode* DCListFind(DCList phead,ElemType x);
size_t DCListLength(DCList phead);
void DCListSort(DCList phead);
void DCListReverse(DCList phead);
void DCListClear(DCList* phead);

size_t DCListFront(DCList phead);
size_t DCListBack(DCList phead);

void DCListDestory(DCList* phead);

//////////////////////////
DCListNode* DCListBuyNode(ElemType v = ElemType())
{
	DCListNode* _s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(_s != NULL);
	_s->data = v;
	_s->next = _s->prev = _s;
	return _s;
}

void DCListInit(DCList *phead)
{
	*phead = DCListBuyNode();
}

void DCListPushBack(DCList* phead, ElemType x)
{
	DCListNode* s = DCListBuyNode(x);
	DCListNode* head = *phead;

	s->prev = head->prev;
	s->next = head;
	head->prev->next = s;
	head->prev = s;
}

void DCListNodeShow(DCList phead)
{
	DCListNode* p = phead->next;
	while (p != phead)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void DCListPushFront(DCList *phead, ElemType x)
{
	DCListNode* s = DCListBuyNode(x);
	DCListNode* head = *phead;

	s->next = head->next;
	s->prev = head;
	head->next = s;
	s->next->prev = s;
}

void DCListNodePopBack(DCList* phead)
{
	assert(phead != NULL);
	DCListNode* p = (*phead)->prev;
	DCListNode* head = *phead;

	if (head->next == head)
		return;

	p->prev->next = head;
	head->prev = p->prev;

	free(p);
}


void DCListNodePopFront(DCList* phead)
{
	assert(phead != NULL);
	DCListNode* p = (*phead)->next;
	DCListNode* head = *phead;

	if (head->next == head)
		return;

	p->next->prev = head;
	head->next = p->next;

	free(p);
}

void DCListEraseVal(DCList phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode* p = DCListFind(phead, x);

	if (p == NULL)
		return;
	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);
}

DCListNode* DCListFind(DCList phead,ElemType x)
{
	DCListNode* p = phead->next;
	while (p != phead && p->data != x)
		p = p->next;

	if (p == phead)
		return NULL;
	return p;
}

size_t DCListLength(DCList phead)
{
	assert(phead != NULL);
	size_t count = 0;
	DCListNode* p = phead->next;
	while (p != phead)
	{
		count++;
		p = p->next;
	}
	return count;
}

size_t DCListFront(DCList phead)
{
	assert(phead != NULL);
	assert(phead->next != phead);
	return phead->next->data;
}
size_t DCListBack(DCList phead)
{
	assert(phead != NULL);
	assert(phead->next != phead);
	return phead->prev->data;
}


void DCListClear(DCList* phead)
{
	assert(phead != NULL);
	DCListNode* cur = (*phead)->next;
	DCListNode* head = *phead;

	while (cur != *phead)
	{
		DCListNode* prev = cur;
		cur = cur->next;
		free(prev);
	}
	head->prev = head->next = head;
}

void DCListDestory(DCList* phead)
{
	assert(phead != NULL);
	DCListClear(phead);
	free(*phead);
	*phead = NULL;
}

void DCListSort(DCList phead)
{
	assert(phead != NULL);
	if (DCListLength(phead) == 1)
		return;
	DCListNode* p = phead->next;
	DCListNode* q = p->next;

	p->next = phead;
	phead->prev = p;

	while (q != phead)
	{
		p = q;
		q = q->next;

		DCListNode* tmp = phead->next ;
		while (tmp != phead && p->data > tmp->data )
			tmp = tmp->next;

		p->prev = tmp->prev;
		p->next = tmp;
		p->prev->next = p;
		p->next->prev = p;
	}
}

void DCListByVal(DCList* phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode *s = DCListBuyNode(x);
	DCListNode* p = (*phead)->next;
	while (p != *phead && x > p->data)
		p = p->next;

	s->prev = p->prev;
	s->next = p;
	s->prev->next = s;
	s->next->prev = s; 
}

void DCListReverse(DCList phead)
{
	assert(phead != NULL);
	DCListNode* p = phead->next;
	DCListNode* q = p->next;

	p->next = phead;
	phead->prev = p;

	while (q != phead)
	{
		p = q;
		q = q->next;
		
		p->next = phead->next;
		p->prev = phead;
		p->prev->next = p;
		p->next->prev = p;
	}
}


#endif
/////////////////////////////////////////
#include "dclist.h"
#pragma warning(disable :4996)

int main()
{
	DCList list;
	DCListInit(&list);
	DCListNode* p = NULL;

	ElemType item;
	//int pos;
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
				DCListPushBack(&list, item);
			}
			printf("头部插入成功......\n");
			break;
		case 2:
			printf("请输入你要插入的数字<以-1结束>:");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushFront(&list, item);
			}
			printf("尾部插入成功......\n");
			break;
		case 3:
			DCListNodeShow(list);
			break;
		case 4:
			DCListNodePopBack(&list);
			printf("尾部删除成功......\n");
			break;
		case 5:
			DCListNodePopFront(&list);
			printf("头部删除成功......\n");
			break;
		case 6:
			//printf("请输入要插入的位置：>");
			//scanf("%d", &pos);
			//printf("清输入要插入的数字：>");
			//scanf("%d", &item);
			////flag = SeqListInsertByPos(&list, pos, item);
			////if (flag)
			//	printf("插入数据成功......\n");
			////else
			//	printf("插入数据失败......\n");
			break;
		case 7:
			printf("请输入需要插入的数字：>");
			scanf("%d", &item);
			DCListSort(list);
			DCListByVal(&list,item);
			printf("任意位置的插入成功......\n");
			break;
		case 8:
			//printf("请输入你要删除的位置：>");
			//scanf("%d", &pos);
			////flag = SeqListEraseByPos(&list, pos);
			//if (flag)
			//	printf("删除自定位置元素成功......\n");
			//else
			//	printf("删除自定位置元素失败......\n");
			break;
		case 9:
			printf("请输入要删除的元素：>");
			scanf("%d", &item);
			DCListEraseVal(list, item);
			printf("删除指定元素成功......\n");

			break;
		case 10:
			printf("请输入要查找的数字：>");
			scanf("%d", &item);
			p = DCListFind(list, item);
			if (p == NULL)
				printf("查找失败.....\n");
			else
				printf("查找成功.....\n");
			break;
		case 11:
			printf("DCList length = %d\n", DCListLength(list));
			break;
		case 12:
			//printf("SeqList capacity = %d\n",DCListCapacity(&list));
			break;
		case 13:
			DCListSort(list);
			printf("链表排序成功.....\n");
			break;
		case 14:
			DCListReverse(list);
			printf("转置成功......\n");
			break;
		case 15:
			DCListClear(&list);
			printf("清除数据成功.......\n");
			break;
		case 16:
			printf("表头元素为：%d\n", DCListFront(list));
			break;
		case 17:
			printf("表尾元素为：%d\n", DCListBack(list));
			break;
		case 19:
			printf("请输入要删除的元素：>");
			scanf("%d", &item);
			//SListEraseValAll(&list, item);
			printf("删除指定元素成功......\n");
			break;
		default :
			printf("输入错误，请重新出入......\n");
			break;
		}
	}
	DCListDestory(&list);

	return 0;
}
