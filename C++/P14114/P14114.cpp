#include <iostream>
#include <cstdio>
using namespace std;
int T;
int n, m, x1, y, x2, y2;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d%d%d", &n, &m, &x1, &y, &x2, &y2);
        if (x1 == x2 && y == y2)
        {
            printf("0\n");
            continue;
        }
        if (abs(x2 - x1) <= 1 && abs(y2 - y) <= 1)
        {
            printf("1\n");
            continue;
        }
        if (x1 == x2)
        {
            if (abs(y2 - y + 1) % 2)
            {
                if (abs(y2 - y) <= max(x1 - 1, n - x1) * 2)
                {
                    printf("2\n");
                    continue;
                }
            }
            else
            {
                if (abs(y2 - y) <= max(x1 - 1, n - x1))
                {
                    printf("2\n");
                    continue;
                }
            }
        }
        else if (y == y2)
        {
            if (abs(x2 - x1 + 1) % 2)
            {
                if (abs(x2 - x1) <= max(y - 1, m - y) * 2)
                {
                    printf("2\n");
                    continue;
                }
            }
            else
            {
                if (abs(x2 - x1) <= max(y - 1, m - y))
                {
                    printf("2\n");
                    continue;
                }
            }
        }
        else
        {
            printf("2\n");
            continue;
        }
        printf("3\n");
    }
    return 0;
}