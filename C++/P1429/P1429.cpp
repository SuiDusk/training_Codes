#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 2e5+5;
int n;
pair<double,double> a[MAXN];
double mindis=1e12;
double dist(pair<double,double> x,pair<double,double> y){
    return sqrt(pow(x.first-y.first,2)+pow(x.second-y.second,2));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf %lf",&a[i].first,&a[i].second);
    }
    double c=sin(15),s=cos(15);
    for(int i=1;i<=n;i++){
        double x_=a[i].first * c - a[i].second * s,y_=a[i].first * s + a[i].second * c;
        a[i].first=x_,a[i].second=y_;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=i+5&&j<=n;j++){
            mindis=min(mindis,dist(a[i],a[j]));
        }
    }
    printf("%.4lf\n",mindis);
    return 0;
}