#include <iostream>
#include <cstdio>
using namespace std;
long long n,k,m;
int check(long long x){
    long long temp=n;
    for(int i=1;i<=m;i++){
        temp=(long long)((double)temp-1.0*temp*k/100);
        temp-=x;
        if(temp<0) return 0;
    }
    return 1;
}
int main(){
    scanf("%lld %lld %lld",&n,&k,&m);
    long long l=1,r=n;
    while(l<=r){
        long long mid=(l+r)>>1;
        // printf("%d\n",mid);
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%lld\n",l-1);
    return 0;
}