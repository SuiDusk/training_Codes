#include <iostream>
#include <map>
using namespace std;
const int MAXN = 705;
int n;
int a[MAXN][2];
int cnt,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            double k=1.0*(a[j][0]-a[i][0])/(a[j][1]-a[i][1]);
            cnt=0;
            for(int p=j+1;p<=n;p++){
                if(1.0*(a[p][0]-a[i][0])/(a[p][1]-a[i][1])==k)
                    cnt++;
            }
            ans=max(ans,cnt);
        }
    }
    printf("%d\n",ans+2);
    return 0;
}