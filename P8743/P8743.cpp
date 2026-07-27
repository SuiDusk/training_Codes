#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 2e5+5;
int T;
int n;
int cnt[50],h;
void get_bit(int x){
    int i=0;
    while(x>0){
        if(x&1) cnt[i]++;
        i++;x=x>>1;
    }
    h=max(h,i);
    return ;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));h=0;
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            get_bit(x);
        }
        int index=-1;
        for(int i=0;i<=h;i++){
            if(cnt[i]%2==1)
                index=i;
        }
        if(index==-1){
            printf("0\n");
            continue;
        }
        if(cnt[index]==1){
            printf("1\n");
            continue;
        }
        if(cnt[index]>1&&(n-cnt[index])%2==0){
            printf("1\n");
            continue;
        } else {
            printf("-1\n");
            continue;
        }
    }
    return 0;
}