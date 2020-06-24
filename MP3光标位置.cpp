#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // n歌曲数
    int n = 0;
    // s执行的up或者down操作
    string s;
    while(cin >> n >> s)
    {
        // 光标
        int index = 1;
        // 歌曲数小于4，表示所有的歌曲在同一页
        // 最后打印列表的时候就打印1到n
        if(n <= 4)
        {
            for(int i = 0; i < s.size(); i++)
            {
                // 光标在1，执行up操作
                if(index == 1 && s[i] == 'U')
                    index = n;
                else if(s[i] == 'U')
                    index--;
                // 光标在n，执行Down操作
                else if(index == n && s[i] == 'D')
                    index = 1;
                else if(s[i] == 'D')
                    index++;
             }
            // 打印列表
            for(int i = 0; i < n - 1; i++)
                cout << i + 1 << " "; 
            cout << n << endl;
            // 光标
            cout << index << endl;
        }
        else
        {
            // 表示歌曲列表
            vector<int> table(4);
            // 最开始是1,2,3,4
            for(int i = 0; i < 4; i++)
                table[i] = i + 1;
            for(int i = 0; i < s.size(); i++)
            {
                // 光标在1，执行up操作，先修改光标位置，再修改列表
                if(index == 1 && s[i] == 'U')
                {
                    index = n;
                    for(int i = 0; i < 4; i++)
                        table[3 - i] = n - i;
                }
                // 1.在同一个列表中up
                // 2.光标的位置正好是数组的第一个数字
                else if(s[i] == 'U')
                {
                    if(index == table[0])
                    {
                        // 修改数组的数字
                        for(int i = 0; i < 4; i++)
                        {
                            table[i] -= 1;
                        }
                    }
                    // 修改光标
                    index--;
                }
                else if(index == n && s[i] == 'D')
                {
                    index = 1;
                    for(int i = 0; i < 4; i++)
                        table[i] = i + 1;
                }
                // 1.在同一个列表中up
                // 2.光标的位置正好是数组的第一个数字
                else if(s[i] == 'D')
                {
                    if(index == table[3])
                    {
                        // 修改数组的数字
                        for(int i = 0; i < 4; i++)
                        {
                            table[i] += 1;
                        }
                    }
                    // 修改光标
                    index++;
                }
             }
            // 打印列表
            for(int i = 0; i < 3; i++)
                cout << table[i] << " ";
            cout << table[3] << endl;
            // 打印光标
            cout << index << endl;
        }
    }
    return 0;
}
