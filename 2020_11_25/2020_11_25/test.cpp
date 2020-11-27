#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s;
	cin >> s;
	string str;

	while (cin >> str)
	{
		s = str + " " + s;
	}
	cout << s << endl;
	return 0;
}