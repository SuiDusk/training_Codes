#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 105;
int n;
int a[MAXN];
int ans;
int check(int x){
    int l=0,r=0;
    while(x){
        if(x%2==1)
            r++;
        else 
            l++;
        x=x>>1;
    }
    if(l==r) return 1;
    else return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        if(check(a[i]))
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}