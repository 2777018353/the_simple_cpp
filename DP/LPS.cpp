//longest Palindrome Subsequence
#include <iostream>
#include <cstring>
using namespace std;

string S;
const int maxn = 1010;
int dp[maxn][maxn] = {0};

int main()
{
    cin >> S;
    int len = S.size();
    int ans = 1;

    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i < len - 1)
        {
            if (S[i] == S[i + 1])
            {
                if (S[i] == S[i + 1]) //初始化时主义当前最长回文子串长度
                {
                    dp[i][i + 1] = 1;
                    ans = 2;
                }
            }
        }
    }
    //状态转移方程
    for (int L = 3; L <= len; L++)
    {
        for (int i = 0; i + L - 1 < len; i++)
        {
            int j = i + L - 1;
            if (S[i] == S[j] && dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    cout << ans;
}