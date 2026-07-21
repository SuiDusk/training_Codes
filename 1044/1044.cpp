#include <iostream>
#include <cstdio>

using namespace std;

int dp[20][20];
int n;

int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++){
            if(!i) dp[i][j]=1;
            else if(!j) dp[i][j]=dp[i-1][j+1];
            else dp[i][j]=dp[i-1][j+1]+dp[i][j-1];
    }
    printf("%d\n",dp[n][0]);
    return 0;
}