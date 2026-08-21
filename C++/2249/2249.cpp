#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e6+5;

int n,m;
int a[MAXN];

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int x,y;
    while(m--){
        scanf("%d",&x);
        y=lower_bound(a+1,a+1+n,x)-a;
        if(a[y]!=x) printf("-1 ");
        else printf("%d ",y);
    }
    return 0;
}