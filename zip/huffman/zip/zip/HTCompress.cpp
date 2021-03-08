#include "HTCompress.h"
//#include "HuffmanTree.hpp"

#include <iostream>
using namespace std;

#include <string>


HTCompress::HTCompress()
{
	_charInfo.resize(256);
	for (size_t i = 0; i < 256; ++i)
	{
		_charInfo[i]._ch = i;
		_charInfo[i]._appearCount = 0;
	}
}

void HTCompress::CompressFile(const std::string& filePath)
{
	FILE* fIn = fopen(filePath.c_str(), "r");
	if (fIn)
	{
		cout << "待打开的文件出错" << endl;
		return;
	}

	// 1.计算字符出现的次数
	while (true)
	{
		char readBuffer[1024];
		size_t  rdsize = fread(readBuffer, 1, 1024, fIn);
		if (rdsize == 0)
			break;

		for (size_t i = 0; i < rdsize; ++i)
		{
			_charInfo[readBuffer[i]]._appearCount++;
		}
	}

	// 2.以charInfo的次数为权值建立哈夫曼树
	HuffmanTree<CharInfo> ht;
	ht.CreateHuffmanTree(_charInfo);

	// 3.获取字符的Huffman编码
	GeneteCode(ht.GetRoot());

	fclose(fIn);
}


void HTCompress::GeneteCode(HuffmanTreeNode<CharInfo>* root)
{
	if (nullptr == root)
		return;

	GeneteCode(root->_left);
	GeneteCode(root->_right);

	if (root->_left == nullptr && root->_right == nullptr)
	{
		HuffmanTreeNode<CharInfo>* cur = root;
		HuffmanTreeNode<CharInfo>* parent = cur->_parent;

		string& strCode = _charInfo[cur->_weight._ch]._strCode;
		while (parent)
		{
			if (root == parent->_left)
				strCode += '0';
			else
				strCode += '1';
		}

		reverse(strCode.begin(), strCode.end());
	}
}