#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXX = 1e5;

int p;
int n, q;

ll a[MAXX + 5];

struct node
{
    ll sum, mul, add;
} tree[MAXX * 4 + 5];

void build(int k, int l, int r)
{
    tree[k].mul = 1, tree[k].add = 0;
    if (l == r)
        tree[k].sum = a[l];
    else
    {
        int m = (l + r) / 2;
        build(k * 2, l, m);
        build(k * 2 + 1, m + 1, r);
        tree[k].sum = tree[k * 2].sum + tree[k * 2 + 1].sum;
    }
    tree[k].sum %= p;
    return;
}

void pd(int k, int l, int r)
{
    int m = (l + r) / 2;
    tree[k * 2].sum = (tree[k * 2].sum * tree[k].mul + tree[k].add * (m - l + 1)) % p;
    tree[k * 2 + 1].sum = (tree[k * 2 + 1].sum * tree[k].mul + tree[k].add * (r - m)) % p;
    tree[k * 2].mul = (tree[k * 2].mul * tree[k].mul) % p;
    tree[k * 2 + 1].mul = (tree[k * 2 + 1].mul * tree[k].mul) % p;
    tree[k * 2].add = (tree[k * 2].add * tree[k].mul + tree[k].add) % p;
    tree[k * 2 + 1].add = (tree[k * 2 + 1].add * tree[k].mul + tree[k].add) % p;
    tree[k].mul = 1;
    tree[k].add = 0;
    return;
}

void updata1(int k, int L, int R, int l, int r, ll x)
{
    if (r < L || R < l)
        return;
    if (l <= L && R <= r)
    {
        tree[k].sum = (tree[k].sum * x) % p;
        tree[k].mul = (tree[k].mul * x) % p;
        tree[k].add = (tree[k].add * x) % p;
        return;
    }
    pd(k, L, R);
    int m = (L + R) / 2;
    updata1(k * 2, L, m, l, r, x);
    updata1(k * 2 + 1, m + 1, R, l, r, x);
    tree[k].sum = (tree[k * 2].sum + tree[k * 2 + 1].sum) % p;
    return;
}

void updata2(int k, int L, int R, int l, int r, ll x)
{
    if (r < L || R < l)
        return;
    if (l <= L && R <= r)
    {
        tree[k].add = (tree[k].add + x) % p;
        tree[k].sum = (tree[k].sum + x * (R - L + 1)) % p;
        return;
    }
    pd(k, L, R);
    int m = (L + R) / 2;
    updata2(k * 2, L, m, l, r, x);
    updata2(k * 2 + 1, m + 1, R, l, r, x);
    tree[k].sum = (tree[k * 2].sum + tree[k * 2 + 1].sum) % p;
    return;
}

ll query(int k, int L, int R, int l, int r)
{
    if (r < L || R < l)
        return 0;
    if (l <= L && R <= r)
        return tree[k].sum;
    pd(k, L, R);
    int m = (L + R) / 2;
    return (query(k * 2, L, m, l, r) + query(k * 2 + 1, m + 1, R, l, r)) % p;
}

int main()
{
    scanf("%d %d %d", &n, &q, &p);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    build(1, 1, n);
    while (q--)
    {
        int op;
        int x, y;
        ll k;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d %d %lld", &x, &y, &k);
            updata1(1, 1, n, x, y, k);
        }
        else if (op == 2)
        {
            scanf("%d %d %lld", &x, &y, &k);
            updata2(1, 1, n, x, y, k);
        }
        else
        {
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }
        //		for(int i=1;i<n;i++)
        //			printf("%lld ",query(1,1,n,i,i));
        //		printf("%lld\n",query(1,1,n,n,n));
    }
    return 0;
}