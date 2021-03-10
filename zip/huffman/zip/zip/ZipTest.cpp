//#include "HuffmanTree.hpp"
#include "HTCompress.h"


int main()
{
	HTCompress htc;
	 htc.CompressFile("1.txt");
	htc.UNCompressFile("compresResult.txt");
	return 0;
}