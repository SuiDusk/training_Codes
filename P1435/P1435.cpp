#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
const int MAXN = 1005;
string s,rs;
int len;
int dp[MAXN][MAXN];
int main(){
    cin>>s;
    len=s.length();
    rs=s;
    for(int i=0;i<len;i++){
        rs[i]=s[len-i-1];
    }
    for(int i=1;i<=len;i++){
        for(int j=0;j<len;j++){
            if(s[i-1]==rs[j]){
                if(j==0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j-1]+1;
            } else {
                if(j==0) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    printf("%d\n",len-dp[len][len-1]);
}
/*
Ab3bd
*/