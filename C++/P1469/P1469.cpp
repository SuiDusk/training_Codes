#include <iostream>
#include <cstdio>
using namespace std;
int n,t;
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        ans^=t;
    }
    printf("%lld\n",ans);
    return 0;
}