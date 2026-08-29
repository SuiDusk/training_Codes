#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int MAXN = 5005;
int n;
int maxx;
int a[MAXN];
ll dp[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        maxx = max(maxx, a[i]);
    }
    sort(a + 1, a + 1 + n);
    dp[0] = 1;
    ll _ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        ll pre = 0;
        for (int j = 0; j <= x; j++)
        {
            pre = (pre + dp[j]) % MOD;
        }
        ll _ans_i = (pre - i + MOD) % MOD;
        _ans = (_ans + _ans_i) % MOD;
        for (int j = maxx; j >= x; j--)
        {
            dp[j] = (dp[j] + dp[j - x]) % MOD;
        }
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++)
        ans = (ans * 2) % MOD;
    ans = (ans - 1 - n + MOD) % MOD;
    ans = (ans - 1ll * n * (n - 1) / 2 % MOD + MOD) % MOD;
    ans = (ans - _ans + MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}