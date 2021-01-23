//#include <stdio.h>
//// #include <unistd.h>
//
//#include <iostream>
//
//#include "treenode.h"
//
//BTNode *head, *tail;
//
//void Inorder_(BTNode* root)
//{
//	if (!root)
//		return;
//
//	Inorder_(root->left_);
//
//	if (!tail)
//	{
//		head = root;
//	}
//	else
//	{
//		tail->right_ = root;
//		root->left_ = tail;
//	}
//	tail = root;
//
//	Inorder_(root->right_);
//}
//
//BTNode* treetodoubleList(BTNode* root)
//{
//	if (!root)
//		return nullptr;
//
//	Inorder_(root);
//	head->left_ = tail;
//	tail->right_ = head;
//
//	return head;
//}
//
//int main()
//{
//	BTNode* root;
//	Create_1(&root);
//	BTNode* l = treetodoubleList(root);
//	BTNode* cur = l->right_;
//	// 因为这里不是二叉搜索树，所以打印出来不是顺序的
//	while (cur != l)
//	{
//		std::cout << cur->data_ << " ";
//		cur = cur->right_;
//	}
//	std::cout << std::endl;
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int empty;
//	int sum = 0;
//	while (n > 1)
//	{
//		empty = n / 3;
//		n %= 3;
//		n += empty;
//		sum += empty;
//		if (n == 2)
//		{
//			sum++;
//			break;
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}


#include <iostream>
using namespace std;
#include <string>

void func(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32 + '0';
	}
}

int getCommonStrLength(string s1, string s2)
{
	int n = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		int temp = 0;
		for (int j = 0; j < s2.size(); j++)
		{
			int index = i;
			while (s1[index] == s2[j])
			{
				temp++;
				j++, index++;
			}

			if (temp > n)
			{
				n = temp;
			}
			temp = 0;
		}
	}
	return n;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	func(s1);
	func(s2);

	cout << getCommonStrLength(s1, s2) << endl;
	return 0;
}