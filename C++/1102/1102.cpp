#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int MAXN = 2e5+5;

int n,c;
int a[MAXN];
map<int,int> mp;

int main(){
    scanf("%d %d",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mp[a[i]]++;
        a[i]-=c;
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=mp[a[i]];
    printf("%lld\n",ans);
    return 0;
}