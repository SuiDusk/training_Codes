#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 1e7 + 5;
ll l, r;
int vis[MAXN];
int sum = 0;
ll ans = 1;
ll quick_pow(ll x, ll b)
{
    ll t = 1;
    while (b)
    {
        if (b & 1)
            t *= x, t %= MOD;
        x *= x, x %= MOD;
        b >>= 1;
    }
    return t;
}
int main()
{
    scanf("%lld%lld", &l, &r);
    for (ll i = l; i <= r; i++)
    {
        if (!vis[i])
        {
            sum++;
            for (ll j = i; j <= r; j += i)
            {
                vis[j] = 1;
            }
        }
    }
    for (int i = 1; i <= r - l + 2; i++)
    {
        ans *= i;
        ans %= MOD;
    }
    // cout << ans << endl;
    ll inv = quick_pow(sum + 1, MOD - 2);
    printf("%lld\n", ((ans * inv) % MOD * sum) % MOD);
    return 0;
}
