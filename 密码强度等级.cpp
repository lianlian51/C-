#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Password_strength(string str)
{
    int sum = 0;
    // 对应小写，大写，数字，字符
    // f赋初始值是为了之后判断的时候少判断，就是没有字母或者数字的时候就不用再次进行赋值为0
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    // 分类接收大写，小写，数字，字符
    vector<char> v2, v3, v4, v5;
    
    // 防止输入空字符串（一般不会输入无效字符）
    if(str.size() <= 0)
        return 0;
    
    // 字符串长度
    if(str.size() <= 4)
        sum1 =5;
    else if(str.size() <= 7 && str.size() >= 5)
        sum1 = 10;
    else if(str.size() >= 8)
        sum1 = 25;
    
    // 小写，大写，数字，字符
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            v2.push_back(str[i]);
        else if(str[i] >= 'A' && str[i] <= 'Z')
                v3.push_back(str[i]);
        else if(str[i] <= '9' && str[i] >= '0')
                v4.push_back(str[i]);
        else
                v5.push_back(str[i]);
    }
    // 这里其实可以不用len，只用在后面判断就行
    int len2 = v2.size(), len3 = v3.size(), len4 = v4.size(), len5 = v5.size();
    
    // 这里就是最后的判断，前面赋值为0 就是在这里起作用的
    if(len2 > 0)
        sum2 = 10;
    if(len3 > 0)
        sum3 = 10;
    if(len4 == 1)
        sum4 = 10;
    else if(len4 > 1)
        sum4 = 20;
    if(len5 == 1)
        sum5 = 10;
    else if(len5 > 1)
        sum5 = 25;
            
    // 奖励
    int sum6 = 0;
    if((len2 > 0 && len4 > 0) || (len3 > 0 && len4 > 0))
        sum6 = 2;
    else if((len2 > 0 && len4 > 0 && len5 > 0) || (len3 > 0 && len4 > 0 && len5 >0))
        sum6 = 3;
    else if(len2 > 0 && len3 > 0 && len4 > 0 && len5 > 0) 
        sum6 = 5;
    
    sum = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;
    // 返回
    return sum;
}

int main()
{
    string str;
    while(cin >> str)
    {
        int sum = Password_strength(str);
        // switch 语句很方便
        // 这里处理的时候小心50-25那个点，到case 5那里，用dafault，然后直接判断sum的值是否大于等于25
        switch(sum / 10)
        {
            case 9 :cout << "VERY_SECURE" << endl;
                break;
            case 8 :cout << "SECURE" << endl;
                break;            
            case 7 :cout << "VERY_STRONG" << endl;
                break;            
            case 6 :cout << "STRONG" << endl;
                break;            
            case 5 :cout << "AVERAGE" << endl;
                break;
            default:
                {
                    if(sum >= 25)
                        cout << "WEAK" << endl;
                    else
                        cout << "VERY_WEAK" << endl;
                }
        }
    }
    return 0;
}
