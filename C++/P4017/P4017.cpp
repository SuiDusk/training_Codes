#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int MAXN = 5e3+5;
const int MOD = 80112002;
int n,m;
int ru[MAXN];
int chu[MAXN];
ll dis[MAXN];
vector<int> g[MAXN];
queue<int> q;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[v].push_back(u);
        ru[u]++;
        chu[v]++;
    }
    for(int i=1;i<=n;i++){
        if(ru[i]==0){
            q.push(i);
            dis[i]=1;
        }
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        int sz=g[t].size();
        for(int i=0;i<sz;i++){
            int v=g[t][i];
            dis[v]+=dis[t];
            dis[v]%=MOD;
            ru[v]--;
            if(ru[v]==0) q.push(v);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(chu[i]==0)
            ans+=dis[i],ans%=MOD;
    }
    printf("%lld\n",ans);
    return 0;
}