#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<int> st;
stack<char> op;
int main(){
    while(1){
        char c=getchar();
        if(isdigit(c)){
            int x=c-'0';
            c=getchar();
            while(c!='.'){
                x=x*10+c-'0';
                c=getchar();
            }
            st.push(x);
        } else if(c=='+'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(x+y);
        } else if(c=='-'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y-x);
        } else if(c=='*'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(x*y);
        } else if(c=='/'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y/x);
        }
        else if(c=='@') break;
    }
    printf("%d\n",st.top());
    return 0;
}