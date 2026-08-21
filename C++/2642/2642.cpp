#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e6+5;
int n;
long long a[MAXN];
long long dp1[MAXN];
long long dp2[MAXN];
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long ans=-1e18;
    for(int i=1;i<=n;i++){
        dp1[i]=max(dp1[i-1]+a[i],a[i]);
    }
    for(int i=n;i>=1;i--){
        dp2[i]=max(dp2[i+1]+a[i],a[i]);
    }
    for(int i=2;i<=n;i++){
        dp1[i]=max(dp1[i-1],dp1[i]);
    }
    for(int i=n-1;i>=1;i--){
        dp2[i]=max(dp2[i+1],dp2[i]);
    }
    for(int i=1;i<n-1;i++){
        ans=max(dp1[i]+dp2[i+2],ans);
    }
    printf("%lld\n",ans);
    return 0;
}