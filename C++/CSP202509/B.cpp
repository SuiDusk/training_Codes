#include <iostream>
#include <cstdio>
using namespace std;
int flag[][10]={
    {1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,1,0,1},
    {1,0,0,1,1,1,1,1,0},
    {1,0,0,0,0,1,1,0,0},
    {1,1,1,1,1,1,1,0,0}
};
int n,L;
int diff[70000];
int a[205][205];
int main(){
    scanf("%d %d",&n,&L);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=1;i<=n-4;i++){
        for(int j=1;j<=n-8;j++){
            int min1=L,max0=0;
            for(int x=0;x<5;x++){
                for(int y=0;y<9;y++){
                    int val=a[i+x][j+y];
                    if(flag[x][y]){
                        if(val<min1) min1=val;
                    } else {
                        if(val>max0) max0=val;
                    }
                }
            }
            max0++;
            if(max0<=min1){
                diff[max0]+=1;
                diff[min1+1]-=1;
            }
        }
    }
    int cur=0;
    for(int i=1;i<=L;i++){
        cur+=diff[i];
        if(cur>0) printf("%d\n",i);
    }
    return 0;
}