#include <iostream>
using namespace std;
int x[5],y[5];
int a,b;
int main(){
    for(int i=0;i<3;i++){
        scanf(" (%d,%d)",&x[i],&y[i]);
    }
    scanf(" (%d,%d)",&a,&b);
    for(int i=0;i<3;i++){
        if((a==x[i]&&b==y[i])){
            printf("4\n");
            return 0;
        }
    }
    int in=0,ou=0;
    for(int i=0;i<3;i++){
        int t=(a-x[i])*(b-y[(i+1)%3])-(b-y[i])*(a-x[(i+1)%3]);
        if(t>0) in++;
        else if(t<0) ou++;
    }
    if(in==3||ou==3){
        printf("1\n");
        return 0;
    } else if(in>0&&ou>0){
        printf("2\n");
        return 0;
    } else {
        printf("3\n");
        return 0;
    }
    return 0;
}