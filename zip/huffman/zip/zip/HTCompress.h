#pragma once
#include "HuffmanTree.hpp"

#include<string>
#include<vector>

typedef unsigned long long ulg;

struct CharInfo
{
	char _ch;
	ulg _appearCount; // 字符出现的次数
	std::string _strCode; // 字符对应的编码

	CharInfo(ulg appCount = 0)
		: _appearCount(appCount)
	{}

	CharInfo operator+(const CharInfo& c)
	{
		return CharInfo(_appearCount + c._appearCount);
	}

	bool operator>(const CharInfo& c) const 
	{
		return _appearCount > c._appearCount;
	}
};

class HTCompress
{
public:

	HTCompress();
	void CompressFile(const std::string& filePath);
	void UNCompressFile(const std::string& filePath);

private:
	void GeneteCode(HuffmanTreeNode<CharInfo>* root);
private:
	std::vector<CharInfo> _charInfo;
};