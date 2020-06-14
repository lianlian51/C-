#include <iostream>
#include <cmath>
using namespace std;

// 判断是不是素数
bool Prime(int n)
{
    int i = 2;
    for(i; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return false;
    }
    if(i > sqrt(n))
        return true;
}


int main()
{
    int n = 0;
    // 循环输入
    while(cin >> n)
    {
        // 这里i + （n - i） 正好等于n，所以直接判断同时是不是素数，是的话那就直接打印
        // 因为两个数相加等于n值，只要判断是不是素数即可
        for(int i = n / 2; i >= 2; i--)
        {
            if(Prime(i) && Prime(n - i))
            {
                // 打印
                cout << i << endl << n - i<< endl;
                break;
            }
        }
    }
    return 0;
}
