#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int T;
ll a, b, l, r, x;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld %lld %lld %lld %lld", &l, &r, &x, &a, &b);
        if (a == b)
            printf("0\n");
        else if (abs(a - b) >= x)
            printf("1\n");
        else if ((llabs(a - r) >= x && llabs(r - b) >= x) || (llabs(a - l) >= x && llabs(l - b) >= x))
            printf("2\n");
        else if ((llabs(a - l) >= x && llabs(r - b) >= x) || (llabs(a - r) >= x && llabs(l - b) >= x))
            printf("3\n");
        else
            printf("-1\n");
    }
    return 0;
}