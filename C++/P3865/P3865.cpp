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
    tree[k].sum = max(tree[k << 1].sum, tree[k << 1 | 1].sum);
    return;
}
int query(int k)
{
    if (l <= tree[k].l && tree[k].r <= r)
    {
        return tree[k].sum;
    }
    int mid = tree[k].l + tree[k].r >> 1;
    return max((l <= mid) ? query(k << 1) : 0, (mid < r) ? query(k << 1 | 1) : 0);
}

signed main()
{
    scanf("%lld %lld", &n, &m);
    build(1, 1, n);
    while (m--)
    {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", query(1));
    }
    return 0;
}