#include <iostream>
#include <cstdio>
using namespace std;
int n;
int ans = 0;
bool f[100005];
void solution(int p, int m)
{
    if (p == 0)
    {
        if (!f[m])
        {
            ans++;
        }
        f[m] = 1;
    }
    else
    {
        for (int i = p; i >= 1; i--)
        {
            solution(p - i, i * (p - i) + m);
        }
    }
    return;
}
int main()
{
    scanf("%d", &n);
    solution(n, 0);
    printf("%d\n", ans);
    return 0;
}