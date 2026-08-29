#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

const int MAXX = 1e5 + 5;

int n, t;
int Weight[MAXX];
int Value[MAXX];

double ans;

int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> Weight[i] >> Value[i];
    }
    while (t > 0)
    {
        int index = 0;
        double maxvalue = -1;
        for (int i = 1; i <= n; i++)
        {
            if (maxvalue < Value[i] * 1.0 / Weight[i])
            {
                maxvalue = Value[i] * 1.0 / Weight[i];
                index = i;
            }
        }
        if (maxvalue == -1 || maxvalue == 0)
            break;
        if (t >= Weight[index])
        {
            t -= Weight[index];
            ans += Value[index];
            Weight[index] = 0;
            Value[index] = 0;
        }
        else
        {
            ans += 1.0 * Value[index] * t / Weight[index];
            t = 0;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}