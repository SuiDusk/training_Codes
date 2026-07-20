#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 5e4+5;

int L,n,m;
int a[MAXN];

int check(int x)
{
    int cnt=0,last=0;
    for(int i=1;i<=n;i++){
        if(a[i]-last<x)
            cnt++;
        else
            last=a[i];
        if(cnt>m) break;
    }
    // if(a[n]!=last) return false;
    return cnt<=m;
}

int main(){
    scanf("%d %d %d",&L,&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[0]=0;a[n+1]=L;
    n++;
    int l=1,r=L;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",l-1);
    return 0;
}