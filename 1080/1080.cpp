#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e3+5;

int n;
int s1,s2;
long long ans;

class priminist{
public:
long long a,b;
static bool cmp(priminist x, priminist y){
    if((x.a*y.b)<(y.a*x.b)) return true;
    if((x.a*y.b)>(y.a*x.b)) return false;
    return x.a<y.a;
}
};

priminist p[MAXN];

int main(){
    scanf("%d",&n);
    scanf("%d %d",&s1,&s2);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&p[i].a,&p[i].b);
    }
    sort(p+1,p+1+n,priminist::cmp);
    p[0].a=s1,p[0].b=s2;
    for(int i=1;i<=n;i++)
    {
        p[i].a*=p[i-1].a;
        ans=max(ans,p[i-1].a/p[i].b);
    }
    printf("%lld\n",ans);
    return 0;
}