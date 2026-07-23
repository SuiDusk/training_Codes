#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 1e4+5;
int n,m;
class mat{
public:
    int t,x,y;
    mat(){t=0,x=0,y=0;}
};
mat a[MAXN];
int dp[MAXN];
int dist(int x,int y){
    return fabs(a[x].x-a[y].x)+abs(a[x].y-a[y].y);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a[i].t,&a[i].x,&a[i].y);
    }
    for(int i=1;i<=m;i++) dp[i]=1;
    for(int i=1;i<=m;i++){
        for(int j=i-1;j>=1;j--){
            if(dist(i,j)<=a[i].t-a[j].t){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++) ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}