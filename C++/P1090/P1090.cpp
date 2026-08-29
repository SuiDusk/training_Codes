#include <bits/stdc++.h>
using namespace std;
int k = 1, x, num, n1, n2, a1[30001], a2[30001], t[20001], w, sum;
int main()
{
    scanf("%d", &num);
    memset(a1, 127 / 3, sizeof(a1));
    memset(a2, 127 / 3, sizeof(a2));
    for (int i = 1; i <= num; i++)
    {
        scanf("%d", &x);
        t[x]++;
    }
    for (int i = 1; i <= 20000; i++)
        while (t[i])
        {
            t[i]--;
            a1[++n1] = i;
        }
    int i = 1, j = 1;
    while (k < num)
    {
        if (a1[i] < a2[j])
            w = a1[i++];
        else
            w = a2[j++];
        if (a1[i] < a2[j])
            w += a1[i++];
        else
            w += a2[j++];
        a2[++n2] = w;
        k++;
        sum += w;
    }
    printf("%d", sum);
}