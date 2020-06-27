#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n = 0;
	int sum = 1;
	cin >> n;
	vector<int> A;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}

	for (int i = 1; i < n - 1; i++)
	{
		if ((A[i - 1] > A[i] && A[i] < A[i + 1]) || (A[i - 1] < A[i] && A[i] > A[i + 1]))
		{
			++sum;
			if (i != n - 3)
				++i;
		}
	}
	cout << sum << endl;
	return 0;
}
