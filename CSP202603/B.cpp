#include <iostream>
#include <vector>
using namespace std;
int n,m;
int sum;
double dp[1005];
vector<pair<int,double> >g;
int main(){
    scanf("%d %d",&n,&m);
    int op,t,a,b;
    for(int i=1;i<=n;i++){
        scanf("%d",&op);
        if(op==0){
            scanf("%d %d %d",&t,&a,&b);
            for(int j=1;j<=a;j++){
                g.push_back(pair<int,double>(1,(double)b/a));
            }
        } else {
            scanf("%d %d %d",&t,&a,&b);
            g.push_back(pair<int,double>(a,b));
        }
        sum+=t;
    }
    for(int i=0;i<=g.size();i++){
        for(int j=m;j>=g[i].first;j--){
            dp[j]=max(dp[j],dp[j-g[i].first]+g[i].second);
        }
    }
    printf("%.6lf\n",1.0*sum-dp[m]);
    return 0;
}