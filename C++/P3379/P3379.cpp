#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int MAXN = 5e5 + 5;
int n, m, r, dn;
int dfn[MAXN];
int mi[20][MAXN];
vector<int> g[MAXN];
int __lg(int x)
{
    int cnt = 0;
    while (x)
        cnt++, x >>= 1;
    return cnt;
}
int get(int x, int y)
{
    return dfn[x] < dfn[y] ? x : y;
}
void dfs(int x, int f)
{
    mi[0][dfn[x] = ++dn] = f;
    for (int it : g[x])
        if (it != f)
            dfs(it, x);
}
int lca(int u, int v)
{
    if (u == v)
        return u;
    if ((u = dfn[u]) > (v = dfn[v]))
        swap(u, v);
    int d = __lg(v - u++) - 1;
    return get(mi[d][u], mi[d][v - (1 << d) + 1]);
}
int main()
{
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(r, 0);
    for (int i = 1; i <= __lg(n) - 1; i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}