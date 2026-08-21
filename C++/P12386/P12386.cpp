#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long n;
long long len=0;
long long a[1000005];
int main(){
    scanf("%lld",&n);
    while((len-1)*len<2*n)len++;
    if(len*(len-1)==2*n){
        printf("%lld\n",len);
        for(int i=len;i>=1;i--){
            printf("%d ",i);
        }
    } else {
        printf("%lld\n",len);
        long long p=(len+1)/2,d=(len*len-len)/2;
        for(int i=1;i<=len;i++){
            a[i]=(i+1)/2;
            // printf("%lld ",a[i]);
        }
        // printf("\n");
        if(n>=d-p){
            int t=d-n;
            for(int i=1;i<=len;i++){
                if(a[i]>d-n) a[i]=++t;
            }
        } else {
            a[len]=len/2-d+p+n;
            int t=a[len-1]+d-p-n;
            for(int i=len-1;t>a[i-1]&&t>1;i--){
                a[i]=t--;
            }
        }
        for(int i=len;i>=1;i--)
            printf("%lld ",a[i]);
    }
    return 0;
}