#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1005;
struct cow
{
    int x, tap;
    cow(int x = 0, int t = 0) : x(x), tap(t) {};
    bool operator<(const cow t) const
    {
        return x < t.x;
    }
} a[MAXN];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].tap);
    }
    sort(a + 1, a + 1 + n);
    int wb = 1e9;
    for (int i = 1; i < n; i++)
    {
        if (a[i].tap ^ a[i + 1].tap)
        {
            wb = min(wb, a[i + 1].x - a[i].x);
        }
    }
    // cout << wb << endl;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i + 1].tap == 1 && a[i + 1].tap == 1 && a[i + 1].x - a[i].x >= wb)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}