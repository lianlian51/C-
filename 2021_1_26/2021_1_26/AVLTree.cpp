#pragma once 
#include <iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& x)
	: left(nullptr)
	, right(nullptr)
	, parent(nullptr)
	, data(x)
	, _bf(0)
	{}

	AVLTreeNode<T>* left;
	AVLTreeNode<T>* right;
	AVLTreeNode<T>* parent;

	T data;
	int _bf;
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:

	AVLTree()
		: _root(nullptr)
	{}

	bool Insert(const T& data)
	{
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}

		// �ǿ�
		Node* cur = _root;
		Node* parent = nullptr;

		// �ҵ�Ҫ�����λ��
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

		// ���½����뵽��λ��
		cur = new Node(data);
		if (data > cur->data)
			parent->right = cur;
		else
			parent->left = cur;
		cur->parent = parent;


		// 2.�½������һ�����˫�׽ڵ��ƽ�����⵽Ӱ��
		//  ��Ҫ����parent��ƽ������
		while (parent)
		{
			// �½�����֮�󣬸���ƽ������
			if (cur == parent->left)
				parent->_bf--;
			else
				parent->_bf++;

			if (0 == parent->_bf)
				return true;
			else if (1 == parent->_bf || -1 == parent->_bf)
			{
				// ����cur֮ǰparent��Ҷ��
				// ��parentΪ���������ĸ߶�������һ��---��Ҫ���ϵ���
				cur = parent;
				parent = cur->parent;
			}
			else if (2 == parent->_bf || -2 == parent->_bf)
			{
				if (2 == parent->_bf)
				{
					if (1 == cur->_bf)
						RotateLeft(parent);
					else
						RotateRL(parent);
				}
				else
				{
					if (-1 == parent->_bf)
						RotateRight(parent);
					else
						RotateLR(parent);
				}
				break;
			}
		}
		return true;
	}

	void InOrder()
	{
		InOrder(_root);
		cout << endl;
	}

	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}


private:
	void InOrder(Node* root)
	{
		if (root)
		{
			InOrder(root->left);
			cout << root->data << " ";
			InOrder(root->right);
		}
	}

	void Destory(Node* & root)
	{
		if (root)
		{
			Destory(root->left);
			Destory(root->right);
			delete root;
			root = nullptr;
		}
	}


	void RotateLeft(Node* parent)
	{
		Node* SubR = parent->right;
		Node* SubRL = SubR->left;

		parent->right = SubRL;
		if (SubRL)
			SubRL->parent = parent;

		SubR->left = parent;

		Node* pparent = parent->parent;
		parent->parent = SubR;
		SubR->parent = pparent;

		if (pparent == nullptr)
			_root = SubR;
		else if (pparent->left == parent)
			pparent->left = SubR;
		else if (pparent->right == parent)
			pparent->right = SubR;

		parent->_bf = SubR->_bf = 0;
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
		subL->parent == pparent;

		if (pparent == nullptr)
			_root = subL;
		else if (pparent->left == parent)
			pparent->left = subL;
		else
			pparent->right = subL;

		subL->_bf = parent->_bf = 0;
	}


	void RotateLR(Node* parent)
	{
		// ��ת֮ǰ���뱣��subLR����Ϊ��ת���֮����Ҫ����subLR֮ǰƽ��
		// ������������µĽڵ��ƽ������
		Node* subL = parent->left;
		Node* subLR = subL->right;
		int bf = subLR->_bf;

		RotateLeft(parent->left);
		RotateRight(parent);

		if (1 == bf)
			subL->_bf = -1;
		else
			parent->_bf = 1;
}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;
		int bf = subRL->_bf;

		RotateRight(parent->right);
		RotateLeft(parent);

		if (1 == bf)
			parent->_bf = 1;
		else
			subR->_bf = 1;
	}

	int _Height(Node* root)
	{
		if (nullptr == root)
			return 0;

		int leftHeight = _Height(root->left);
		int rightHeight = _Height(root->right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool _IsBalanceTree(Node* root)
	{
		if (nullptr == root)
			return true;

		int leftHeight = _Height(root->left);
		int rightHeight = _Height(root->right);

		int bf = rightHeight - leftHeight;
		if (abs(bf) > 1 || bf != root->_bf)
		{
			cout << root->data << "�ڵ��ƽ������������" << endl;
			return false;
		}
		return _IsBalanceTree(root->left) && _IsBalanceTree(root->right);
	}

private:
	Node* _root;
};

void TestAVLTree()
{
	int array[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	AVLTree<int> t;
	for (auto e : array)
		t.Insert(e);

	t.InOrder();
	if (t.IsBalanceTree())
		cout << "t is a AVL tree!" << endl;
	else
		cout << "t is not a AVL tree��" << endl;
}