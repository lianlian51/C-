int cuttingRope(int n){
    // 小于3返回n-1
    if(n <= 3)
        return n - 1;
    
    // a表示3的个数。b表示余数
    int a = 0;
    int b = 0;
    // 最后的最大值
    long long int sum = 1;

    b = n % 3;
    a = n / 3 - 1;
    int p = 1000000007;

    // a个3相乘
    while(a > 0)
    {
        sum = (sum*3)%p;
        a--;
    }

    // 因为之前少了一个3，所以在这里我们乘上去
    if(b == 0)
        sum = (sum * 3)%p;
    else if(b == 1)
        sum = (sum * 4)%p;
    else if(b == 2)
        sum = (sum * 6)%p;

    return sum;
}
