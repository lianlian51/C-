#include <iostream>
#include <vector>
#include <string.h>

#include <string>
#include <stdio.h>

#pragma warning(disable:4996)

void TestStrcpy()
{
	char buff1[] = "abcdef";
	char buff2[30];

	strcpy(buff2, buff1);
	std::cout << buff2 << std::endl;
}


void TestMemcpy()
{
	char buff[] = "abcdef";
	//string s = "abc";
	memcpy(s, '\0', strlen(buff));
	std::cout << buff << std::endl;
}

int main()
{
	// TestStrcpy();
	TestMemcpy();
	return 0;
}