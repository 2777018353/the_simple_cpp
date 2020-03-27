//Longest Increasing Sequence
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;
int A[N], dp[N]; //A输入的序列, dp对应A每个元素的最长上升子序列

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    int ans = -1;                //记录最大的dp[i]
    for (int i = 1; i <= n; i++) //按顺序记录dp[i]的值
    {
        dp[i] = 1; //边界初始条件(默认每个元素是一个长度为1的子序列)
        for (int j = 1; j < i; j++)
        {
            if (A[i] >= A[j] && (dp[j] + 1 > dp[i]))
            {
                dp[i] = dp[j] + 1; //状态转移方程, 更新dp[i]
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}