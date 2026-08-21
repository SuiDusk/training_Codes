#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5;

int n,k;
int l,r;
int ans;
int a[MAXN];

bool check(int x);

int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        r=max(r,a[i]);
    }
    l=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",l-1);
    return 0;
}

bool check(int x){
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i]/x;
    return sum>=k;
}