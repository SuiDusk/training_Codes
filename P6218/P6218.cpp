#include <iostream>
#include <cstdio>
using namespace std;
int len;
int a[50];
int f[50][65];
int vis[50][65];
int dfs(int limit,int lead,int pos,int dist){
    if(pos==0) return dist>=30;
    if(!limit&&!lead&&vis[pos][dist]) return f[pos][dist];
    int res=0;
    int up=limit?a[pos]:1;
    for(int i=0;i<=up;i++){
        res+=dfs(limit&(i==a[pos]),lead&(i==0),pos-1,dist+(i==0?(lead?0:1):-1));
    }
    if(!limit&&!lead) vis[pos][dist]=1,f[pos][dist]=res;
    return res;
}
int solve(int x){
    len=0;
    while(x){
        len++;
        a[len]=x%2;
        x/=2;
    }
    return dfs(1,1,len,30);
}
int main(){
    int l,r;
    scanf("%d %d",&l,&r);
    printf("%d\n",solve(r)-solve(l-1));
    return 0;
}