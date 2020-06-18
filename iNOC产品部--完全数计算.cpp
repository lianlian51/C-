#include <iostream>
using namespace std;

// 判断是不是完备数
bool count(int k)
{
    // num 所有k的约数的和
    int num = 0;
    for(int i = 1; i < k; i++)
    {
        // 是约数的话就+=
        if(k % i == 0)
            num += i;
    }
    // 返回
    if(num == k)
        return true;
    else
        return false;
}

int main()
{
    int n = 0;
    while(cin >> n)
    {
        // 计数完备数个数
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            if(count(i))
                sum++;
        }
        // 打印
        cout << sum << endl;
    }
    return 0;
}
