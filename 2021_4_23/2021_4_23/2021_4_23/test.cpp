#include <iostream>
#include <string>
#include <vector>
using namespace std;

int StrToInt(string str) {
	bool flag = false;
	if (str[0] == '-'){
		flag = true;
	}
	int i = 0;
	if (flag)
		i = 1;

	vector<int> st;
	for (; i < (int)str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9'){
			int temp = str[i] - '0';
			st.push_back(temp);
		}
		else
			return 0;
	}
	int ret = 0;
	i = 0;
	int l = st.size();
	while (i < l){
		ret *= 10;
		ret += st[i];
		i++;
	}
	if (flag)
		ret = 0 - ret;
	return ret;
}

int main()
{
	string str;
	while (cin >> str)
	{
		cout << StrToInt(str) << endl;
	}
	return 0;
}