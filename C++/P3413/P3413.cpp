#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const long long MOD = 1e9+7;
string l,r;
int a[1005];
long long dp[1005][10][2];
int dfs(int pos,int pre,int per,int t,int k,int limit){
    if(pos<=0) return t;
    if(!limit&&dp[pos][pre][t]!=-1) return dp[pos][pre][t];
    int up=limit?a[pos]:9;
    int res=0;
    for(int i=0;i<=up;i++){
        res=(res+dfs(pos-1,   i,   k?pre:-1,   t||((i==pre)&&k)||((i==per)&&k),   k||(i!=0),   limit&&(up==i)   )%MOD)%MOD;
    }
    if(!limit&&k&&per!=-1) dp[pos][pre][t]=res;
    return res;
}
int solve(string s){
    int len=0,slen=s.size()-1;
    while(slen>=0) a[++len]=s[slen]-'0',slen--;
    while(!a[len])len--;
    memset(dp,-1,sizeof(dp));
    return dfs(len,-1,-1,0,0,1);
}
int main(){
    cin>>l>>r;int k=1,len=l.length();
    while(l[len-k]=='0'&&len>k) l[len-k]='9',k++;
    l[len-k]-=1;
    printf("%lld\n",(solve(r)-solve(l)+MOD)%MOD);
    return 0;
}