#include <iostream>
#include <cstdio>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 5e5+5;
int n;
long long fac[MAXN];
long long fac_inv[MAXN];
int a[MAXN];
long long ans=0;
long long quick_pow(long long a,long long b){
    if(b==0) return 1;
    return (((b&1)?a:1)*quick_pow(a*a%MOD,b>>1)%MOD)%MOD;
}
int main(){
    fac[0]=fac[1]=1;
    for(int i=2;i<=5e5;i++){
        fac[i]=fac[i-1]*i;
        fac[i]%=MOD;
    }
    for(int i=0;i<=5e5;i++){
        fac_inv[i]=quick_pow(fac[i],MOD-2);
    }
    scanf("%d",&n);
    n-=2;int x;
    for(int i=1;i<=n+2;i++){
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<=n;i++){
        if(n%i==0&&a[i]&&a[n/i]){
            int x=i,y=n/i;
            a[x]--,a[y]--;
            long long now=fac[n];
            for(int j=1;j<=5e5;j++){
                if(a[j])
                    now=now*fac_inv[a[j]]%MOD;
            }
            ans=(ans+now)%MOD;
            a[x]++;a[y]++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}