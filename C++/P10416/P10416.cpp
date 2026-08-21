#include <iostream>
#include <cstdio>
using namespace std;
int T;
long long l,r;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&l,&r);
        long long t=r-2*l+1;
        if(t<=0)printf("0\n");
        else {
            printf("%lld\n",t*(t+1)/2);
        }
    }
    return 0;
}