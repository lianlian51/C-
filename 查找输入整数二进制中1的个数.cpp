#include <iostream>
using namespace std;

int main()
{
    // 输入的整数
    int n = 0;
    while(cin >> n)
    {
        // 计数
        int count = 0;
        while(n)
        {
            // &运算，每次都和二进制的最后一位比较
            if(n & 1 == 1)
                count++;
            // 右移一位
            n = n >> 1;
        }
        // 打印
        cout << count << endl;
    }
    return 0;
}
