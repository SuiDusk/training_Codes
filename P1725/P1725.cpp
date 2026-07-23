#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 2e5+5;
int n,l,r;
int ans=-1e9;
int a[MAXN];
int dp[MAXN];
deque<int> q;
int main(){
    scanf("%d %d %d",&n,&l,&r);
    for(int i=0;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,128,sizeof(dp));
    dp[0]=0;
    for(int i=l;i<=n;i++){
        while(!q.empty()&&dp[i-l]>=dp[q.back()]) q.pop_back();
        q.push_back(i-l);
        while(q.front()+r<i) q.pop_front();
        dp[i]=dp[q.front()]+a[i];
        if(i+r>n) ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}

/*
0 12 3 11 7 -2
*/