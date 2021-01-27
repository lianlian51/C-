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


		// 2.新结点插入后，一定会对双亲节点的平衡性遭到影响
		//  需要调整parent的平衡因子
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
				// 插入cur之前parent是叶子
				// 以parent为根的子树的高度增加了一层---需要往上调整
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
		RotateLeft(parent->left);
		RotateRight(parent);
	}

	void RotateRL(Node* parent)
	{
		RotateRight(parent->right);
		RotateLeft(parent);
	}

private:
	Node* _root;
};