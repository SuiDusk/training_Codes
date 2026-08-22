#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXK = 1e6 + 5;
int n, k;
int a[MAXK];
int b[MAXK];
long long ans = 0;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    sort(a + 1, a + 1 + k);
    sort(b + 1, b + 1 + k);
    int cnt = 1;
    for (int i = 1; i < k; i++)
    {
        if (a[i + 1] != a[i])
        {
            cnt++;
        }
    }
    ans += 1LL * cnt * n;
    int cnt1 = 1;
    for (int i = 1; i < k; i++)
    {
        if (b[i + 1] != b[i])
        {
            cnt1++;
        }
    }
    ans += 1LL * (n - cnt) * cnt1;
    printf("%lld\n", ans);
    return 0;
}