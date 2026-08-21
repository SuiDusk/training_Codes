#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100005;
struct rec{
    int id,num;
    rec(int i,int n):id(i),num(n){}
    rec(){id=0,num=0;} 
}s1[N],s2[N];
int n,sum,cnt1,cnt2,a[N];
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1) s1[++cnt1]=rec(i,1);
        else s2[++cnt2]=rec(i,a[i]);
        sum += a[i];
    }
    if(sum==n*2-2){
        while(cnt1+cnt2>2){
            printf("%d %d\n",s1[cnt1].id,s2[cnt2].id);
            cnt1--;
            s2[cnt2].num--;
            if(s2[cnt2].num==1) s1[++cnt1]=s2[cnt2--];
        }
        printf("%d %d\n",s1[1].id,s1[2].id);
    } else {
        printf("-1");
    }
    return 0;
}
