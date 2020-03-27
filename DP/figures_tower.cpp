#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000;
int f[maxn][maxn], dp[maxn][maxn]; //可以直接在f的最后一层直接操作, 减少空间

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) //输入数塔
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> f[i][j];
        }
    }

    for (int j = 1; j <= n; j++) //边界
    {
        dp[n][j] = f[n][j];
    }
    //从第n - 1层不断向上计算出dp[i][j](dp对于f的相应位置就是最大路径之和)
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            //状态转移方程
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
        }
    }
    cout << dp[1][1];
    return 0;
}