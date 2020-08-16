int cuttingRope(int n){
    int a = 0;
    int b = 0;
    if(n <= 3)
        return n - 1;
    else
    {
        b = n % 3;
        a = (n - b)/3;
        if(b == 2)
        {
            return pow(3, a)*2;
        }
        else
        {
            return b ? pow(3, a -1)*4:pow(3,a);
        }
    }
}
