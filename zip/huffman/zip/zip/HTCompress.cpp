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
	if (nullptr == fIn)
	{
		cout << "���򿪵��ļ�����" << endl;
		return;
	}

	// 1.�����ַ����ֵĴ���
	char readBuffer[1024];
	while (true)
	{
		size_t  rdsize = fread(readBuffer, 1, 1024, fIn);
		if (rdsize == 0)
			break;

		for (size_t i = 0; i < rdsize; ++i)
		{
			_charInfo[readBuffer[i]]._appearCount++;
		}
	}

	// 2.��charInfo�Ĵ���ΪȨֵ������������
	HuffmanTree<CharInfo> ht;
	ht.CreateHuffmanTree(_charInfo, CharInfo(0));

	// 3.��ȡ�ַ���Huffman����
	GeneteCode(ht.GetRoot());

	// �����ļ�ָ���λ��
	rewind(fIn);

	// fOut����дѹ�������
	FILE* fOut = fopen("compresResult.txt", "w");

	// 4.�û�ȡ���ı����Դ�ļ���ÿ���ַ�����д��
	uch chData = 0;
	ulg biteCount = 0;
	while (true)
	{
		size_t rdsize = fread(readBuffer, 1, 1024, fIn);
		if (rdsize == 0)
		{
			break;
		}

		for (size_t i = 0; i < rdsize; ++i)
		{
			string& strCode = _charInfo[readBuffer[i]]._strCode;

			for (size_t j = 0; j < strCode.size(); ++j)
			{
				chData <<= 1;
				if (strCode[j] == '1')
					chData |= 1;
				biteCount++;
				if (biteCount == 8)
				{
					// �����ֽ�д�뵽ѹ���ļ���
					fputc(chData, fOut);
					biteCount = 0;
					chData = 0;
				}
			}
		}
	}

	// ����û��д���˸�����λ�����
	if (biteCount > 0 && biteCount < 8)
	{
		chData <<= (8 - biteCount);
		fputc(chData, fOut);
	}

	fclose(fIn);
	fclose(fOut);
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
			if (cur == parent->_left)
				strCode += '0';
			else
				strCode += '1';

			cur = parent;
			parent = cur->_parent;
		}

		reverse(strCode.begin(), strCode.end());
	}
}