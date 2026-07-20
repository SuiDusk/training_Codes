#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 2e6+5;

int n,m;
int ans;

class farmer{
public:
    int price;
    int amount;
    static bool cmp(farmer a,farmer b) {
        return a.price<b.price;
    }
};

farmer f[MAXN];

int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++) {
        scanf("%d %d",&f[i].price,&f[i].amount);
    }
    sort(f+1,f+m+1,farmer::cmp);
    for(int i=1;i<=m;i++) {
        if(n<=f[i].amount) {
            ans+=n*f[i].price;
            break;
        } else {
            ans+=f[i].amount*f[i].price;
            n-=f[i].amount;
        }
    }
    printf("%d\n",ans);
    return 0;
}