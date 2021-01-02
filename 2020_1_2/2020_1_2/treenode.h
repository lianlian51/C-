#pragma once 

#include <stdio.h>
// #include <unistd.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#include <iostream>
#include <queue>

typedef char DataType;

typedef struct BTNode
{
	DataType data_;
	struct BTNode* left_;
	struct BTNode* right_;
}BTNode;

typedef BTNode* pBTNode;

BTNode* BuyNode(DataType data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));

	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->data_ = data;
	newNode->left_ = NULL;
	newNode->right_ = NULL;

	return newNode;
}

void InitBTree(pBTNode* Tree)
{
	// 这里开辟的head之后一定要给Tree，不然和没开辟是一个道理
	BTNode* head = (BTNode*)malloc(sizeof(BTNode));
	if (head != NULL)
	{
		head->data_ = 0;
		head->left_ = NULL;
		head->right_ = NULL;
	}
	*Tree = head;  // 这里一定要用*Tree = head,不要用Tree=&(head),实践的结果
}

void CreateBTree(pBTNode *Tree)
{
	DataType data;
	std::cin >> data;
	if (data == '#')
	{
		Tree = NULL;
	}
	else
	{
		*Tree = new BTNode;
		(*Tree)->data_ = data;
		// (*Tree)->left_ = NULL;
		// (*Tree)->right_ = NULL;
		CreateBTree(&(*Tree)->left_);
		CreateBTree(&(*Tree)->right_);
	}
}

void Create_1(pBTNode* pRoot)
{
	BTNode* node1 = BuyNode('1');
	BTNode* node2 = BuyNode('2');
	BTNode* node3 = BuyNode('3');
	BTNode* node4 = BuyNode('4');
	BTNode* node5 = BuyNode('5');
	BTNode* node6 = BuyNode('6');

	(*pRoot) = node1;
	node1->left_ = node2;
	node1->right_ = node3;
	node2->left_ = node4;
	node2->right_ = node5;
	node3->left_ = node6;
}

BTNode* Create_2()
{
	BTNode* node1 = BuyNode(5);
	BTNode* node2 = BuyNode(4);
	BTNode* node3 = BuyNode(8);
	BTNode* node4 = BuyNode(11);
	BTNode* node5 = BuyNode(13);
	BTNode* node6 = BuyNode(4);
	BTNode* node7 = BuyNode(7);
	BTNode* node8 = BuyNode(2);
	BTNode* node9 = BuyNode(5);
	BTNode* node10 = BuyNode(1);

	BTNode* pRoot = node1;
	node1->left_ = node2;
	node1->right_ = node3;
	node2->left_ = node4;
	node3->left_ = node5;
	node3->right_ = node6;
	node4->left_ = node7;
	node4->right_ = node8;
	node6->left_ = node9;
	node6->right_ = node10;

	return pRoot;
}

// 前序遍历
void PreOrder(pBTNode Tree)
{
	if (Tree)
	{
		std::cout << Tree->data_ << "->";
		PreOrder(Tree->left_);
		PreOrder(Tree->right_);
	}
}

// 中序遍历
void InOrder(pBTNode Tree)
{
	if (Tree)
	{
		InOrder(Tree->left_);
		std::cout << Tree->data_ << "->";
		InOrder(Tree->right_);
	}
}

// 后序遍历
void PostOrder(pBTNode Tree)
{
	if (Tree)
	{
		PostOrder(Tree->left_);
		PostOrder(Tree->right_);
		std::cout << Tree->data_ << "->";
	}
}

// 获取节点的个数
int GetCount(BTNode* root)
{
	// assert(root);
	if (root == NULL)
		return 0;

	return 1 + GetCount(root->left_) + GetCount(root->right_);
}

// 获得叶子节点的个数
int GetleafCount(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left_ == NULL && root->right_ == NULL)
		return 1;

	return GetleafCount(root->left_) + GetleafCount(root->right_);
}

// 返回二叉树的高度
int GetHeight(BTNode* root)
{
	assert(root);
	if (NULL == root)
		return 0;

	int leftHeight = GetHeight(root->left_);
	int rightHeight = GetHeight(root->right_);

	return leftHeight > rightHeight ? leftHeight : rightHeight;
}

// 获取k层节点的个数
int GetKCount(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return GetKCount(root->left_, k - 1) + GetKCount(root->right_, k - 1);
}

// 返回x在二叉树中的节点
BTNode* Find(BTNode* root, DataType data)
{
	if (root == NULL)
		return NULL;

	BTNode* pNode = NULL;

	if (root->data_ == data)
		return root;

	if ((pNode = Find(root->left_, data)) || (pNode = Find(root->right_, data)))
		return pNode;

	return NULL;
}

// 获取节点的双亲
BTNode* GetParent(BTNode* root, BTNode* node)
{
	if (root == NULL || node == NULL || root == node)
		return NULL;

	BTNode* pParent = NULL;

	if (root->left_ == node || root->right_ == node)
		return root;

	if ((pParent = GetParent(root->left_, node)) || (pParent = GetParent(root->right_, node)))
		return pParent;

	return NULL;
}

// 二叉树层序遍历
void levelOrder_queue(pBTNode& Tree)
{
	std::queue<pBTNode> q;
	if (Tree != NULL)
	{
		q.push(Tree);
	}

	while (!q.empty())
	{
		std::cout << q.front()->data_ << "->";

		if (q.front()->left_)
		{
			q.push(q.front()->left_);
		}

		if (q.front()->right_)
		{
			q.push(q.front()->right_);
		}
		q.pop();
	}
}
