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
			_charInfo[readBuffer[i]].appearCount++;
		}
	}

	// 2.以charInfo的次数为权值建立哈夫曼树

	fclose(fIn);
}