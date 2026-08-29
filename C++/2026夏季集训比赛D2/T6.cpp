#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 105;
int T;
int m, s;
int a[MAXN];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &m, &s);
        int maxm = 0;
        int summ = 0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &a[i]);
            maxm = max(maxm, a[i]);
            summ += a[i];
        }
        if (maxm * (maxm + 1) / 2 - summ > s)
        {
            printf("NO\n");
            continue;
        }
        s -= maxm * (maxm + 1) / 2 - summ;
        for (int i = maxm + 1; s > 0; i++)
        {
            s -= i;
        }
        if (s == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}