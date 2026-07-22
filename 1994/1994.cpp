#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e3+5;
int n;
int dp[MAXN][MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&dp[i][j]);
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1){
                dp[i][j]+=dp[i-1][j];
            }
            else if(j==i){
                dp[i][j]+=dp[i-1][j-1];
            }
            else {
                dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(dp[n][i],ans);
    }
    printf("%d\n",ans);
    return 0;
}