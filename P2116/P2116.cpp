#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const double eps = 1e-8;
int n,l;
class Node{
public:
    int x,y;
    Node(){x=0,y=0;}
    Node(int _x,int _y){x=_x,y=_y;}
    bool operator < (const Node &t)const{
        if(x<t.x) return 1;
        else if(x==t.x&&y<t.y) return 1;
        else return 0;
    }
    bool operator == (const Node &t)const{
        if(x==t.x&&y==t.y) return 1;
        return 0;
    }
};
Node a[MAXN];
Node s[MAXN];
int dcmp(double x){
    if (fabs(x)<eps) return 0; 
    else return x<0?-1:1;
}
Node sub(Node x,Node y){
    return Node(x.x-y.x,x.y-y.y);
}
double cross(Node A,Node B){
    return A.x*B.y-A.y*B.x;
}
int main(){
    scanf("%d %d",&n,&l);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    sort(a+1,a+1+n);
    int cnt=1;
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        while((cnt>1&&dcmp(cross(sub(s[cnt],s[cnt-1]),sub(a[i],s[cnt]))>0))||a[i]==s[cnt])
            cnt--;
        s[++cnt]=a[i];
    }
    for(int i=n-1;i>=1;i--){
        while((cnt>1&&dcmp(cross(sub(s[cnt],s[cnt-1]),sub(a[i],s[cnt]))>0))||a[i]==s[cnt])
            cnt--;
        s[++cnt]=a[i];
    }
    cnt--;
    double ans=0;
    for(int i=1;i<=cnt;i++){
        ans+=sqrt(pow(s[i].x-s[i+1].x,2)+pow(s[i].y-s[i+1].y,2));
    }
    printf("%.0lf",ans+2*3.1415926535897932384*l);//a如果用3.14会精度不够导致WA
    return 0;
}