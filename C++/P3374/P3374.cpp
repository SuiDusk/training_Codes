#include <iostream>
#include <cstdio>

using namespace std;

// #define int long long

typedef long long Lint;

const int MAXX = 500000;

int n, q;
int c[MAXX + 5];

void read(int &x)
{
    x = 0;
    int f = 1;
    char s = getchar();
    while (!isdigit(s))
    {
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while (isdigit(s))
    {
        x = (x << 3) + (x << 1) + (s ^ 48);
        s = getchar();
    }
    x *= f;
    return;
}

void print(int x)
{
    if (x < 0)
        x = (~x) + 1, putchar('-');
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + 48);
    return;
}

int lowbit(int x)
{
    return x & (-x);
}

void Add(int k, int x)
{
    for (int i = k; i <= n; i += lowbit(i))
        c[i] += x;
    return;
}

Lint Sum(int k)
{
    Lint sum = 0;
    for (int i = k; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}

int main()
{
    read(n);
    read(q);
    for (int i = 1, x; i <= n; i++)
        read(x), Add(i, x);
    for (int i = 1, u, v, x; i <= q; i++)
    {
        read(x);
        read(u), read(v);
        if (x == 1)
            Add(u, v);
        else
            print(Sum(v) - Sum(u - 1)), putchar('\n');
    }
    return 0;
}