#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
const int MAXN = 2e5+5;
int T;
int n;
int a[MAXN];
int main(){
    scanf("%d",&T);
    while(T--){
        map<ll,int> cnt;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        ll ans=0,prev=-2,prev_cnt=0;
        for(auto &p:cnt){
            ll cur=p.first,
            cur_cnt=p.second;
            if(cur!=prev+1){
                ans+=cur_cnt;
            } else {
                if(cur_cnt>prev_cnt){
                    ans+=cur_cnt-prev_cnt;
                }
            }
            prev=cur;
            prev_cnt=cur_cnt;
        }
        printf("%lld\n",ans);
    }
    return 0;
}