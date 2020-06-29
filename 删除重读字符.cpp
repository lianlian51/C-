#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s1,s2;
    getline(cin, s1); // 连续输入字符
    getline(cin, s2);
    
    for(int i = 0; i < s2.size(); ++i)
    {
        int index ; // 找到s1里面的重复字符，删除
        while((index = s1.find(s2[i])) != -1)
              s1.erase(index, 1); // erase(size_t pos = 0;size_t len = npos)
    }

    cout<<s1<<endl;
    return 0;
}
