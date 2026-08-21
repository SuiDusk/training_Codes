#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 4e4 + 5;
int n, m;
int a[MAXN];
int dp[MAXN], l[300];
int cnt[300][MAXN], c[300];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int b = sqrt(n + 0.5);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (++cnt[j][a[i]] == 1)
            {
                if (++c[j] > j)
                {
                    while (--cnt[j][a[++l[j]]] != 0)
                    {
                        c[j]--;
                    }
                }
            }
        }
        for (int j = 1; j <= b; j++)
        {
            dp[i] = min(dp[i], dp[l[j]] + j * j);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}