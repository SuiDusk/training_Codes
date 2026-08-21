#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 105;
int n;
double a[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i]-(int)a[i]>=0.5)
                printf("%d ",(int)a[i]+1);
            else 
                printf("%d ",(int)a[i]);
    }
    putchar('\n');
    for(int i=1;i<=n;i++){
        if(a[i]-(int)a[i]==0.5){
            if((int)(a[i]+0.5)%2==0){
                printf("%.0lf ",a[i]+0.5);
            } else {
                printf("%.0lf ",a[i]-0.5);
            }
        } else {
            if(a[i]-(int)a[i]>0.5)
                printf("%d ",(int)a[i]+1);
            else 
                printf("%d ",(int)a[i]);
        }
    }
    return 0;
}