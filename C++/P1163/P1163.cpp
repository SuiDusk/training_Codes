#include <iostream>
#include <cstdio>
using namespace std;
const double eps = 1e-5;
double w,v,m;
int main(){
    scanf("%lf %lf %lf",&w,&v,&m);
    double l=0,r=5;
    while(l<=r){
        double mid=(l+r)/2;
        if(r-l<0.0001){
            break;
        }
        double t=w;
        for(int i=1;i<=m;i++){
            t=t*(1+mid)-v;
        }
        if(t>0) r=mid;
        else if(t<0) l=mid;
        else if(t==0) break;
    }
    printf("%.1lf",(l+r)/2*100);
    return 0;
}