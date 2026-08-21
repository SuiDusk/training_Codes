#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5+5;

int a[MAXN];

int n;
int ans;
int minn=1e9;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) {
        if(a[i]>a[i-1]) {
            ans+=a[i]-a[i-1];
        }
    }
    printf("%d\n",ans);
    return 0;
}