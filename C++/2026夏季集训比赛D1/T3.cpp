#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;
const int MAXN = 5e5 + 5;
int n, k;
int ans;
int a[MAXN];
unordered_map<int, int> mp;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int cur = 0;
    mp[cur] = 1;
    for (int i = 1; i <= n; i++)
    {
        cur ^= a[i];
        if (mp[k ^ cur] == 1)
        {
            ans++;
            mp.clear();
            mp[cur] = 1;
        }
        else
        {
            mp[cur] = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}