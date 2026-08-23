#include <iostream>
#include <cstdio>
using namespace std;
int n, a, b;
unsigned long long dp[100][100];
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 50; i++)
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    unsigned long long ans = 0;
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
            ans += dp[n + i - 1][n - 1] * dp[n + j - 1][n - 1];
    cout << ans << endl;
    return 0;
}