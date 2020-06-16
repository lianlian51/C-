#include <iostream>
#include <algorithm>
using namespace std;

// 袋子里面数字的个数
int n = 0;
int* x = NULL;

int Count(int pos, int add, long long mul)
{
    int num = 0;
    for(int i = pos; i < n; i++)
    {
        add += x[i];
        mul *= x[i];
        
        // 判定其是不是幸运的袋子
        if(add > mul)
            num += 1 + Count(i + 1, add, mul);
        else if(x[i] == 1)
            num += Count(i + 1, add, mul);
        else
            break;
        
        // 不符合的话直接去掉
        add -= x[i];
        mul /= x[i];
        
        // 去掉x[i]是1 的情况
        while(x[i] == x[i + 1] && (i + 1 <n))
             i++;
    }
    return num;
}


int main()
{
    cin >> n;
    // 开辟空间
    x = new int[n];
    int add = 0; // 和
    long long mul = 1; // 积
    // 输入数据
    for(int i = 0; i < n; i++)
        cin >> x[i];
    
    // 排序，记得头文件
    sort(x, x + n);
    // 计数函数
    int num = Count(0, add, mul);
    // 打印
    cout << num;
    // 销毁
    if(x != NULL)
    {
        delete []x;
        x = NULL;
    }
    return 0;
}
