#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e5+5;
int n,m;
int vis[MAXN];
vector<int> g[MAXN];
void dfs(int x){
    vis[x]=1;
    printf("%d ",x);
    for(int i=0;i<g[x].size();i++){
        if(!vis[g[x][i]])
            dfs(g[x][i]);
    }
}
void bfs(){
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        printf("%d ",t);
        for(int i=0;i<g[t].size();i++){
            if(!vis[g[t][i]])
                q.push(g[t][i]),vis[g[t][i]]=1;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
    }
    memset(vis,0,sizeof(vis));
    dfs(1);
    putchar('\n');
    memset(vis,0,sizeof(vis));
    bfs();
    putchar('\n');
    return 0;
}