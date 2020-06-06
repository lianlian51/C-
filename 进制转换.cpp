#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string ret;
    // 建立一个表，最后进行字符访问直接输出
    string sTable("0123456789ABCDEF");
    int M = 0;
    int N = 0;
    cin >> M >> N;
    // flag用来记录M的正负
    int flag = 1;
    if(M < 0)
    {
        flag = 0;
        M = -M;
    }
    while(M)
    {
        // +=操作直接将字符+上去
        ret += sTable[M % N];
        M /= N;
    }
    if(flag == 0)
    {
        ret += '-';
    }
    // 反转字符，打印
    reverse(ret.begin(), ret.end());
    cout<<ret;
    return 0;
}
