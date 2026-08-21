#include <iostream>
#include <queue>
using namespace std;
struct Node{
    int x,y,t;
    Node(int _x,int _y,int _t){
        x=_x,y=_y,t=_t;
    }
};
int n,k;
int sx,sy;
int ans=1;
int vis[105][105];
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
queue<Node> q;
int main(){
    scanf("%d %d",&n,&k);
    scanf("%d %d",&sx,&sy);
    vis[sx][sy]=1;
    q.push({sx,sy,0});
    while(!q.empty()){
        Node t=q.front();
        q.pop();
        if(t.t>=k) continue;
        for(int i=0;i<8;i++){
            int tx=t.x+dx[i],ty=t.y+dy[i];
            if(tx<1||ty<1||tx>n||ty>n) continue;
            if(!vis[tx][ty])
                q.push(Node(tx,ty,t.t+1)),ans++,vis[tx][ty]=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}