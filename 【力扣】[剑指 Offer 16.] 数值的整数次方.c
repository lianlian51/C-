double myPow(double x, int n){
    // 任何数的0次幂都是1
    if(n == 0)
        return 1;
    // 采用递归的方式，对于n==1则返回x，n==-1则返回1/x
    if(n == 1)
        return x;
    if(n == -1)
        return 1 / x;

    // 每次算一半解决，提高速率
    double half = myPow(x, n / 2);
    // 解决取模下来为1的情况
    double mod = myPow(x, n % 2);
    return half * half * mod;
}
