#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e4+5;
int n;
int a[MAXN];
int dp[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) dp[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}