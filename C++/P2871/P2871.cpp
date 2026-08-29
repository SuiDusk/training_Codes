#include <iostream>
#include <cstdio>
using namespace std;
const int MAXX = 30005;
int v, n;
int w[MAXX];
int c[MAXX];
int dp[MAXX];

int main()
{
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &w[i], &c[i]);
    for (int i = 1; i <= n; i++)
        for (int j = v; j >= w[i]; j--)
            dp[j] = max(dp[j - w[i]] + c[i], dp[j]);
    printf("%d\n", dp[v]);
    return 0;
}