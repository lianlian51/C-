#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int W,H,ret = 0;
    // 利用vector的二维数组来解决
    vector<vector<int>> v;
    cin >> W >> H;
    // 开辟横排空间
    v.resize(W);
    // 开辟列排空间
    // 先将所有的数字全置为1，最后将不符合的置为0
    for(auto &e : v)
    {
        
        e.resize(H, 1);
    }
    
    // 循环遍历所有的数字
    for(int i = 0; i < W; i++)
    {
        for(int j = 0; j < H; j++)
        {
            if(v[i][j] == 1)
            {
                ret++;
                // 任意横排或者裂开之间相距2，就可以直接置为0
                // ret控制最火有多少个蛋糕
                if((i + 2) < W)
                    v[i + 2][j] =0;
                if((j + 2) < H)
                    v[i][j + 2] =0;
            }
        }
    }
    // 打印
    cout << ret <<endl;
    return 0;
}
