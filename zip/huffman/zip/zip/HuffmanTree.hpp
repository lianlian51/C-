#pragma once

#include <vector>
#include <queue>

template<class W>
struct HuffmanTreeNode
{
	// 孩子双亲表示法
	HuffmanTreeNode(const W& weight = W())
	: _left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _weight(weight)
	{}

	HuffmanTreeNode<W>* _left;
	HuffmanTreeNode<W>* _right;
	HuffmanTreeNode<W>* _parent;
	W _weight;
};

template<class W>
struct HuffmanTree
{
	typedef HuffmanTreeNode<W> Node;

	struct Compare
	{
		bool operator()(const Node* left, const Node* right)
		{
			return left->_weight > right->_weight;
		}
	};

public:

	HuffmanTree()
		: _root(nullptr)
	{}

	~HuffmanTree()
	{
		DestoryTree(_root);
	}

	Node* CreateHuffmanTree(const std::vector<W>& weights, const W& invalid)
	{
		std::priority_queue<Node*, std::vector<Node*>, Compare> q;
		for (auto e : weights)
		{
			if (e == invalid)
				continue;
			q.push(new Node(e));
		}

		while (q.size() > 1)
		{
			Node* left = q.top();
			q.pop();

			Node* right = q.top();
			q.pop();

			Node* parent = new Node(left->_weight + right->_weight);
			parent->_left = left;
			parent->_right = right;

			left->_parent = parent;
			right->_parent = parent;
			q.push(parent);
		}
		
		_root = q.top();
		return _root;
	}

	Node* GetRoot()
	{
		return _root;
	}

private:
	void DestoryTree(Node* & root)
	{
		if (root)
		{
			DestoryTree(root->_left);
			DestoryTree(root->_right);
			delete root;
			root = nullptr;
		}
	}

private:
	Node* _root;
};
