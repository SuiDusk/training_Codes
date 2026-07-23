#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,m;
int a[105][1005];
bool vis[1000005];
class Node{
public:
    int s;
    int step;
    Node(int s,int step):s(s),step(step){}
    Node(){}
};
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int ss=0;
    queue<Node> q;
    q.push(Node((1<<n)-1,0));
    vis[(1<<n)-1]=true;
    while(!q.empty()){
        Node u=q.front();
        q.pop();
        if(u.s==0){
            printf("%d\n",u.step);
            return 0;
        }
        for(int i=1;i<=m;i++){
            ss=u.s;
            for(int j=1;j<=n;j++){
                if(a[i][j]==1&&(ss&(1<<j-1))) ss^=(1<<j-1);
                else if(a[i][j]==-1&&!(ss&(1<<j-1))) ss|=(1<<j-1);
            }
            if(!vis[ss]){
                q.push(Node(ss,u.step+1));
                vis[ss]=true;
            }
        }
    }
    printf("-1\n");
    return 0;
}