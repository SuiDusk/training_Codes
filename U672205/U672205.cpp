#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 5e5+5;
const int base = 233;
int ans;
string a,b;
ull hash1[MAXN];
ull hash2[MAXN];
ull pw[MAXN];
int main(){
    cin>>a>>b;
    int len1=a.length(),len2=b.length();
    pw[0]=1;
    for(int i=0;i<len1;i++){
        hash1[i+1]=hash1[i]*base+a[i];
        pw[i+1]=pw[i]*base;
    }
    for(int i=0;i<len2;i++){
        hash2[i+1]=hash2[i]*base+b[i];
    }
    for(int i=len1;i<=len2;i++){
        ull t=hash2[i]-hash2[i-len1]*pw[len1];
        // ull a=hash_[r1]-hash_[l1-1]*pw[r1-l1+1];
        // ull b=hash_[r2]-hash_[l2-1]*pw[r2-l2+1];
        if(hash1[len1]==t)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}