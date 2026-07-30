#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e6+5;
class Edge{
public:
    int u,v,w;
    Edge(){u=0,v=0,w=0;}
    Edge(int u,int v,int w):u(u),v(v),w(w){}
    bool operator < (const Edge x)const{
        return w<x.w;
    }
}edge[MAXN];
int cnt;
int n,m;
int f[MAXN];
int ans;
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
int bind(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        f[fx]=f[fy];
        return 1;
    }
    return 0;
}
void kruskal(){
    int tot=0;
    for(int i=1;i<=cnt&&tot<=n;i++){
        if(bind(edge[i].u,edge[i].v)){
            tot++;
            ans+=edge[i].w;
        }
    }
}
int main(){
    scanf("%d%d",&m,&n);
    int t=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&t);
            if(i<j&&t!=0)
                edge[++cnt]=Edge(i,j,t);
        }
    }
    for(int i=1;i<=n;i++){
        edge[++cnt]=Edge(0,i,m);
    }
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    sort(edge+1,edge+1+cnt);
    kruskal();
    printf("%d\n",ans);
    return 0;
}