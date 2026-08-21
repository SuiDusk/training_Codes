#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
string s1,s2,s3;
long long ans=1;
int main(){
    cin>>s1>>s2;
    for(int i=0;i<s1.length()-1;i++){
        s3=s1.substr(i,2);
        reverse(s3.begin(),s3.end());
        if(s2.find(s3)!=string::npos) ans*=2;
    }
    cout<<ans<<endl;
    return 0;
}