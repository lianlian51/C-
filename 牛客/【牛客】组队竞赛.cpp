#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0;
    long long sum = 0; // 必须用long long
    vector<int> v;
    cin>>n;  // c++输入
    v.resize(3*n);  // 开辟空间
    for(int i = 0; i < 3*n; ++i)
    {
        cin>>v[i];  // 向空间里面写入数据
    }
    
    sort(v.begin(), v.end()); // sort前面不用加v.
    int count = n;
    for(int i = v.size() - 1; i > 0 && count > 0; --i)
    {
        v.pop_back();
        sum += v.back();
        v.pop_back();
        --count;
    }
    cout<< sum;
    return 0;
}
