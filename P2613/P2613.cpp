#include <iostream>
#include <cstdio>
using namespace std;
const int MOD = 19260817;
int a,b;
long long x,y;
int read()
{
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){ if(s=='-') f=-1; s=getchar(); }
	while(isdigit(s)){ x=(x<<3)+(x<<1)+(s^'0'); x%=MOD; s=getchar(); }
	return x*f;
}
void exgcd(int A,int B){
    if(B==0){
        x=1,y=0;
        return ;
    }
    exgcd(B,A%B);
    long long t=x;
    x=y,y=t-A/B*y;
    return ;
}
int main(){
    a=read(),b=read();
    if(b==0){
        printf("Angry!\n");
        return 0;
    }
    exgcd(b,MOD);
    x=(x%MOD+MOD)%MOD;
    printf("%lld\n",(1LL*a*x)%MOD);
    return 0;
}