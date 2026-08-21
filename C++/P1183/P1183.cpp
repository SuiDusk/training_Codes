#include<cstdio>
#include<cmath>
using namespace std;
int n;
int x[105], y[105];
int ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
        scanf("%d %d",&x[i],&y[i]);
	x[n+1] = x[1], y[n+1] = y[1];
	for(int i=1;i<=n;++i)   
        ans += (x[i]*y[i+1]-x[i+1]*y[i]);
	printf("%d",abs(ans/2));
	return 0;
}
