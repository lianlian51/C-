#include <iostream>
#include <string>
using namespace std;

int main()
{
        
    int dict = 1;
    int len = 1;
    
    int n = 0;
    cin >> n;
    string str[n + 1];
    for(int i = 0; i < n; i++)
    {
        cin >> str[i];
        if(i > 0)
        {
            if(str[i - 1] > str[i])
                dict = 0; // 判断字典
            if(str[i - 1].size() > str[i].size())
                len = 0;  // 判断长度
        }
    }
    
    if(len == 1 && dict == 1)
        cout<<"both"<<endl;
    else if(len == 1 && dict == 0)
        cout<<"lengths"<<endl;
    else if(len == 0 && dict ==1)
        cout<<"lexicographically"<<endl;
    else
        cout<<"none"<<endl;
    return 0;
}
