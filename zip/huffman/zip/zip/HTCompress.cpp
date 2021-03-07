#include "HTCompress.h"
#include <iostream>
using namespace std;

#include <string>


HTCompress::HTCompress()
{
	_charInfo.resize(256);
	for (size_t i = 0; i < 256; ++i)
	{
		_charInfo[i].ch = i;
		_charInfo[i].appearCount = 0;
	}
}

void HTCompress::CompressFile(const std::string& filePath)
{
	FILE* fIn = fopen(filePath.c_str(), "r");
	if (fIn)
	{
		cout << "���򿪵��ļ�����" << endl;
		return;
	}

	// 1.�����ַ����ֵĴ���
	while (true)
	{
		char readBuffer[1024];
		size_t  rdsize = fread(readBuffer, 1, 1024, fIn);
		if (rdsize == 0)
			break;

		for (size_t i = 0; i < rdsize; ++i)
		{
			_charInfo[readBuffer[i]].appearCount++;
		}
	}

	// 2.��charInfo�Ĵ���ΪȨֵ������������

	fclose(fIn);
}