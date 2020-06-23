#include <iostream>
#include <string>
using namespace std;

// 返回最长公共子串
string Longstring(string s1, string s2)
{
    // str用于返回
    string str = "";
    for(int i = 0; i < s1.size(); i++)
    {
        // 将找到的子串暂时寄存在ret
        string ret = "";
        for(int j = 0; j < s2.size(); j++)
        {
            // 用index来代替i
            int index = i;
            // 字符相等
            while(s1[index] == s2[j])
            {
                ret += s1[index];
                index++;
                j++;
            }
            // 如果找到的字符比原来的大，那么就赋值过去
            if(ret.size() > str.size())
                str = ret;
            // 置空，不影响下一次的字符
            ret = "";
        }
    }
    // 返回
    return str;
}

int main()
{
    string s1;
    string s2;
    while(cin >> s1 >> s2)
    {
        if(s1.size() > s2.size())
            swap(s1, s2);
        // 打印
        cout << Longstring(s1, s2) << endl;
    }
    return 0;
}
