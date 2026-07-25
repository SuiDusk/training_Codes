#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 3e6+5;
int n;
int a[MAXN];
int ans[MAXN];
stack<int> st;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        while(!st.empty()&&a[i]>a[st.top()])
            ans[st.top()]=i,st.pop();
        st.push(i);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}