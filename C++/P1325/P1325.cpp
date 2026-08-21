#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
int n,d;
int cnt;
class Node{
public:
    int x,y;
    bool operator < (const Node tha)const{
        return 1.0*x-sqrt(d*d-y*y)<1.0*tha.x-sqrt(d*d-tha.y*tha.y);
    }
}a[MAXN];
int main(){
    double temp=-2e7;
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].x,&a[i].y);
        if(a[i].y>d){
            printf("-1\n");
            return 0;
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        double l=1.0*a[i].x-sqrt(d*d-a[i].y*a[i].y),r=(1.0*a[i].x+sqrt(d*d-a[i].y*a[i].y));
        if(l>temp){
            cnt++;
            temp=r;
        } else if(temp>=r){
            temp=r;
        }
    }
    printf("%d\n",cnt);
    return 0;
}