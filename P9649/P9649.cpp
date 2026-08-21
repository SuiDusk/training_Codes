#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 5;
int n;
int T;
long long ans;
int l[MAXN], r[MAXN];
int cal(int x, int i)
{
    if (!((x >> i) & 1))
    {
        x = ((x >> i) | 1) << i;
    }
    return x;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &l[i], &r[i]);
        }
        for (int i = 30; i >= 0; i--)
        {
            long long t = 1ll << i;
            int flag = 0;
            for (int j = 1; j <= n; j++)
            {
                if (cal(l[j], i) > r[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            for (int j = 1; j <= n; j++)
                l[j] = cal(l[j], i);
            ans |= t;
        }
        printf("%lld\n", ans);
    }
    return 0;
}