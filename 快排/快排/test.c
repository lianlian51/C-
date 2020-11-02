#include "QuickSort.h"

int main()
{
	int array[] = { 9, 3, 8, 6, 7, 2, 1, 0, 4, 5 };
	Print(array, sizeof(array) / sizeof(array[0]));
	QuickSort(array, 0, sizeof(array) / sizeof(array[0]));


	Print(array, sizeof(array) / sizeof(array[0]));
	return 0;
}

