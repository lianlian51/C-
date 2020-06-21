#include <iostream>
#include <string>
using namespace std;

bool Judge(const string& s1, const string& s2)
{
    // i来遍历s1， j来遍历s2
    int i = 0;
    int j = 0;
    // flag处理*
    bool flag = false;
    while(s1[i] || s2[j])
    {
        // 如果是同样的字符，就一直往后走
        if(s1[i] == s2[j] || s1[i] == '?')
        {
            i++;
            j++;
        }
        // * 下面处理*
        else if(s1[i] == '*')
        {
            ++i;
            flag = true;
        }
        // 找s2相同的字符
        else if(flag)
        {
            while(s1[i] != s2[j])
                ++j;
            flag = false;
        }
        else
            return false;
    }
    // 如果此时的s1，s2都走到了末尾，则表示匹配成功
    if(s1[i] == '\0' && s2[j] == '\0')
        return true;
    else
        return false;
}

int main()
{
    string s1;
    string s2;
    // 因为是一行一行输入，所以用getline
    while(getline(cin, s1))
    {
        getline(cin, s2);
        // 调用函数
        if(Judge(s1, s2))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
