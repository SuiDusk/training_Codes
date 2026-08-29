#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m;
int tap = 0;
int index;
int a[MAXN];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++)
    {
        scanf("%d", &a[i]);
    }
    tap = a[1];
    sort(a + 1, a + 1 + n * m, cmp);
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i] == tap)
        {
            index = i;
            break;
        }
    }
    // printf("%d\n",index);
    int x = (index - 1) / n + 1;
    int y = index % n;
    if (y == 0)
        y = n;
    if (x % 2 == 1)
    {
        printf("%d %d\n", x, y);
    }
    else
    {
        printf("%d %d\n", x, n - y + 1);
    }
    return 0;
}
/*
2 2
98 100 97 99
2 2
97 100 98 99
2 3
1 2 3 4 5 6
*/