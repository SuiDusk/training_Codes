#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;
const int MAXN = 1e5+5;
const int INF = 2147483647;
int n=1;
int len;
int a[MAXN];
int dp[MAXN];
int f[MAXN];
int main(){
    // while(scanf("%d",&a[n])!=EOF){
    //     dp[n]=1;
    //     f[1]=max(a[n],f[1]);
    //     n++;
    // }
    // n--;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i]=0;
    }
    f[0]=INF;len=0;
    for(int i=1;i<=n;i++){
        int l=0,r=len+1;
        while(l+1<r){
            int mid=(l+r)/2;
            if(f[mid]>=a[i]) l=mid;
            else r=mid;
        }
        if(r>len) len=r;
        f[r]=a[i];
    }
    printf("%d\n",len);
    len=0;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        int l=0,r=len+1;
        while(l+1<r){
            int mid=(l+r)/2;
            if(f[mid]<a[i]) l=mid;
            else r=mid;
        }
        if(r>len) len=r;
        f[r]=a[i];
    }
    printf("%d\n",len);
}
/*
8
389 207 155 300 299 170 158 65
*/