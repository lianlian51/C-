#include <iostream>
#include <vector>
#include <string>
using namespace std;

string AddLongInteger(string addend, string augend)
{
    // 算出两个字符串长度
    int size1 = addend.size();
    int size2 = augend.size();
    
    // size为大的
    int size = size1 > size2 ? size1 : size2;
    
    // 开辟空间
    vector<int> v1(size);
    vector<int> v2(size);
    
    // 这里是反向的放，便于+操作
    // 将addend这个字符串放在v1中
    for(int i = 0; i < size1; i++)
    {
        v1[i] = addend[size1 - i -1] - '0';
    }
    // 将auend这个字符串放在v2中
    for(int i = 0; i < size2; i++)
    {
        v2[i] = augend[size2 - i -1] - '0';
    }
    
    // 算出两个和的数组
    vector<int> v(size + 1, 0);
    for(int i = 0; i < size; i++)
    {
        v[i] += v1[i] + v2[i];
        // 有进位的处理
        if(v[i] > 9)
        {
            v[i + 1] = v[i] / 10;
            v[i] %= 10;
        }
    }
    
    // 用s来接收算出的数字
    string s;
    // 这里要判断是不是进位了
    if(v[size] == 0)
    {
        // 没有进位
        for(int i = 0; i < size; i++)
        {
            s.push_back(v[size - 1 - i] + '0');
        }
    }
    else
    {
        // 进位
        for(int i = 0; i < size + 1; i++)
        {
            s.push_back(v[size - i] + '0');
        }
    }
    
    // 返回s
    return s;
}

int main()
{
    // 输入的两个字符串
    string addend;
    string augend;
    // 调用函数并打印 
    while(cin >> addend >> augend)
    {
        cout << AddLongInteger(addend, augend) << endl;
    }
    return 0;
}
