#include <iostream>
using namespace std;
int k;
int a,b,c;
int main(){
    scanf("%d",&k);
    while(k--){
        scanf("%d %d %d",&a,&b,&c);
        printf("%d %d\n",(int)((10.0*(c-a)/b))+1,((int)(100.0*(c-a)/b))%10+1);
    }
    return 0;
}