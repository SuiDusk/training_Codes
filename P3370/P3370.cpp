#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef unsigned long long ull;
int n;
string s;
int ans;
map<ull,int> mp;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        ull res=0;
        int len=s.length();
        for(int j=0;j<len;j++){
            res=res*233+s[j];
        }
        if(!mp[res]) ++ans,mp[res]=1;
    }
    printf("%d\n",ans);
    return 0;
}