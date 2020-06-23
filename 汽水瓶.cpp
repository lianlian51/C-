#include <iostream>
using namespace std;

int Count(int n)
{
    // 空瓶的个数
    int empty = n;
    // 返回喝的汽水数
    int ret = 0;
    while(empty)
    {
        // 一个瓶子直接退出循环
        if(empty == 1)
            break;
        // 两个的话ret+1然后退出循环
        if(empty == 2)
        {
            ret += 1;
            break;
        }
        // value代表每次喝的汽水数
        int value = empty / 3;
        // 加上每次喝的汽水数
        ret += value;
        // 这两个是将空瓶的个数计数
        empty %= 3;
        empty += value;
    }
    return ret;
}

int main()
{
    int n = 0;
    // 循环输入遍历
    while(cin >> n)
    {
        cout << Count(n) << endl;
    }
    return 0;
}
