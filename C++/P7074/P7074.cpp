#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1005;
const int INF = 2147483647;
int n,m;
int mp[MAXN][MAXN];
int vis[MAXN][MAXN];
int rem[MAXN][MAXN];
int dfs(int x,int y){
    if(x==n&&y==m){
        rem[n][m]=mp[n][m];
        vis[n][m]=1;
        return mp[n][m];
    }
    int cnt=-INF;
    for(int i=1;i<=3;i++){
        switch(i){
            case 1:{
                if(x<=1) continue;
                if(vis[x-1][y]==1) cnt=max(cnt,rem[x-1][y]);
                else if(vis[x-1][y]==0) vis[x-1][y]=-1,cnt=max(cnt,dfs(x-1,y));
            }
            case 2:{
                if(y>=m) continue;
                if(vis[x][y+1]==1) cnt=max(cnt,rem[x][y+1]);
                else if(vis[x][y+1]==0) vis[x][y+1]=-1,cnt=max(cnt,dfs(x,y+1));
            }
            case 3:{
                if(x>=n) continue;
                if(vis[x+1][y]==1) cnt=max(cnt,rem[x+1][y]);
                else if(vis[x+1][y]==0) vis[x+1][y]=-1,cnt=max(cnt,dfs(x+1,y));
            }
        }
    }
    vis[x][y]=1;
    rem[x][y]=cnt+mp[x][y];
    return cnt+mp[x][y];
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    vis[1][1]=-1;
    int ans=dfs(1,1);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",vis[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",rem[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",ans);
    return 0;
}