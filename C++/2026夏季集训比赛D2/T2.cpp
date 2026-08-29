#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1005;
int T;
int n, s, r;
int a[MAXN];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &s, &r);
        int diff = r - (n - 1);
        for (int i = 0; i <= n - 1; i++)
            a[i] = 1;
        for (int i = 0; i < n - 1 && diff > 0; i++)
        {
            int add = min(diff, s - r - 1);
            a[i] += add;
            diff -= add;
        }
        for (int i = 0; i < n - 1; i++)
        {
            printf("%d ", a[i]);
        }
        printf("%d\n", s - r);
    }
    return 0;
}