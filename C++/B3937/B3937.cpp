#include <iostream>
#include <cstdio>
using namespace std;
int n,q;
string s,op;
int sum1,sum2;
int main(){
    scanf("%d%d",&n,&q);
    cin>>s>>op;
    for(int i=0;i<q;i++){
        if(op[i]=='1') sum1++;
        else sum2++;
    }
    // cout<<sum1<<" "<<sum2<<endl;
    if(sum1%2){
        for(int i=0;i<n/2;i++)
            swap(s[i],s[n-i-1]);
    }
    if(sum2%2){
        for(int i=0;i<n;i++){
            if(s[i]=='1') s[i]='0';
            else s[i]='1';
        }
    }
    cout<<s<<endl;
    return 0;
}