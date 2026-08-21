#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5+5;

int n,m;
int a[MAXN];

long long ans;

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    a[0]=a[1];
    a[n+1]=a[n];
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        int l=1,r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[mid]<=x) l=mid+1;
            else r=mid-1;
        }
        ans+=min(abs(x-a[r]),abs(x-a[r+1]));
    }
    printf("%lld\n",ans);
    return 0;
}