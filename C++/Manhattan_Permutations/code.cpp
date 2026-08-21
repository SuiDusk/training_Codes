#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 2e5+5;
int T;
long long n,k;
int cnt[MAXN];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld %lld",&n,&k);
        if(k%2==1||k>n*n/2){
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        for(int i=1;i<=n;i++){
            cnt[i]=i;
        }
        int l=1,r=n;
        while(k>0){
            if(k>=2*(r-l)){
                k-=2*(r-l);
                swap(cnt[l],cnt[r]);
                l++,r--;
                continue;
            } else {
                int d=k/2;
                swap(cnt[l],cnt[l+d]);
                break;
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d ",cnt[i]);
        }
        printf("\n");
    }
    return 0;
}