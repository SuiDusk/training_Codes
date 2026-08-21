#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 2e5+5;
int n;
int a[MAXN];
int f[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        f[i]=max(f[i-1]+a[i],a[i]);
    }
    int ans=-1e5;
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}