#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1e5+5;
int n;
long long sum;
long long temp,ans;
long long c[MAXN];
long long sz[MAXN];
class Node{
public:
    long long v,w,sz;
    Node(long long v,long long w):v(v),w(w),sz(0){}
    Node(){};
};
vector<Node> g[MAXN];
long long dp[MAXN];
void dfs(int u,int fa){
    sz[u]=c[u];
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        // g[u][i].sz=sz[v];
        // printf("dp[%d]+=(sz[%d]*g[%d][%d].w+dp[%d]);\n",u,v,u,i,v);
        dp[u]+=(sz[v]*g[u][i].w+dp[v]);
    }
}
/*
dp[u]=sz[v]*g[u][i].w+dp[v];
*/
void dfs1(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(v==fa) continue;
        temp-=sz[v]*g[u][i].w;
        temp+=(sum-sz[v])*g[u][i].w;
        // printf("temp=%d,ans=%d\n",temp,ans);
        ans=min(ans,temp);
        dfs1(v,u);
        temp-=(sum-sz[v])*g[u][i].w;
        temp+=sz[v]*g[u][i].w;
    }
    return ;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
        sum+=c[i];
    }
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(Node(v,w));
        g[v].push_back(Node(u,w));
    }
    dfs(1,1);
    temp=dp[1];
    ans=1e18;
    dfs1(1,1);
    // for(int i=1;i<=n;i++){
    //     printf("sz[%d]=%d\n",i,sz[i]);
    // }
    // for(int i=1;i<=n;i++){
    //     printf("dp[%d]=%d\n",i,dp[i]);
    // }
    printf("%lld\n",ans);
    return 0;
}
/*
5 
1 
1 
0 
0 
2 
1 3 1 
2 3 2 
3 4 3 
4 5 3 
*/