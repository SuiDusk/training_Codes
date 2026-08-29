#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e5;
const int MOD = 1e9 + 7;
int n;
int a[MAXN];
long long sum = 1;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < i)
        {
            printf("0\n");
            return 0;
        }
        sum *= a[i] - i + 1;
        sum %= MOD;
    }
    printf("%lld\n", sum);
    return 0;
}