#include <iostream>
#include <cstdio>
using namespace std;
int T;
int l,r;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&l,&r);
        int k=l^r,index=0;
        while(k>0){
            k=k>>1;
            index++;
        }
        index--;
        int x=((r>>(index+1))<<(index+1))+(1<<index)-1;
        int y=x+1;
        if(l!=x&&l!=y){
            printf("%d %d %d\n",x,y,l);
        } else {
            printf("%d %d %d\n",x,y,r);
        }
    }
    return 0;
}