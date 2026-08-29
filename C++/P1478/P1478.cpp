#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
struct st
{
    int t, l;
} m[5005];
int n, s, a, b, sum;
bool cmp(const st &x, const st &y)
{
    if (x.l > y.l || (x.l == y.l && x.t > y.t))
        return 0;
    else
        return 1;
}
int main()
{
    cin >> n >> s >> a >> b;
    a += b;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i].t >> m[i].l;
    }
    sort(m, m + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (s >= m[i].l && a >= m[i].t)
            s -= m[i].l, sum++;
    }
    cout << sum << endl;
}