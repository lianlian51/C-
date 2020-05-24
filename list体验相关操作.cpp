#include <iostream>
using namespace std;
#include <list>
#include <vector>

void Testlist()
{
	list<int> l1;
	list<int> l2(10, 5);
	cout << "l2:";
	list<int>::iterator it = l2.begin();
	while (it != l2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	vector<int> v{ 1, 2, 3, 4, 5 };
	list<int> l3(v.begin(), v.end());
	cout << "l3:";
	for (auto e : l3)
	{
		cout << e << " ";
	}
	cout << endl;


	int array[] = { 1, 2, 3, 4, 5 };
	list<int> l33(array, array + sizeof(array) / sizeof(array[0]));
	cout << "l33:";
	for (auto e : l33)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int> l4(l3);
	cout << "l4:";
	for (auto e : l4)
	{
		cout << e << " ";
	}
	cout << endl;

}


void Testlist1()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);
	L.push_back(6);
	cout << "尾插验证:";
	cout << L.size() << endl;
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	cout << "尾删验证：";
	L.pop_back();
	L.pop_back();
	cout << L.size() << endl;
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.push_front(0);
	cout << "头插验证：";
	cout << L.size() << endl;
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.pop_front();
	cout << "头删验证：";
	cout << L.size() << endl;
	for (auto e : L)
		cout << e << " ";
	cout << endl;
}

void Testlist2()
{
	// assign
	list<int> L{ 1, 2, 3, 4, 5 };
	L.assign(5, 5);
	cout << "5个5：";
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	int array[] = { 6, 7, 8 };
	L.assign(array, array + sizeof(array) / sizeof(array[0]));
	cout << "6,7,8:";
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	cout << "1,2,3,4,5,6:";
	L.assign({ 1, 2, 3, 4, 5, 6 });
	for (auto e : L)
		cout << e << " ";
	cout << endl;
}

void Testlist3()
{
	//insert
	list<int> L{ 1, 2, 3, 4, 5 };
	L.insert(L.begin(), 0);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	vector<int>  v{ 2, 3, 4 };
	L.insert(find(L.begin(), L.end(), 2),v.begin(),v.end());
	// L.insert(find(L.begin(),L.end(),2),10,5);
	cout << "找到2的地址进行区间插入：";
	for (auto e : L)
		cout << e<<" ";
	cout << endl;

	L.insert(L.end(), { 1, 1, 1, 1, 1 });
	cout << "区间插入：";
	for (auto e : L)
		cout << e << " ";
	cout << endl;
}


void Testlist4()
{
	// erase
	list<int> L{ 1, 2, 3, 4, 5 };

	// 删除3之后的所有元素
	L.erase(find(L.begin(), L.end(), 3), L.end());
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	// 清空操作
	L.erase(L.begin(), L.end());
}

bool ismod2(int data)
{
	return 0 == data % 2;
}

void Testlist5()
{
	// unique,sort,merge
	list<int> L{ 1, 1, 3, 3, 4, 4, 5 };
	L.unique();
	cout << "去重：";
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.assign({ 1, 2, 3, 4, 1, 2, 3, 4, 5 });
	cout << "排序：";
	L.sort();
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	cout << "去重2：";
	L.unique();
	for (auto e : L)
		cout << e << " ";
	cout << endl;


	//merge 合并list应该保持两个链表有序
	list<int> L1{ 3, 4, 5, 6 };
	L.merge(L1);
	cout << "合并两个链表:";
	for (auto e: L)
		cout << e << " ";
	cout << endl;

	cout << "删除指定元素：";
	L.remove(3);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	//remove_if 条件删除 1.函数指针 2.仿函数 3.lambda 此处为函数指针
	cout << "删除2的倍数的元素：";
	L.remove_if(ismod2);
	for (auto e : L)
		cout << e << " ";
	cout << endl;
} 

void Testlist6()
{
	// 迭代器失效
	list<int> l{ 1, 2, 3, 4, 5 };
	
	// 插入元素不会导致迭代器失效
	l.push_back(6);
	l.push_back(7);
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 删除元素会导致迭代器失效
	l.erase(l.begin());
	// 之前删除it迭代器的第一个元素
	// 该节点被删除后，it迭代器指向的一个被释放的节点
	// 改迭代器失效
	// 使用该迭代器之前，如果没有重新赋值，代码就会崩溃

	// 解决办法:it重新赋值
	it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	// Testlist();
	// Testlist1();
	// Testlist2();
	// Testlist3();
	// Testlist4();
	// Testlist5();
	Testlist6();
	return 0;
}
