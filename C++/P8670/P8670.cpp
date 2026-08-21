#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAXN = 1e7+5;
int n;
ll ans;
ll cnt[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=n;i>=1;i--){
        cnt[i]=1LL*(n-n%i)/i*(n-n%i)/i;
        for(int j=2;i*j<=n;j++){
            cnt[i]-=cnt[i*j];
        }
        ans+=(1LL*i*i)%MOD*(cnt[i]%MOD);
        ans%=MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
