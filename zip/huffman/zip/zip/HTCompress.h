#pragma once

#include<string>
#include<vector>

typedef unsigned long long ulg;

struct CharInfo
{
	char ch;
	ulg appearCount; // �ַ����ֵĴ���
	std::string _strCode; // �ַ���Ӧ�ı���
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