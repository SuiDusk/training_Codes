#include <iostream>
#include <cstdio>
using namespace std;
long long n, ans, f[100005];
int main()
{
    scanf("%lld", &n);
    for (int i = n; i > 0; i--)
    {
        f[i] = n / i * (n / i);
        for (int j = i * 2; j <= n; j += i)
            f[i] -= f[j];
        ans += i * f[i];
    }
    printf("%lld\n", ans);
    return 0;
}