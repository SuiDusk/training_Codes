#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1e5+5;
int n,d;
int ans=0;
int vis[MAXN];
vector<int> g[MAXN];
void dfs(int index,int deep){
    if(deep==d) return;
    for(int i=0;i<g[index].size();i++){
        int v=g[index][i];
        if(!vis[v]){
            vis[v]=1;
            ans++;
            dfs(v,deep+1);
        }
    }
}
int main(){
    scanf("%d %d",&n,&d);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[1]=1;
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}