#include <iostream>
#include <cstdio>

using namespace std;

typedef long long Lint;

Lint c[500005];
int n, m;

int lowbit(int x)
{
    return x & (-x);
}

void add(int k, Lint x)
{
    for (int i = k; i <= n; i += lowbit(i))
        c[i] += x;
    return;
}

Lint query(int k)
{
    Lint ans = 0;
    for (int i = k; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main()
{
    scanf("%d %d", &n, &m);
    Lint last = 0, now;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &now);
        add(i, now - last);
        last = now;
    }
    int flag;
    while (m--)
    {
        scanf("%d", &flag);
        if (flag == 1)
        {
            int x, y;
            Lint k;
            scanf("%d %d %lld", &x, &y, &k);
            add(x, k);
            add(y + 1, -k);
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%lld\n", query(x));
        }
    }
    return 0;
}