#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e6+5;

int n;
int f[MAXN];

int main(){
    scanf("%d",&n);
    f[1]=1,f[2]=2,f[3]=5;
    for(int i=4;i<=n;i++){
        f[i]=(2*f[i-1]+f[i-3])%10000;
    }
    printf("%d",f[n]);
    return 0;
}