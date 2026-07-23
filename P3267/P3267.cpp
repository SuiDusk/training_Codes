#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 5e5+5;
int n,d;
int val[MAXN];
int m;
int b[MAXN];
int f[MAXN][30];
int g[MAXN][30];
vector<int> G[MAXN];
void dfs(int u,int fa){
    if(b[u]) f[u][0]=g[u][0]=val[u];
    else f[u][0]=g[u][0]=0;
    for(int i=1;i<=d;i++){
        f[u][i]=val[u];
    }
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa) continue;
        dfs(v,u);
        for(int j=d;j>=0;j--){
            f[u][j]=min(min(f[u][j]+g[v][j],g[u][j+1]+f[v][j+1]),f[u][j]+f[v][j+1]);
        }
        for(int j=d;j>=0;j--){
            f[u][j]=min(f[u][j+1],f[u][j]);
        }
        for(int j=1;j<=d+1;j++){
            g[u][j]=g[u][j]+g[v][j-1];
        }
        for(int j=1;j<=d+1;j++){
            g[u][j]=min(g[u][j],g[u][j-1]);
        }
    }
    for(int j=d;j>=0;j--){
        f[u][j]=min(f[u][j+1],f[u][j]);
    }
    for(int j=1;j<=d+1;j++){
        g[u][j]=min(g[u][j],g[u][j-1]);
    }
    return ;
}
int main(){
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);b[x]=1;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(f,0x3f,sizeof(f));
    dfs(1,0);
    return 0;
}