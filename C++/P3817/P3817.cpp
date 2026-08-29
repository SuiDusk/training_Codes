#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

const int MAXX = 2e5 + 5;

int n, x;
int a[MAXX];

ll ans = 0;

int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] + a[i - 1] > x)
        {
            if (a[i - 1] <= x)
            {
                ans += a[i - 1] + a[i] - x;
                a[i] -= a[i - 1] + a[i] - x;
            }
            else
            {
                ans += a[i];
                a[i] = 0;
                ans += a[i - 1] - x;
                a[i - 1] = x;
            }
        }
    }
    cout << ans << endl;
    return 0;
}