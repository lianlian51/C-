int movingCount(int m, int n, int k){
    if(k < 0)
        return 0;
    int res = 1;
    int p;
    int visit[100][100] = {0};
    visit[0][0] = 1;  // 将最开始的位置置为1
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n;j++)
        {
            // 双循环从[0,0]的位置开始
            int sum = 0;

            // 求位数之和
            for(int k = 0; k <= 2; k++)
            {
                p = pow(10, k);
                if(i/p > 0)
                    sum += (i/p)%10;
                if(j/p > 0)
                    sum += (j/p)%10;
            }

            // 如果上下左右有一个是走过的路，那么就将该位置置为1，并且res++
            if(sum <= k)
            {
                if((i > 0 && visit[i - 1][j] == 1 )|| visit[i + 1][j] == 1 || (j > 0 && visit[i][j - 1] == 1 )|| visit[i][j + 1] == 1)
                {
                    res++;
                    visit[i][j] = 1;
                }
            }
        }
    }
    return res;
}
