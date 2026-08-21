#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 1e7+5;
int n;
int t;
long long x,y;
int a[100005];
long long ans;
queue<int> q1;
queue<long long> q2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        a[t]++;
    }
    for(int i=1;i<=1e5;i++){
        while(a[i]){
            q1.push(i);
            a[i]--;
        }
    }
    while(1){
        if(q1.empty()&&q2.size()==1) break;
        if(q2.empty()||(!q1.empty()&&q1.front()<q2.front())){
            x=q1.front();
            q1.pop();
        } else {
            x=q2.front();
            q2.pop();
        }
        if(q2.empty()||(!q1.empty()&&q1.front()<q2.front())){
            y=q1.front();
            q1.pop();
        } else {
            y=q2.front();
            q2.pop();
        }
        ans+=(x+y);
        q2.push(x+y);
    }
    printf("%lld\n",ans);
    return 0;
}