#include <iostream>
using namespace std;

const int MAXN = 5e5+5;;

int e[MAXN], ne[MAXN], pos[MAXN], pre[MAXN];
int idx;
int q;

void init() {
    e[0] = 1;
    ne[0] = -1;
    pos[1] = 0;
    idx = 1;
}

void insert(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    pos[x] = idx;
    idx++;
}

void delete_after(int k) {
    if (ne[k] != -1) {
        ne[k] = ne[ne[k]];
    }
}

int main() {
    scanf("%d",&q);
    init();
    int op, x, y;
    while (q--) {
        scanf("%d",&op);
        if (op == 1) {
            scanf("%d %d",&x,&y);
            insert(pos[x], y);
        } else if (op == 2) {
            scanf("%d",&x);
            int nxt = ne[pos[x]];
            if (nxt == -1)
                printf("0\n");
            else
                printf("%d\n",e[nxt]);
        } else {
            scanf("%d",&x);
            delete_after(pos[x]);
        }
    }
    return 0;
}