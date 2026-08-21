#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5+5;

int L,n,k;

int a[MAXN];

int check(int x){
    int cnt=0;
    int index=0;
    for(int i=1;i<=n;i++){
        if(cnt>k) break;
        if(a[i]-index<=x)
            index=a[i];
        else   
            index+=x,i--,cnt++;
    }
    return cnt<=k;
}

int main(){
    scanf("%d %d %d",&L,&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=1,r=L;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",r+1);
    return 0;
}