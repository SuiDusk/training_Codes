#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 2147483647;
int n,m,q,u,v,t;
int x;
int a[100005];
class Node{
public:
    long long v;
    int _time;
    Node(long long V,int _t){
        v=V,_time=_t;
    }
    bool operator < (const Node x)const{
        return (v+(t-_time)*q)<(x.v+(t-x._time)*q);
    }
};
queue<int>q1,q2,q3;
int main(){
    scanf("%d %d %d %d %d %d",&n,&m,&q,&u,&v,&t);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=n;i++)
        q1.push(a[i]);
    for(int i=1;i<=m;i++){
        pair<int,int> pii=max({make_pair(q1.empty()?-INF:q1.front(),1),
                            make_pair(q2.empty()?-INF:q2.front(),2),
                            make_pair(q3.empty()?-INF:q3.front(),3)});

        int r=pii.first+q*(i-1),s=pii.second;
        if(s==1) q1.pop();
        else if(s==2) q2.pop();
        else if(s==3) q3.pop();

        int nowl=1ll*r*u/v,lef=r-nowl;
        q2.push(nowl-i*q);
        q3.push(lef-i*q);
        if(i%t==0) printf("%d ",r);
    }
    printf("\n");
    for(int i=1;i<=m+n;i++){
        pair<int,int> pii=max({make_pair(q1.empty()?-INF:q1.front(),1),
                            make_pair(q2.empty()?-INF:q2.front(),2),
                            make_pair(q3.empty()?-INF:q3.front(),3)});
        int r=pii.first,s=pii.second;
        if(s==1) q1.pop();
        else if(s==2) q2.pop();
        else if(s==3) q3.pop();
        
        if(i%t==0) printf("%d ",r+q*m);
    }
    printf("\n");
    return 0;
}

/*

struct Node{

}

class Node{
public:
    int val;
    Node *x;
}*p1;
int t=p1->val;

int a;
int *p=&a;
delet(p);

*/