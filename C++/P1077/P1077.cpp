#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 105;
const int MOD = 1e6+7;
int n,m;
int a[MAXN];
int dp[MAXN][MAXN];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            dp[i][j]=1;
        }
    }//初始化
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=a[i];k++){
                if(j>=k){
                    dp[i][j]+=dp[i-1][j-k];
                    dp[i][j]%=MOD;
                }            
            }
        }
    }
    /*
    设i,j,k分别为当前摆到第几种花,摆了之后有多少盆,当前这种花要摆多少盆
    那么当前dp[i][j],从上一个种类的花i-1转移过来,
    */
    printf("%d\n",dp[n][m]);
    return 0;
}