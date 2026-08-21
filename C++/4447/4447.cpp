#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 1e5+5;

int n;
int a[MAXN];

class numb{
public:
    int num;
    int amount;
    numb(){
        num=0,amount=0;
    }
};

numb b[MAXN];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int index=1;
    b[index].num=a[1];b[index].amount=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            b[index].amount++;
        } else {
            index++;
            b[index].num=a[i];
            b[index].amount=1;
        }
    }
    int ans=1e9,cnt=0;
    int tap=0;
    for(int i=1;i<=index;i++){
        if(b[i].num==b[i-1].num+1&&b[i].amount-1>=b[i-1].amount){
                cnt++;
                b[i].amount--;
                if(tap==0&&b[i].amount>b[i-1].amount){
                    tap=i;
                }
        } else {
            if(tap!=0)
                i=tap;
            if(cnt!=0)
                ans=min(ans,cnt);
            cnt=0;
            tap=0;
            cnt++;
            b[i].amount--;
            if(b[i].amount>b[i-1].amount){
                tap=i;
            }
        }
    }
    ans=min(ans,cnt);
    printf("%d\n",ans);
    return 0;
}