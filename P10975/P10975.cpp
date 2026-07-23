#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int h,w;
long long dp[15][10005];//每一个二进制的1表示这是竖着矩形的上半部分
int check(int x){
    int lst=-1;
    for(;x;x-=(x&-x)){
        int i=log2(x&-x);
        if((i-lst)%2==0) return 0;
        lst=i;
    }
    return (w-lst)&1;
}
int main(){
    while(1){

        scanf("%d %d",&h,&w);
        if(h==w&&h==0) return 0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<(1<<w);i++){
            if(check(i))
                dp[1][i]=1;
        }
        for(int i=2;i<=h;i++){
            for(int s=0;s<(1<<w);s++){
                for(int t=0;t<(1<<w);t++){
                    if((s&t)||!check(s|t)) continue;
                    //(s&t)表示有连着的竖着矩形的上半部分,肯定不行
                    //check(s|t)==0的话代表两个竖着的矩形中间不能横着摆满
                    dp[i][t]+=dp[i-1][s];
                }
            }
        }
        printf("%lld\n",dp[h][0]);
    }
    return 0;
}//状压DP