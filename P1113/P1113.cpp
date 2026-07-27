#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e4+5;
int n;
int val[MAXN];
int ru[MAXN];
int pre[MAXN];
vector<int> g[MAXN];
int ti[MAXN];
struct Node{
    int x;
    int _t;
    Node(int _x,int __t){
        x=_x;_t=__t;
    }
};
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int u,v;
        scanf("%d",&v);
        scanf("%d",&val[v]);
        while(1){
            scanf("%d",&u);
            if(u==0) break;
            g[u].push_back(v);
            ru[v]++;
        }
    }
    queue<Node> q;
    for(int i=1;i<=n;i++){
        if(ru[i]==0){
            q.push(Node(i,val[i]));
        }
    }
    while(!q.empty()){
        Node t=q.front();
        q.pop();
        for(int i=0;i<g[t.x].size();i++){
            pre[g[t.x][i]]++;
            ti[g[t.x][i]]=max(ti[g[t.x][i]],t._t+val[g[t.x][i]]);
            if(pre[g[t.x][i]]==ru[g[t.x][i]])
                q.push(Node(g[t.x][i],ti[g[t.x][i]]));
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,ti[i]);
    }
    printf("%d\n",ans);
    return 0;
}