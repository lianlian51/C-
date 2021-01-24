#include <iostream>
using namespace std;

int main()
{
	unsigned long long  int n = 1;
	for (int i = 1; i < 101; i++)
	{
		n *= i;
	}
	cout << n << endl;
	return 0;
}