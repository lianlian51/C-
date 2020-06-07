#include <iostream>
#include <algorithm>>
using namespace std;

int main()
{
    // Max先记录最小的数字，然后慢慢赋值变大
    // x表示输入的数字
    // temp比较大小
    int n, Max = -9999, x, temp = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        // 循环输入
        cin >> x;
        // 每次都是前一个数和后一个数的和 与 后一个数比大小
        // 大的记录起来
        temp = max(temp + x, x);
        // temp 和 Max比较，记录大的数字
        Max = max(temp, Max);
    }
    // 打印
    cout << Max<<endl;
    return 0;
}
