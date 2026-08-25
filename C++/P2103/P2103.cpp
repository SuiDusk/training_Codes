#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m;
int z[505];
int mp[505][505];
int g[505][505];
int main()
{
    memset(mp, 0x3f, sizeof(mp));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        mp[u][v] = w;
        mp[v][u] = w;
        g[u][v] = w;
        g[v][u] = w;
    }
    for (int i = 1; i <= n; i++)
    {
        mp[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mp[i][j] > mp[i][k] + mp[k][j])
                {
                    mp[i][j] = mp[i][k] + mp[k][j];
                    mp[j][i] = mp[i][k] + mp[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        memset(z, 0, sizeof(z));
        for (int j = 1; j <= n; j++)
        {
            if (i == j || mp[i][j] == mp[0][0])
                continue;
            for (int k = 1; k <= n; k++)
            {
                if (!g[k][j])
                    continue;
                if (mp[i][k] + g[k][j] == mp[i][j])
                {
                    z[j]++;
                }
            }
        }
        for (int j = i + 1; j <= n; j++)
        {
            int ans = 0;
            for (int k = 1; k <= n; k++)
            {
                if (k == i)
                    continue;
                if (mp[i][k] + mp[k][j] == mp[i][j])
                    ans += z[k];
            }
            printf("%d ", ans);
        }
    }
    printf("\n");
    return 0;
}