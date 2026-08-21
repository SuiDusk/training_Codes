#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
const int MAXN = 1e4+5;
int n,m;
long long dis[MAXN];
int vis[MAXN];
int num[MAXN];int cnt[MAXN];
struct Node{
    int v,w;
    Node(){}
    Node(int v,int w):v(v),w(w){};
};
vector<Node> g[MAXN];
queue<int> q;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int op,a,b,c;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%d",&a,&b,&c);
            g[a].push_back(Node(b,-c));
        } else if(op==2){
            scanf("%d%d%d",&a,&b,&c);
            g[b].push_back(Node(a,c));
        } else {
            scanf("%d%d",&a,&b);
            g[a].push_back(Node(b,0));
            g[b].push_back(Node(a,0));
        }
    }
    for(int i=1;i<=n;i++){
        g[n+1].push_back(Node(i,0));
    }
    n++;
    for(int i=1;i<=n;i++){
        dis[i]=2e8;
    }
    dis[n]=0;
    q.push(n);
    num[n]++;
    vis[n]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].v,w=g[u][i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v] >= n){
                    printf("No\n");
                    return 0;
                }
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    printf("Yes\n");
    return 0;
}