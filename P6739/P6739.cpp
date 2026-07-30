#include <iostream>
#include <cstdio>
#include <cstdio>
#include <map>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 2e6+5;
const int base = 999983;
int n,mid;
string s;
ull pw[MAXN];
ull Hash[MAXN];
ull rt,lt;
map<ull,int> vis;
ull get_hash(int l,int r){
    return Hash[r]-Hash[l-1]*pw[r-l+1];
}
ull re_hash(int l,int r,int pos){
    return get_hash(l,pos-1)*pw[r-pos]+get_hash(pos+1,r);
}
int check(int pos){
    if(pos==mid){
        lt=get_hash(1,pos-1);
        rt=get_hash(pos+1,n);
    } else if(pos<mid){
        lt=re_hash(1,mid,pos);
        rt=get_hash(mid+1,n);
    } else {
        lt=get_hash(1,mid-1);
        rt=re_hash(mid,n,pos);
    }
    return rt==lt;
}
int main(){
    cin>>n>>s;
    if(n%2==0){
        cout<<"NOT POSSIBLE"<<endl;
        return 0;
    }
    s="0"+s;
    mid=(n+1)>>1;
    pw[0]=1;
    string s1=s.substr(mid+1,n);
    string s2=s.substr(1,mid-1);
    for(int i=1;i<=n;i++){
        pw[i]=pw[i-1]*base;
        Hash[i]=Hash[i-1]*base+s[i];
    }
    ull index=0,ans=0;
    for(int i=1;i<=n;i++){
        if(check(i)==1){
            ull tmp=0;
            index=i;
            if(index<=mid){
                tmp=rt;
            } else {
                tmp=lt;
            }
            if(vis[tmp]>0) continue;
            vis[tmp]=1;
            ans++;
        }
    }
    if(ans>1){
        cout<<"NOT UNIQUE"<<endl;
    } else if(ans==0){
        cout<<"NOT POSSIBLE"<<endl;
    } else {
        if(index<=mid){
            cout<<s.substr(mid+1)<<endl;
        } else {
            cout<<s.substr(1,mid-1)<<endl;
        }
    }
    return 0;
}