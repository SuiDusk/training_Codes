#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 1e6+5;
const int base = 233;
string s;
int Q;
ull hash_[MAXN];
ull pw[MAXN];
int main(){
    cin>>s;
    scanf("%d",&Q);
    int len=s.length();
    ull sum=1;
    for(int i=0;i<len;i++){
        hash_[i+1]=hash_[i]*base+s[i]-'a';
    }
    pw[0]=1;
    for(int i=1;i<1e6;i++){
        pw[i]=pw[i-1]*base;
    }
    while(Q--){
        int l1,l2,r1,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(r2-l2!=r1-l1){
            printf("No\n");
            continue;
        } else {
            ull a=hash_[r1]-hash_[l1-1]*pw[r1-l1+1];
            ull b=hash_[r2]-hash_[l2-1]*pw[r2-l2+1];
            if(a==b) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}