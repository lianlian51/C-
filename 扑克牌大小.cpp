#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string card = "345678910JKQA2";
    vector<string> v;
    
    // 处理大小王
    v.push_back("joker JOKER");
    v.push_back("JOKER joker");
    
    // 输入
    string input;
    while(getline(cin, input))
    {
        // 分左右手
        unsigned int pos = input.find('-');
        int len = input.size();
        
        // 将牌分开
        string s1 = input.substr(0, pos);
        string s2 = input.substr(pos + 1, len - pos - 1);
        
        // 计数左右手空格数
        int n1 = count(s1.begin(), s1.end(), ' ');
        int n2 = count(s2.begin(), s2.end(), ' ');
        
        // 遇见王炸直接输出
        if(s1 == v[0] || s1 == v[1])
        {
            cout << s1 << endl;
            continue;  // 跳出这次循环，执行下一次
        }
        if(s2 == v[0] || s2 == v[1])
        {
            cout << s2 << endl;
            continue;
        }
        
        // 个子，对子，三个一样的，四个一样的均可比较
        // 因为这里的牌是排好序的
        if(n1 == n2)
        {
            int l = card.find(s1[0]);
            int r = card.find(s2[0]);
            string ans = l > r ? s1 : s2;
            cout << ans << endl;
            continue;
        }
        
        // 标胶炸弹和不是炸弹的牌
        if(n1 == 3 && n2 != 3)
        {
            cout << s1 << endl;
            continue;
        }
        else if(n1 != 3 && n2 == 3)
        {
            cout << s2 << endl;
            continue;
        }
        cout << "ERROR" << endl;
    }
    return 0;
}
