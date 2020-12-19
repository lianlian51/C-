//#include<iostream>
//#include<cstring>
//#include<cassert>
//#include<queue>
//
//using namespace std;
//
//typedef char DataType;
//
//struct TreeNode {
//
//	DataType data;    /* node data */
//
//	struct TreeNode *leftPtr;   /* pointer to left subtree */
//
//	struct TreeNode *rightPtr;  /* pointer to right subtree */
//};
//
//
//typedef struct TreeNode TreeNode;
//
//typedef TreeNode * pTreeNode;
//
//
//void InitTreeNode(pTreeNode *Tree)
//{
//	*Tree = NULL;
//}

//void CreateBinTree(pTreeNode *Tree)
//{
//	DataType ch;
//	ch = getchar();
//	if (ch == '#')
//	{
//		*Tree = NULL;
//	}
//	else
//	{
//		*Tree = (pTreeNode)malloc(sizeof(pTreeNode));
//
//		if (NULL == (*Tree))
//		{
//			exit(0);
//		}
//		else
//		{
//			(*Tree)->data = ch;
//			(*Tree)->leftPtr = NULL;
//			(*Tree)->rightPtr = NULL;
//			CreateBinTree(&(*Tree)->leftPtr);
//			CreateBinTree(&(*Tree)->rightPtr);
//		}
//	}
//}
//
//void test()
//{
//	pTreeNode T;
//	InitTreeNode(&T);
//
//	CreateBinTree(&T);  //创建一个二叉树
//}
//
//int main(void)
//{
//	test();
//	return 0;
//}


//#include<stdlib.h>
//#include<malloc.h>
//#include<iostream>
//#include<stack>
//#include<queue>
//#include <cstring>
//
//#include <stdlib.h>
//using namespace std;
//
//typedef  char ElemType;
//
//typedef struct  BtNode
//{
//	BtNode *leftchild;
//	BtNode *rightchild;
//	ElemType data;
//}BtNode, *BinaryTree;
////购买结点
//BtNode *Buynode()
//{
//	BtNode *p = (BtNode *)malloc(sizeof(BtNode));
//	memset(p, 0, sizeof(BtNode));
//	return p;
//}
//void *Freenode(BtNode *ptr)
//{
//	free(ptr);
//}
//
////方法一
////前序创建二叉树
//void *PreCreateTree(BinaryTree  *ptr)
//{
//	char ch;
//	cin >> ch;
//	if (ch != '#' || ptr != NULL)
//	{
//		*ptr = Buynode();
//		(*ptr)->data = ch;
//		PreCreateTree(&(*ptr)->leftchild);
//		PreCreateTree(&(*ptr)->rightchild);
//	}
//}
//int main()
//{
//	BinaryTree root = NULL;
//	PreCreateTree(&root);
//}

#pragma once 

#include <stdio.h>

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
	*Tree = NULL;
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

BTNode* Create_()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	BTNode* pRoot = node1;
	node1->left_ = node2;
	node1->right_ = node3;
	node2->left_ = node4;
	node2->right_ = node5;
	node3->left_ = node6;

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

#include <iostream>

void Test()
{
	BTNode* T;
	InitBTree(&T);

	//T = Create_();
	CreateBTree(&T);

	std::cout << "前序遍历: ";
	PreOrder(T);
	std::cout << "NULL";

	std::cout << "\n中序遍历: ";
	InOrder(T);
	std::cout << "NULL";

	std::cout << "\n后序遍历: ";
	PostOrder(T);
	std::cout << "NULL";

	std::cout << "\n层序遍历: ";
	levelOrder_queue(T);
	std::cout << "NULL";

	std::cout << "\n节点的个数：" << GetCount(T) << std::endl;
}


int main()
{
	Test();
	return 0;
}
