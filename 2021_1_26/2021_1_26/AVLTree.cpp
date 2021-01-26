#pragma once 

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

		// 非空
		Node* cur = _root;
		Node* parent = nullptr;

		// 找到要插入的位置
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

		// 将新结点插入到该位置
		cur = new Node(data);
		if (data > cur->data)
			parent->right = cur;
		else
			parent->left = cur;
		cur->parent = parent;

		while (parent)
		{
			// 新结点插入之后，更新平衡因子
			if (cur == parent->left)
				parent->_bf--;
			else
				parent->_bf++;

			if (0 == parent->_bf)
				return true;
			else if (1 == parent->_bf || -1 == parent->_bf)
			{
				cur = parent;
				parent = cur->parent;
			}
		}
	}

private:
	void RotateLeft(Node* parent)
	{
		Node* SubR = parent->right;
		Node* SubRL = SubR->left;

		parent->right = SubRL;
		if (SubRL)
			SubRL->parent = parent;

		SubR->left = parent;

		Node* pparent = parent->parent;
		SubRL->parent = pparent;
		parent->parent = SubR;
		
		if (pparent == nullptr)
			_root = SubR;
		else if (pparent->left == parent)
			pparent->left = SubR;
		else if (pparent->right == parent)
			pparent->right = SubR;

		parent->_bf = SubR->_bf = 0;
	}


private:
	Node* _root;
};