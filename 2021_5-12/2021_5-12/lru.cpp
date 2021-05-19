#include <iostream>
#include <unordered_map>

struct DLinkedNode
{
	DLinkedNode* prev;
	DLinkedNode* next;
	int _key, _value;
	DLinkedNode()
		: prev(nullptr)
		, next(nullptr)
		, _key(0)
		, _value(0)
	{}

	DLinkedNode(int key, int value)
		: prev(nullptr)
		, next(nullptr)
		, _key(key)
		, _value(value)
	{}
};


class LRUCache
{
public:
	LRUCache(int capacity)
		: _capacity(capacity)
	{
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}

	int Get(int key)
	{
		if (!cache.count(key))
			return -1;
		DLinkedNode* Node = cache[key];
		MoveToHead(Node);
		return Node->_value;
	}

	void Put(int key, int value)
	{
		if (!cache.count(key))
		{
			DLinkedNode* Node = new DLinkedNode(key, value);
			AddToHead(Node);
			++_size;
			if (_size > _capacity)
			{
				DLinkedNode* Node = DeleteTail();
				cache.erase(Node->_key);
				delete Node;
				--_size;
			}
		}
		else
		{
			// key´æÔÚ
			DLinkedNode* Node = cache[key];
			Node->_value = value;
			AddToHead(Node);
		}
	}

private:
	void AddToHead(DLinkedNode* Node)
	{
		Node->prev = head;
		Node->next = head->next;
		Node->next->prev = Node;
		head->next = Node;
	}

	DLinkedNode* DeleteTail()
	{
		DLinkedNode* Node = tail->prev;
		RemoveNode(Node);
		return Node;
	}

	void RemoveNode(DLinkedNode* Node)
	{
		Node->prev->next = Node->next;
		Node->next->prev = Node->prev;
	}

	void MoveToHead(DLinkedNode* Node)
	{
		RemoveNode(Node);
		AddToHead(Node);
	}
private:
	DLinkedNode* head;
	DLinkedNode* tail;
	int _size;
	int _capacity;
	std::unordered_map<int, DLinkedNode*> cache;
};



int main()
{
	return 0;
}