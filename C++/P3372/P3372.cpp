#include <iostream>
#include <cstdio>

using namespace std;

#define int long long

const int MAXX = 1e5;

struct node
{
    int sum, len, l, r;

    node() { sum = len = l = r = 0; }
};

int n, m;
int l, r;
int ans;
int lazy[(MAXX << 2) + 5];

node tree[(MAXX << 2) + 5];

void f(int k, int x)
{
    lazy[k] += x;
    tree[k].sum += tree[k].len * x;
    return;
}

void push_down(int k)
{
    if (lazy[k] == 0)
        return;
    f(k << 1, lazy[k]);
    f(k << 1 | 1, lazy[k]);
    lazy[k] = 0;
    return;
}

void build(int k, int l, int r)
{
    lazy[k] = 0;
    tree[k].l = l;
    tree[k].r = r;
    tree[k].len = (r - l + 1);
    if (l == r)
    {
        scanf("%lld", &tree[k].sum);
        return;
    }
    int mid = l + r >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
    return;
}

void add(int k, int x)
{
    if (l <= tree[k].l && tree[k].r <= r)
    {
        lazy[k] += x;
        tree[k].sum += tree[k].len * x;
        return;
    }
    push_down(k);
    int mid = tree[k].l + tree[k].r >> 1;
    if (l <= mid)
        add(k << 1, x);
    if (r > mid)
        add(k << 1 | 1, x);
    tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
    return;
}

void query(int k)
{
    if (l <= tree[k].l && tree[k].r <= r)
    {
        ans += tree[k].sum;
        return;
    }
    push_down(k);
    int mid = tree[k].l + tree[k].r >> 1;
    if (l <= mid)
        query(k << 1);
    if (mid < r)
        query(k << 1 | 1);
    return;
}

signed main()
{
    scanf("%lld %lld", &n, &m);
    build(1, 1, n);
    while (m--)
    {
        int op, x;
        scanf("%lld %lld %lld", &op, &l, &r);
        if (op == 1)
        {
            scanf("%lld", &x);
            add(1, x);
        }
        else
        {
            ans = 0;
            query(1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}