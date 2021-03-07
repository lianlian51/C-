#pragma once

#include<string>
#include<vector>

typedef unsigned long long ulg;

struct CharInfo
{
	char ch;
	ulg appearCount; // 字符出现的次数
	std::string _strCode; // 字符对应的编码
};

class HTCompress
{
public:

	HTCompress();
	void CompressFile(const std::string& filePath);
	void UNCompressFile(const std::string& filePath);

private:
	std::vector<CharInfo> _charInfo;
};