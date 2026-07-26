#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,a;
int cnt=0;
int main(){
    scanf("%d %d",&n,&a);
    for(int i=1;i<=n;i++){
        double x,y;
        scanf("%lf %lf",&x,&y);
        if(sqrt(x*x+y*y)<=a)
            cnt++;
    }
    printf("%.6lf",1.0*cnt/n*4);
    return 0;
}