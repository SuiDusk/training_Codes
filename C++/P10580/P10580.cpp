#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1e5+5;
const int MOD = 998244353;
struct Node{
    int x,p;
    Node(int _x,int _p){
        x=_x,p=_p;
    }
};
int Q;
int x,y,n;
int len;
int prime[MAXN],cnt;
int vis[MAXN];
vector<Node> g;
void Prime(){
    for(int i=2;i<=100000;i++){
        if(!vis[i]){
            prime[++cnt]=i;
        }
        for(int j=1;i*prime[j]<=100000;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    return ;
}
long long quick_pow(long long x,long long b){
    if(b==0) return 1;
    return ((((b&1)?x:1)%MOD)*(quick_pow((x*x)%MOD,b>>1))%MOD)%MOD;
}
int main(){
    scanf("%d",&Q);
    Prime();
    while(Q--){
        g.clear();
        len=0;
        scanf("%d %d %d",&x,&y,&n);
        int t=y/x;
        for(int i=1;i<=cnt&&t>1;i++){
            if(t%prime[i]==0){
                len++;
                g.push_back(Node(prime[i],0));
                while(t%prime[i]==0){
                    t/=prime[i];
                    g[len-1].p++;
                }
            }
        }
        if(t>1){
            g.push_back(Node(t,1));
            len++;
        }//最重要的一段,因为可能会有一个非常大的质数不在5e4范围之内,这个时候要特判一下
        long long ans=1;
        for(int i=0;i<len;i++){
            long long tmp=quick_pow(g[i].p+1,n)%MOD;
            tmp=(tmp-quick_pow(g[i].p,n))%MOD;
            tmp=(tmp-quick_pow(g[i].p,n))%MOD;
            tmp=(tmp+quick_pow(g[i].p-1,n))%MOD;
            ans=ans*tmp%MOD;
            ans=(ans+MOD)%MOD;
        }
        printf("%lld\n",(ans+MOD)%MOD);
    }
    return 0;
}
// 12=2*2*3; 2,1 (3^3-2*2^3+1^3)*(2^3-2*1^3+0^3);
//27-16+3=14