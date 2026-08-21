#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 35;
int n,m;
int a[MAXN][MAXN];
int main(){
    scanf("%d %d",&n,&m);
    a[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i&1||j&1)&&(i!=1||j!=1))
				a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    printf("%d\n",a[n][m]);
    return 0;
}