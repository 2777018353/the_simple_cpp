typedef long long LL;
//求a ^ b % m, 迭代
LL binaryPow(LL a, LL b, LL m)
{
    LL ans = 1;
    while (b > 0)
    {

        if (b & 1)
        {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}