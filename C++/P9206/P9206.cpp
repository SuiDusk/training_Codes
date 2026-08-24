#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m;
int a[MAXN];
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int d;
        scanf("%d", &d);
        for (int i = 1; i <= n; i++)
        {
            cnt++;
            int now = i;
            while (now > d)
            {
                if (a[now] < a[now - d])
                {
                    swap(a[now], a[now - d]);
                    now -= d, cnt++;
                }
                else
                    break;
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}