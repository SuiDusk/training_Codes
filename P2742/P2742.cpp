#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;
const double eps = 1e-8;
int n;
class Node{
public:
    double x,y;
    Node(){
        x=0,y=0;
    }
    Node(double _x,double _y){
        x=_x;y=_y;
    }
    bool operator < (Node t)const{
        if(x>t.x) return 0;
        else if(x<t.x) return 1;
        else return y<t.y;
    }
    bool operator == (Node t)const{
        if(x==t.x&&y==t.y) return 1;
        return 0;
    }
};
Node a[MAXN];
Node s[MAXN];
int cnt=0;
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf %lf",&a[i].x,&a[i].y);
    }
    sort(a+1,a+1+n);
    s[1]=a[1];
    cnt=1;
    for(int i=2;i<=n;i++){
        while((cnt>1&&dcmp(cross(sub(s[cnt],s[cnt-1]),sub(a[i],s[cnt])))>0)||a[i]==s[cnt])
          cnt--;
        s[++cnt]=a[i];
    }
    for(int i=n-1;i>=1;i--){
        while((cnt>1&&dcmp(cross(sub(s[cnt],s[cnt-1]),sub(a[i],s[cnt])))>0)||a[i]==s[cnt])
          cnt--;
        s[++cnt]=a[i];
    }
    cnt--;
    double ans=0;
    // for(int i=1;i<=cnt;i++){
    //     printf("%lf %lf\n",s[i].x,s[i].y);
    // }
    for(int i=1;i<=cnt;i++){
        ans+=sqrt(pow(s[i].x-s[i+1].x,2)+pow(s[i].y-s[i+1].y,2));
        // printf("%.2lf\n",ans);
    }
    printf("%.2lf\n",ans);
    return 0;
}
/*
10
0 -4
0 -1
2 2
0 -1
2 -1
1 -1
-1 2
4 -3
1 3
4 -1
-1.000000 2.000000
0.000000 -1.000000
0.000000 -1.000000
1.000000 3.000000
2.000000 2.000000
4.000000 -1.000000
4.000000 -3.000000
0.000000 -1.000000
0.000000 -1.000000
0.000000 -4.000000
3.16
3.16
7.29
8.70
12.31
14.31
18.78
18.78
21.78
27.86
27.86

9
0 -4
2 2
0 -1
2 -1
1 -1
-1 2
4 -3
1 3
4 -1
*/