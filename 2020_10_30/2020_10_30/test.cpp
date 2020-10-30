// ÆðÅÝ·¨×Ö·û´®
#include <stdio.h>
#include <string.h>

void Fun(char* arr, int len)
{
	for (int i = 0; i < len - 2; i++)
	{
		for (int j = 0; j < len - i - 3; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				char tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}


int main()
{
	char arr[] = "dsgcds";
	printf("%s\n", arr);
	int num = sizeof(arr) / sizeof(arr[0]);
	Fun(arr, num);
	printf("%s\n", arr);
	return 0;
}