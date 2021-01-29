#pragma once

#include <iostream>

using namespace std;

enum Color{RED, BLACK};

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& x = T(), Color c = RED)
	: left(nullptr)
	, right(nullptr)
	, parent(nullptr)
	, data(x)
	, color(c)
	{}


	RBTreeNode<T>* left;
	RBTreeNode<T>* right;
	RBTreeNode<T>* parent;
	T data;
	Color color;
};

template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		head = new node();
		head->left = head;
		head->right = head;
		head->parent = nullptr;
	}

	~RBTree()
	{
		Destory(GetRoot());
		delete head;
		head = nullptr;
	}

	bool Insert(const T& data)
	{
		Node*& root = GetRoot();

		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			root->parent = head;
			head->left = root;
			head->right = root;
			return root;
		}

		// Ѱ�Ҳ���ڵ��λ��
		Node* cur = root;
		Node* parent = head;
		while (cur)
		{
			parent = cur;
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else
				return false;
		}

		// �����½ڵ�
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;

		cur->parent = parent;


		// �½ڵ�Ĭ���Ǻ�ɫ��
		// ����Ƿ�Υ������3

		while (parent != head && RED == parent->color)
		{
			Node* grandFather = parent->parent;
			if (parent == grandFather->left)
			{
				Node* uncle = grandFather->right;
				if (uncle && RED == uncle->color)
				{
					// ���һ������ڵ������Ϊ��
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					// ����ڵ㲻���� || ����ڵ�����Һ�ɫ
					if (cur == parent->right)
					{
						RotateLeft(parent);
						std::swap(parent, cur);
					}

					grandFather->color = RED;
					parent->color = BLACK;
					RotateRight(grandFather);
				}
			}
			else
			{
				// ˫�����游���Ҳ�
				Node* uncle = grandFather->left;
				if (uncle && RED == uncle->color)
				{
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					if (cur = parent->left)
					{
						RotateRight(parent);
						std::swap(parent, cur);
					}

					parent->color = BLACK;
					grandFather->color = RED;
					RtateLeft(grandFather);
				}
			}
		}
		root->color = BLACK;
		head->left = LeftMost();
		head->right = RightMost();
		return true;
	}




	void InOrder()
	{
		InOrder(GetRoot());
	}


	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return true;

		if (BLACK != root->color)
		{
			cout << "Υ������2�����ڵ㲻�Ǻ�ɫ��" << endl;
			retur false;
		}

		size_t blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->color)
				blackCount++;
			cur = cur->left;
		}

		size_t pathBlackCount = 0;
		return  _IsValidRBTree(root, pathBlackCount, blackCount);
	}

private:
	bool _IsValidRBTree(Node* root, size_t pathBlackCount, const size_t blackCount)
	{
		if (nullptr == root)
			return true;

		if (BLACK == root->color)
		{
			pathBlackCount++;
		}

		Node* parent = root->parent;
		// parent != head:˵��rootһ�����Ǻ�����ĸ��ڵ㣬parentһ���Ǻ��������Ч�ڵ�
		if (parent != head && RED == parent->color && RED == root->color)
		{
			cout << "Υ������3������" << endl;
			return false;
		}

		if (nullptr == root->left && nullptr == root->right)
		{
			if (pathBlackCount != blackCount)
			{
				cout << "Υ������4��·��" << endl;
				return false;
			}
		}

		return _IsValidRBTree(root->left, pathBlackCount, blackCount) &&
			_IsValidRBTree(root->right, pathBlackCount, blackCount);
	}



	void RotateLeft(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;

		if (subRL)
			subRL->parent = parent;

		subR->left = parent;

		// ����subR��parent ��˫��
		Node* pparent = parent->parent;
		parent->parent = subR;
		subR->parent = pparent;


		if (pparent == head)
		{
			head->parent = subR;
		}
		else
		{
			if (parent == pparent->left)
				pparent->left = subR;
			else
				pparent->right = subR;
		}
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		parent->left = subLR;

		if (subLR)
			subLR->parent = parent;

		subL->right = parent;

		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		// ����ԭparent ��˫��
		if (pparent == head)
		{
			head->parent = subL;
		}
		else
		{
			if (parent == pparent->left)
				pparent->left = subL;
			else
				pparent->right = subL;
		}
	}


	Node*& GetRoot()
	{
		return head->parent;
	}

	Node* LeftMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return head;

		Node* cur = root;
		while (cur->left)
			cur = cur->left;

		return cur;
	}

	Node* RightMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return head;

		Node* cur = root;
		while (cur->right)
			cur = cur->right;
		return cur;
	}

	void InOrder(Node* root)
	{
		if (root)
		{
			InOrder(root->left);
			cout << root->data << " ";
			InOrder(root->right);
		}
	}

	void Destory(Node*& root)
	{
		if (root)
		{
			Destory(root->left);
			Destory(root->right);
			delete root;
			root = nullptr;
		}
	}

private:
	Node* head;
};