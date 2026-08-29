#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int a, b, z;
int fa[200005];

void makeSet()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    return;
}

int findSet(int x)
{
    if (fa[x] != x)
        fa[x] = findSet(fa[x]);
    return fa[x];
}

bool unionSet(int a, int b)
{
    int u = findSet(a), v = findSet(b);
    if (u == v)
        return false;
    fa[u] = v;
    return true;
}

void read_int(int &x)
{
    x = 0;
    char s = getchar();
    int f = 1;
    while (!isdigit(s))
    {
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while (isdigit(s))
    {
        x = (x << 3) + (x << 1) + s - 48;
        s = getchar();
    }
    x *= f;
    return;
}

int main()
{
    read_int(n), read_int(m);
    makeSet();
    for (int i = 1; i <= m; i++)
    {
        read_int(z), read_int(a), read_int(b);
        if (z == 1)
            unionSet(a, b);
        else if (findSet(a) == findSet(b))
            printf("Y\n");
        else
            printf("N\n");
    }
}