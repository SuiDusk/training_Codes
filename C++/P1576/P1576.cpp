#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 2005;
class Edge{
public:
    int v,w;
    Edge(){v=0,w=0;}
    Edge(int v,int w):v(v),w(w){}
};
struct Node{
    double x;
    int u;
    Node(){x=0,u=0;}
    Node(double x,int u):x(x),u(u){}
    bool operator < (Node t)const{
        return x<t.x;
    }
};
int n,m;
int st,ed;
int vis[MAXN];
double dis[MAXN];
vector<Edge> g[MAXN];
void bfs(int x){
    priority_queue<Node> q;
    q.push(Node(1,x));
    while(!q.empty()){
        Node t=q.top();
        q.pop();
        // printf("%lf\n",t.x);
        int sz=g[t.u].size(),u=t.u;
        if(vis[u]) continue;
        vis[u]=1;
        // printf("%d\n",u);
        for(int i=0;i<sz;i++){
            int v=g[u][i].v,w=g[u][i].w;
            // printf("%d %d %lf\n",u,v,dis[u]*(100-w)/100);
            if(!vis[v]&&dis[v]<dis[u]*(100-w)/100){
                dis[v]=dis[u]*(100-w)/100;
                q.push(Node(dis[v],v));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(Edge(v,w));
        g[v].push_back(Edge(u,w));
    }
    scanf("%d%d",&st,&ed);
    dis[st]=1;
    bfs(st);
    printf("%.8lf",100.0/dis[ed]);
    return 0;
}