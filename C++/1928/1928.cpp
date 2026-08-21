#include <iostream>
#include <cstdio>

using namespace std;

string s;
string ans;
int len,index=0;

void expand(int &i){
    int x=0;
    i++;
    while(isdigit(s[i])){
        x=x*10+s[i]-'0';
        i++;
    }
    int st=i;
    for(int k=0;k<x;k++){
        for(i=st;;i++)
            if(isalpha(s[i]))
                ans+=s[i];
            else if(s[i]=='[')
                expand(i);
            else break;
    }
    return ;
}

int main(){
    cin>>s;
    len=s.length();
    for(int i=0;i<len;i++){
        if(isalpha(s[i]))
            ans+=s[i];
        else if(s[i]=='[')
            expand(i);
    }
    cout<<ans<<endl;
    return 0;
}