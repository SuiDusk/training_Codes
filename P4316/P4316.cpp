#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1e5+5;
class Edge{
public:
    int v,w;
    Edge(){v=0,w=0;}
    Edge(int v,int w):v(v),w(w){}
};
int n,m;
vector<Edge> g[MAXN]; 
int ru[MAXN];
int in[MAXN];
double f[MAXN];
void dfs(int x){
    int sz=g[x].size();
    for(int i=0;i<sz;i++){
        int v=g[x][i].v,w=g[x][i].w;
        f[v]+=1.0*(w+f[x])/in[v];
        ru[v]--;
        if(ru[v]<=0){
            dfs(v);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[v].push_back(Edge(u,w));
        ru[u]++;in[u]++;
    }
    dfs(n);
    printf("%.2lf",f[1]);
    return 0;
}