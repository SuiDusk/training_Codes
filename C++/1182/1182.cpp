#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5+5;

int n,m;
int l,r=1e9;
int a[MAXN];

int check(int x)
{
    int cnt=0;
    int sum=0;
    for(int i=1;i<=n;i++) {
        if(a[i]>x) {
             cnt=m+1;
             break;
        }
        if(sum+a[i]>x)
            cnt++,sum=a[i];
        else sum+=a[i];
        if(cnt>=m) break;
    }
    return cnt<m;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    l=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",r+1);
    return 0;
}