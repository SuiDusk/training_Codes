#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
int n;
long long ans = 0;
long long dp[MAXN];
long long f[MAXN][350];
int main()
{
    scanf("%d", &n);
    long long b = sqrt(n);
    dp[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        long long d, x;
        scanf("%lld%lld", &d, &x);
        for (int j = 1; j <= b; j++)
        {
            if (i + j <= n)
                f[i + j][j] = (f[i + j][j] + f[i][j] % MOD);
            dp[i] = (dp[i] + f[i][j]) % MOD;
        }
        ans = (ans + dp[i]) % MOD;
        if (d == 0)
            continue;
        if (d > b)
        {
            for (int j = i + d, k = 1; j <= n && k <= x; j += d, k++)
            {
                dp[j] = (dp[i] + dp[j]) % MOD;
            }
        }
        else
        {
            if (i + d <= n)
                f[i + d][d] = (f[i + d][d] + dp[i]) % MOD;
            if (i + d * (x + 1) <= n)
                f[i + d * (x + 1)][d] = (f[i + d * (x + 1)][d] - dp[i] + MOD) % MOD;
        }
    }
    printf("%lld\n", ans);
    // for (int i = 1; i <= n; i++)
    // {
    //     scanf("%lld%lld", &d[i], &x[i]);
    // }
    // dp[1] = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     for (int j = 1; j < i; j++)
    //     {
    //         if (d[j] == 0 || x[j] == 0)
    //             continue;
    //         if (((i - j + d[j]) % d[j]) == 0 && j + x[j] * d[j] >= i)
    //         {
    //             dp[i] += dp[j];
    //             dp[i] %= MOD;
    //         }
    //     }
    //     // printf("%lld\n", dp[i]);
    // }
    // long long ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     ans += dp[i];
    //     ans %= MOD;
    // }
    // printf("%lld\n", ans);
    return 0;
}