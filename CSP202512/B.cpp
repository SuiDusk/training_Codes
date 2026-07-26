#include <iostream>
using namespace std;
const int MAXN = 1005;
int n,m;
int ans[2000];
int f(int x,int k){
    return (((x*x)+(k*k))%8)^k;
}
int g(int x,int k){
    int c=x&7;
    int b=(x>>3)&7;
    int a=x>>6;
    int a2=b,b2=c^f(b,k),c2=a^f(c,k);
    return (a2<<6)|(b2<<3)|c2;
}
int main(){
    int k[MAXN];
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&k[i]);
    }
    for(int i=0;i<512;i++){
        int x=i;
        for(int j=1;j<=m;j++){
            x=g(x,k[j]);
        }
        ans[x]=i;
    }
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        printf("%d ",ans[x]);
    }
    putchar('\n');
    return 0;
}