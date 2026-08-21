#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n,m,a,b;
int mp[505][505];
queue<pair<int,int> > q;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int check(int x,int y);
int main(){
    scanf("%d %d %d %d",&n,&m,&a,&b);
    memset(mp,-1,sizeof(mp));
    for(int i=1;i<=a;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        mp[x][y]=0;
        q.push(pair<int,int>(x,y));
    }
    while(!q.empty()){
        pair<int,int>t=q.front();
        int x=t.first,y=t.second;
        q.pop();
        for(int i=0;i<4;i++){
            int tx=x+dx[i],ty=y+dy[i];
            if(!check(tx,ty)||mp[tx][ty]!=-1) continue;
            mp[tx][ty]=mp[x][y]+1;
            q.push(pair<int,int>(tx,ty));
        }
    }
    for(int i=1;i<=b;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",mp[x][y]);
    }
    return 0;
}

int check(int x,int y){
    if(x<1||x>n||y<1||y>m) return 0;
    return 1;
}