#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e6;

int n,m;
int a[MAXN];
long long pre[MAXN];

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    int l=0,r=4e5;
    while(l<=r){
        int mid=(l+r)/2;
        int index=lower_bound(a+1,a+n+1,mid)-a;
        long long sum=pre[n]-pre[index-1]-1LL*(n-index+1)*mid;
        if(sum>=m) l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",r);
    return 0;
}