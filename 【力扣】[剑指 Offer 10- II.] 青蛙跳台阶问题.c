int numWays(int n)
{
    if(n < 2)
        return 1;   
    int a = 1;
    int b = 1;
    int c = 0;
    for(int  i = 1; i < n; ++i)
    {
        c = (a + b)%1000000007;
        a = b;
        b = c;
    }
    return c;
}
