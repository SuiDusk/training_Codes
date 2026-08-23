#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 305;
int n, m;
int dp[MAXN][MAXN];
int f[MAXN][MAXN][MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int w, l, r;
        scanf("%d%d%d", &w, &l, &r);
        for (int j = l; j <= r; j++)
        {
            f[j][l][r] = w;
        }
    }
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k <= j; k++)
            {
                f[k][i][j] = max(f[k][i + 1][j], max(f[k][i][j - 1], f[k][i][j]));
            }
        }
    }
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k <= j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            for (int k = i; k <= j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + f[k][i][j]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
    // for (int k = 1; k <= n; k++)
    // {
    //     for (int i = k; i >= 1; i--)
    //     {
    //         for (int j = k; j <= n; j++)
    //         {
    //             if (i != 1)
    //             {
    //                 f[k][i - 1][j] = max(f[k][i - 1][j], f[k][i][j]);
    //             }
    //             if (j != n)
    //             {
    //                 f[k][i][j + 1] = max(f[k][i][j + 1], f[k][i][j]);
    //             }
    //         }
    //     }
    // }
    // for (int i = n; i >= 1; i--)
    // {
    //     for (int j = i; j <= n; j++)
    //     {
    //         for (int k = i; k < j; k++)
    //         {
    //             dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
    //         }
    //         for (int k = i; k <= j; k++)
    //         {
    //             dp[i][j] = max(dp[i][j], (k != i ? dp[i][k - 1] : 0) + (k != j ? dp[k + 1][j] : 0) + f[k][i][j]);
    //         }
    //     }
    // }
    // printf("%d\n", dp[1][n]);
    return 0;
}