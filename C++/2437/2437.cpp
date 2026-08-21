#include <iostream>
#include <cstdio>

using namespace std;

int m,n;
int f[1005][1005];

void _p(int x){
    for(int i=0;i<=1000;i++){
        f[x][i]+=f[x-1][i]+f[x-2][i];
        f[x][i+1]=f[x][i]/10;
        f[x][i]%=10;
    }
    return ;
}

int main(){
    scanf("%d %d",&m,&n);
    f[m][0]=1;
    f[m+1][0]=1;
    for(int i=m+2;i<=n;i++){
        _p(i);
    }
    int tap=0;
    for(int i=1000;i>=0;i--){
        if(tap) printf("%d",f[n][i]);
        else if(f[n][i]!=0) tap=1,printf("%d",f[n][i]);
    }
    return 0;
}