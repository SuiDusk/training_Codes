#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int m, n, a[30005], sum;
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (a[j] + a[i] <= m)
            sum++, i++, j--;
        else
            sum++, j--;
    }
    cout << sum;
}