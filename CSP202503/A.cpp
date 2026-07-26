#include <iostream>
using namespace std;
int b,c,l,r;
long long ans=0;
int main(){
    scanf("%d %d %d %d",&b,&c,&l,&r);
    if(l%2==1) l++;
    while(l<=r){
        ans+=1LL*2*(l*l+b*l+c);
        l+=2;
    }
    printf("%lld\n",ans);
    return 0;
}