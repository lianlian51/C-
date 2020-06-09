#include <iostream>
#include <vector>
using namespace std;

// 最终返回最小的数字
int Min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

int main()
{
    int N = 0;
    cin >> N;
    // Fibonacci 的三个数
    int f0 = 0;
    int f1 = 1;
    int f;
    
    // 找到存放数字的区间
    int right = 0;
    int left = 0;
    while(1)
    {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
        // 小于的话就一直找，直到大于
        if(f < N)
        {
            left = N - f;
        }
        else
        {
            right = f - N;
            break;
        }
    }
    // 打印出最小值
    cout << Min(right, left);
    return 0;
}
