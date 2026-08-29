#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 105;
int T;
int n;
int a[MAXN][MAXN];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        int st;
        if (a[1][1] == a[2][1] && a[2][1] == a[3][1])
        {
            st = a[1][1];
        }
        else
        {
            if (a[1][1] == a[2][1])
            {
                st = a[1][1];
            }
            else
            {
                if (a[1][1] == a[3][1])
                {
                    st = a[1][1];
                }
                else
                {
                    st = a[2][1];
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i][1] != st)
            {
                printf("%d ", st);
                for (int j = 1; j < n; j++)
                {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}