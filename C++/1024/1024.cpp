#include <iostream>
#include <cstdio>

using namespace std;

double a,b,c,d;

double calculate(double x){
    return a*x*x*x+b*x*x+c*x+d;
}

int main(){
    cin>>a>>b>>c>>d;
    double left=0,right=0;
    for(int i=-100;i<=100;i++)
    {
        left=calculate(i);
        right=calculate(i+1);
        if(left*right<0||left==0)
        {
            double l=i,r=i+1;
            for(int j=1;j<=10;j++){
                double mid=(l+r)/2;
                if(calculate(mid)*left<=0) r=mid;
                else l=mid;
            }
            printf("%.2lf ",(l+r)/2);
        }
    }
    return 0;
}