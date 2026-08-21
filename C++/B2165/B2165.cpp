#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int n;
string s;
int isright(char c){
    if(c==']'||c==')'||c=='}') return 1;
    return 0;
}
int solve(){
    int len=s.length();
    stack<char> st;
    for(int i=0;i<len;i++){
        if(st.empty()&&isright(s[i])) return 0;
        if(!isright(s[i])) st.push(s[i]);
        if(isright(s[i])) {
            if((s[i]=='}'&&st.top()=='{')||(s[i]==']'&&st.top()=='[')||(s[i]==')'&&st.top()=='('))
                st.pop();
            else return 0;
        }
    }
    if(!st.empty()) return 0;
    else return 1;
}
int main(){
    scanf("%d",&n);
    while(n--){
        cin>>s;
        if(solve())
            printf("YES\n");
        else   
            printf("NO\n");
    }
    return 0;
}