#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 305;

int n;
int a[MAXN];
long long ans;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    ans+=a[r]*a[r];
    int index=r;
    while(l<=r) {
        if(index==r) {
            ans+=(a[r]-a[l])*(a[r]-a[l]);
            r--;
            index=l;
        } else {
            ans+=(a[r]-a[l])*(a[r]-a[l]);
            l++;
            index=r;
        }
    }
    printf("%lld\n",ans);
    return 0;
}