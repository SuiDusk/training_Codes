#include<iostream>
#include<cstdio>

using namespace std;

const int MAXX = 205;

int n;
int ans;
int snow[MAXX];
int dp[MAXX][MAXX];

int main()
{
	scanf("%d",&n); 
    for(int i=1;i<=n;i++)
		scanf("%d",&snow[i]),snow[i+n]=snow[i];
    for(int i=2;i<2*n;i++)
        for(int j=i-1;i-j<n&&j>=1;j--)
		{
            for(int k=j;k<i;k++)
	            dp[j][i]=max(dp[j][i],dp[j][k]+dp[k+1][i]+snow[j]*snow[k+1]*snow[i+1]);
			ans=max(ans,dp[j][i]);
        }
    printf("%d\n",ans);
    return 0;
}