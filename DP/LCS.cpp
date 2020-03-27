//Longest Common Subsequence
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100;
string A, B;
int dp[N][N];

int main()
{
    int n;
    cin >> A >> B;
    int lenA = A.size();
    int lenB = B.size();

    // for (int i = 0; i < lenA; i++)
    // {
    //     dp[i][0] = 0;
    // }
    // for (int j = 0; j < lenB; j++)
    // {
    //     dp[0][j] = 0;
    // }

    for (int i = 0; i < lenA; i++)
    {
        for (int j = 0; j < lenB; j++)
        {
            if (A[i] == B[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1; //存在越界情况, 可考虑输入字符型数组, 并从第一位开始放
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[lenA - 1][lenB - 1];
}