#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 205;
int n;
int val[MAXN][MAXN];
int dp[MAXN][MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            scanf("%d",&dp[i][j]);
        }
    }//val[i][j]表示从i到j的价格
    for(int i=3;i<=n;i++){
        for(int j=2;j<i;j++){
            dp[1][i]=min(dp[1][i],dp[1][j]+dp[j][i]);
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}