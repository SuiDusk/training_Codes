#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e6+5;
long long l,r;
int prime[MAXN],cnt,ans;
int vis[MAXN];
void Prime(){
    for(int i=2;i<=5e4;i++){
        if(!vis[i])prime[++cnt]=i;
        for(int j=1;i*prime[j]<=50000;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
int main(){
    Prime();
    scanf("%lld %lld",&l,&r);
    l=l==1?2:l;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=cnt;i++){
        long long p=prime[i],start=(l+p-1)/p*p>2*p?(l+p-1)/p*p:2*p;
        for(long long j=start;j<=r;j+=p){
            vis[j-l+1]=1;
        }
    }
    for(int i=1;i<=r-l+1;i++){
        if(!vis[i]) ans++;
    }
    printf("%d\n",ans);
    return 0;
}