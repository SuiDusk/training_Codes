#include <iostream>
using namespace std;
const int MAXN = 100005;
#define int long long
int n,D,sum[MAXN],cnt;
struct Node{
    int x,y;
}s[MAXN];
double Ans;
double slope(Node x, Node y){ return 1.0 * (x.y - y.y) / (x.x - y.x); }
signed main(){
    scanf("%lld %lld",&n,&D);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%lld %lld",&x,&y);
        sum[i]=sum[i-1]+x;
        Node t={i*D,sum[i-1]};
        while(cnt>1&&slope(s[cnt-1],s[cnt])>slope(s[cnt],t)) cnt--;
        s[++cnt]=t;
        t={y+i*D,sum[i]};
        int l=1,r=cnt,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(slope(s[mid],t)>slope(s[mid-1],t)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        Ans+=slope(s[ans],t);
    }
    printf("%.0lf\n",Ans);
    return 0;
}