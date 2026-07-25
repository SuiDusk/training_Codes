#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define pb push_back
#define ll unsigned long long
#define getchar() (tt==ss&&(tt=(ss=In)+fread(In,1,1<<20,stdin),ss==tt)?EOF:*ss++)
using namespace std;
char In[1<<20],*ss=In,*tt=In;
const int N=5e6+10;
struct Node1{
	ll x;
	ll y;
	int id;
	friend bool operator <(const Node1 a,const Node1 b){
		if(a.x!=b.x) return a.x<b.x;
		return a.id<b.id;
	}
}a[N];
struct Node2{
	ll ans;
	int id;
	friend bool operator <(const Node2 a,const Node2 b){
		return a.id<b.id;
	}
}b[N];
int n;
ll res;
ll read(void){
    ll f=1,res=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        res=res*10+(ch-'0');
        ch=getchar();
    }
    return res*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].x=read();
		a[i].y=read();
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;){
		int l=i,r=i;
		while(i<=n&&a[r].x==a[l].x) r=++i;
		r--;
		for(int j=l;j<=r;j++) 
            b[j]={(j-1<l?0ll:a[j-1].y),a[j].id};
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		res+=i*b[i].ans;
	}
	printf("%llu\n",res);
	return 0;
}

/*
x1,y1, a1,a2;
x2,y2  b1,b2;
*/
