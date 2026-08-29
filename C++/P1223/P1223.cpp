#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
struct st
{
    int a;
    int n;
} a[1005];
int n;
double m;
bool cmp(const st &x, const st &y)
{
    if (x.a > y.a || (x.a == y.a && x.n > y.n))
        return 0;
    else
        return 1;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].a, a[i].n = i + 1;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            m += a[j].a;
    m = m * 1.0 / n;
    for (int i = 0; i < n; i++)
        cout << a[i].n << " ";
    printf("\n%.2lf", m);
}