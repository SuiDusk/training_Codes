#include <iostream>
using namespace std;
const int MAXN = 105;
int n,m;
int a[MAXN];
int dp[10005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        for(int j=i;j<=n;j++){
            dp[j]=max(dp[j],dp[j-i]+a[i]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}