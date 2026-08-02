#include <iostream>
#include <cstdio>
using namespace std;
int T;
string s;
string st;
int main(){
    scanf("%d",&T);
    for(int i=1;i<=100;i++){
        st+="Yes";
    }
    while(T--){
        cin>>s;
        if(st.find(s)!=string::npos){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}