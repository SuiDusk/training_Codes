#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 10005;
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    vector<vector<int>> S(m),T(m);
    for(int i=0;i<m;i++){
        int k;
        scanf("%d",&k);
        S[i].resize(k);
        for(int j=0;j<k;j++){
            scanf("%d",&S[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        int k;
        scanf("%d",&k);
        T[i].resize(k);
        for(int j=0;j<k;j++){
            scanf("%d",&T[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        long long xorS=0,xorT=0;
        for(int x:S[i]) xorS^=a[x];
        for(int x:T[i]) xorT^=a[x];
        bool equal=(S[i].size()==T[i].size());
        if(equal){
            for(int j=0;j<S[i].size();j++){
                if(S[i][j]!=T[i][j]){
                    equal=false;
                    break;
                }
            }
        }
        bool xorEqual=(xorS==xorT);
        if(equal==xorEqual){
            printf("correct\n");
        } else {
            printf("wrong\n");
        }
    }
    return 0;
}