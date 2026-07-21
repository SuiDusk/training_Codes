#include <iostream>
#include <cstdio>
using namespace std;
string s;
long long n;
int main(){
    cin>>s>>n;
    int num=s.length();
    while(num<n){
        long long i=num;
        while(i<n) i*=2;
        i/=2;
        n-=(i+1);
        if(n==0) n=i;
    }
    cout<<s[n-1]<<endl;
    return 0;
}