#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int MAXN = 2005;
const int INF = 0x3f3f3f3f;
int n;
int a[MAXN];
int cnt = 0, ans = INF;
map<string, int> mp;
int l[MAXN][55], r[MAXN][55];
int p[55];
int r1 = 0;
bool cmp(int x, int y)
{
    return l[r1][x] < l[r1][y];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (mp.find(s) == mp.end())
            mp[s] = ++cnt;
        a[i] = mp[s];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            l[i][j] = l[i - 1][j];
        }
        l[i][a[i]] = i;
    }
    for (int i = 1; i <= cnt; i++)
    {
        r[n + 1][i] = INF;
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= cnt; j++)
        {
            r[i][j] = r[i + 1][j];
        }
        r[i][a[i]] = i;
    }
    for (r1 = 1; r1 < n; r1++)
    {
        for (int i = 1; i <= cnt; i++)
        {
            p[i] = i;
        }
        sort(p + 1, p + 1 + cnt, cmp);
        for (int l2 = r1 + 1; l2 <= n; l2++)
        {
            int r2 = l2;
            for (int i = 1; i <= cnt; i++)
            {
                int c = p[i], l1 = l[r1][c];
                if (l1 > 0)
                    ans = min(ans, r1 - l1 + 1 + r2 - l2 + 1);
                r2 = max(r2, r[l2][c]);
                if (r2 == INF)
                    break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}