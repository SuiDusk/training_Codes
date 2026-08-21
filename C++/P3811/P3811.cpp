#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 3e6+5;
long long n,mod;
long long inv[MAXN];
void get_inv(){
    inv[0]=inv[1]=1;
    for(int i=2;i<=n;i++){
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    }
    return ;
}
int main(){
    scanf("%lld %lld",&n,&mod);
    get_inv();
    for(int i=1;i<=n;i++){
        printf("%lld\n",inv[i]);
    }
    return 0;
}