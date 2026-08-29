#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

const int MAXX = 1e6 + 5;

struct st
{
    int l, r;
} match[MAXX];

int n;
int ans = 0;

int cmp(st a, st b)
{
    if (a.r < b.r)
        return 1;
    return 0;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &match[i].l, &match[i].r);
    }
    sort(match + 1, match + n + 1, cmp);
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        if (r <= match[i].l)
        {
            r = match[i].r;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}