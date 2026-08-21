#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 105;
int n,q;
int sz[MAXN];
int dp[MAXN][MAXN];
class Node{
public:
    int v,w;
    Node(){v=0,w=0;}
    Node(int v,int w):v(v),w(w){}
};
vector<Node> g[MAXN];
void dfs(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(v==fa) continue;
        dfs(v,u);sz[u]+=sz[v]+1;
        for(int j=min(sz[u],q);j>=0;j--){
            for(int k=min(sz[v],j-1);k>=0;k--){
                dp[u][j]=max(dp[u][j],dp[u][j-k-1]+dp[v][k]+g[u][i].w);
            }
        }
    }
    return;
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(Node(v,w));
        g[v].push_back(Node(u,w));
    }
    dfs(1,0);
    printf("%d\n",dp[1][q]);
    return 0;
}