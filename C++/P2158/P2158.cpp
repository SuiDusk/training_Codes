#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 4e5+5;
int n;
int ans;
int phi[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        phi[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(phi[i]==i){
            for(int j=1;i*j<=n;j++){
                phi[j*i]=phi[i*j]*(i-1)/i;
            }
        }
    }
    for(int i=1;i<n;i++){
        ans+=phi[i];
    }
    printf("%d\n",(n==1)?0:ans<<1|1);
    return 0;
}