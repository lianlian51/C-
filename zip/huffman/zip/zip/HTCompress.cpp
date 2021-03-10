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
	FILE* fIn = fopen(filePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		cout << "待打开的文件出错" << endl;
		return;
	}

	// 1.计算字符出现的次数
	uch readBuffer[1024];
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

	// 2.以charInfo的次数为权值建立哈夫曼树
	HuffmanTree<CharInfo> ht;
	ht.CreateHuffmanTree(_charInfo, CharInfo(0));

	// 3.获取字符的Huffman编码
	GeneteCode(ht.GetRoot());

	// 更新文件指针的位置
	rewind(fIn);

	// fOut用来写压缩结果的
	FILE* fOut = fopen("compresResult.txt", "wb");

	WriteHeadInfo(fOut, filePath);
	// 4.用获取到的编码对源文件的每个字符进行写改
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
					// 将该字节写入到压缩文件中
					fputc(chData, fOut);
					biteCount = 0;
					chData = 0;
				}
			}
		}
	}

	// 对于没有写满八个比特位的情况
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


void HTCompress::WriteHeadInfo(FILE* fOut, const string& filePath)
{
	// 1.获取文件后缀
	string filePostFix = filePath.substr(filePath.find("."));
	filePostFix += "\n";

	// 2.字节出现的总行数
	size_t szCount = 0;

	// 3.字节，字符的次数---每条占一行
	string chAppear;
	for (size_t i = 0; i < 256; ++i)
	{
		if (0 != _charInfo[i]._appearCount)
		{
			chAppear += _charInfo[i]._ch;
			chAppear += ",";
			chAppear += to_string(_charInfo[i]._appearCount);
			chAppear += "\n";
			szCount++;
		}
	}

	fwrite(filePostFix.c_str(), 1, filePostFix.size(), fOut);

	string strCount = to_string(szCount);
	strCount += "\n";
	fwrite(strCount.c_str(), 1, strCount.size(), fOut);

	fwrite(chAppear.c_str(), 1, chAppear.size(), fOut);
}

void HTCompress::UNCompressFile(const std::string& filePath)
{
	// 读取文件
	FILE* fIn = fopen(filePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		cout << "压缩文件路径出错" << endl;
		return;
	}

	// 源文件的压缩名字
	string fileName = "2";
	string s;
	GetLine(fIn, s);
	fileName += s;

	s = "";
	GetLine(fIn, s);
	size_t szCount = atoi(s.c_str());

	// 获取每行的信息
	for (size_t i = 0; i < szCount; ++i)
	{
		s = "";
		GetLine(fIn, s);

		// 对于换行，单独处理
		if (s == "")
		{
			s += "\n";
			GetLine(fIn, s);
		}
		_charInfo[(uch)s[0]]._appearCount = atoi(s.c_str() + 2);
	}

	// 还原Huffman树
	HuffmanTree<CharInfo> ht;
	ht.CreateHuffmanTree(_charInfo, CharInfo(0));

	// 解压缩
	FILE* fOut = fopen(fileName.c_str(), "wb");

	HuffmanTreeNode<CharInfo>* cur = ht.GetRoot();
	uch bitCount = 8;
	uch chBit;
	ulg fileSize = cur->_weight._appearCount;
	uch readBuff[1024];

	while (true)
	{
		size_t rdsize = fread(readBuff, 1, 1024, fIn);
		if (0 == rdsize)
		{
			break;
		}

		for (size_t i = 0; i < rdsize; ++i)
		{
			bitCount = 8;
			chBit = readBuff[i];
			while (bitCount)
			{
				if (chBit & 0x80)
				{
					cur = cur->_right;
				}
				else
				{
					cur = cur->_left;
				}

				if (nullptr == cur->_left && nullptr == cur->_right)
				{
					// 走到了叶子节点，就解压出来一个字符
					fputc(cur->_weight._ch, fOut);
					cur = ht.GetRoot();

					// 处理最后一个字节不够8个比特位的情况
					fileSize--;
					if (0 == fileSize)
						break;
				}

				bitCount--;
				chBit <<= 1;
			}
		}
	}

	fclose(fIn);
	fclose(fOut);
}

void HTCompress::GetLine(FILE* fIn, std::string &s)
{
	uch ch;
	while (!feof(fIn))
	{
		ch = fgetc(fIn);
		if (ch == '\n')
			break;
		s += ch;
	}
}
