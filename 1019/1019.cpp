#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n;
int ans=0;
int vis[30];//每个最多访问两次
string s[50];
vector<pair<int,int> > g[50];
void Init();
int check(string x,string y);
void dfs(int index,int len);
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        cin>>s[i];
    Init();
    char c;
    cin>>c;
    for(int i=1;i<=n;i++){
        if(c==s[i][0]){
            vis[i]++;
            dfs(i,s[i].length());
            vis[i]--;
        }
    }
    printf("%d\n",ans);
    return 0;
}

void Init(){//建图
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int l=check(s[i],s[j]);
            if(l!=-1){
                g[i].push_back(pair<int,int>(j,l));//路径权值为出去接龙的长度
            }
        }
    }
}

int check(string x,string y){
    int len1=x.length(),len2=y.length();
    for(int i=len1-1;len1-i<=len2;i--){
        if(y[0]==x[i]){
            int index=1,l=0,r=i;
            while(r<len1){
                if(x[r]!=y[l]){
                    index=0;
                    break;
                }
                r++;
                l++;
            }
            if(index==1){
                return len2-(len1-i);
            }
        }
    }
    return -1;
}

void dfs(int index,int len){
    for(int i=0;i<g[index].size();i++){
        int u=g[index][i].first;
        if(vis[u]<2){
            vis[u]++;
            dfs(u,len+g[index][i].second);
            vis[u]--;
        }
    }
    ans=max(ans,len);
    return ;
}